#!../ve/bin/python
import re
import pdb
from datastructures import KeyedComparisonMixin, PriorityQueue, Stack

class Project(object):
    '''
    A project is nothing more then a list of tasks.
    
    duration == longest path to END task
    earliest_start == longest path to each vertex
    ( nEND's latest_start == END's earliest start)
    latest_start == latest_start of successor - tasks duration. 
    
    '''

    def __init__(self, filename):
        self.tasks = dict()
        self._load(filename)
        #self._debug()

    def _load(self, filename):
        '''
        Load tasks from filename and store them in the
        Tasks dictionary.

        The tasks are read from file specified. Only lines who start with a
        word will be recognized. the tasks are split by whitespace in the file,
        and a set of predecessors(dependencies) are listed after a colon, those
        are also split by whitespace.
        
        We also add successors to all task to simple the shortest path
        algorithm. This adds some overhead, O(N^2), to the initialization
        of the project.

        '''
        with open(filename, mode='r') as fp:
            lines = (line.strip().split(' ') for line in fp.readlines()
                if re.search(r'^\w', line))

        try:
            for line in lines:
                name, duration = line[0], int(line[1])
                predecessors = [self.tasks[p] for p in line[3:]]
                self.tasks[name] = Task(name, int(duration), predecessors)
        except IndexError:
            print 'Failed to desipher the tasks-file. Please check your syntax'
        
        for task in self.tasks.itervalues():
            for p in task.predecessors:
                p.successors.update({task.name: task})
    
    def earliest(self, start='START', debug=False):
        '''
        Will find the shortest path for each task limited by the tasks
        prerequisites, that is, every task before it in the one-directional
        tree. As a result the tasks in the ``tasks`` dict will have
        their earliest_start updated. 
        
        | N (latest start) |  State of Queue            |
        -------------------------------------------------
        | START(0) in tree |  queue: A(0) B(0) 	        | 0
        | A(0) in tree     |  queue: B(0) E(3) D(3) 	| 1 
        | B(0) in tree     |  queue: E(3) D(3) C(4) 	| 2
        | E(3) in tree     |  queue: D(3) C(4) END(5) 	| 3
        | D(3) in tree     |  queue: C(4) END(5) F(4) 	| 4
        | C(4) in tree     |  queue: F(4) END(5) 	| 5
        | F(4) in tree     |  queue: END(5) 	        | 6
        | END(7) in tree   |  queue:                    | 7
        -------------------------------------------------
        
        '''
        def add_to_tree(task):
            for t in task.successors.values():
                new = task.duration + task.earliest_start
                old = t.earliest_start
                t.earliest_start = new if old < new else old # None < 2 == True
                if t not in tree:
                    pq.push(t)

            tree.update({task.name: task})
        
        tree = dict()
        pq = PriorityQueue(lambda x: x.earliest_start, [])
        
        # init by setting the ``start`` as the first task in the tree.
        start_task = self.tasks[start] 
        start_task.earliest_start = start_task.duration
        add_to_tree(start_task)
        
        if debug:
            print "\n| %s in tree | " % start_task.name,
            self._p_queue(pq.heap)
            print ""
        
        while(pq.size > 0):
            c = pq.pop()
            add_to_tree(c)
            if debug:
                print "| %s(%s) in tree | " % (c.name, c.earliest_start),
                self._p_queue(pq.heap)
                print ""
        return tree
    
    def latest(self, start='END', debug=False):
        '''
        Find the latest start time for each task by traversing the tree,
        backwards and calculating the latest_start by subtracting the
        minimum of the latest start of the successors, minus the tasks
        duration.
        
        '''
        def add_to_tree(task):
            for t in filter(lambda x: x not in tree, task.predecessors):
                cost = (task.latest_start - t.duration) 
                t.latest_start = cost if cost > 0 else 0
                pq.push(t)
            tree.update({task.name: task})

        tree = dict() 
        pq = PriorityQueue(lambda x: x.latest_start, []) 
        
        start_task = self.tasks[start] 
        start_task.latest_start = start_task.earliest_start
        add_to_tree(start_task)
        
        if debug:
            print "\n| %s in tree | " % start_task.name,
            self._p_queue(pq.heap)
            print ""
        
        while(pq.size > 0):
            c = pq.pop()
            add_to_tree(c)
            if debug:
                print "| %s(%s) in tree | " % (c.name, c.latest_start),
                self._p_queue(pq.heap)
                print ""
            
        return tree        
    
    def critical(self, start='START'):
        '''
        1. for each node follow the predecessors if the node has no slack.
        2. traverse predecessor and repeat step 1.
        
        The function will return one critical path. If there are more critical
        paths it will only return one arbitrary of them.
        
        '''
        top = self.topological()
        path = Stack([self.tasks[start]])
        bad = set()
        
        def _visits(task):
            if len(task.successors.values()) == 0:
                return True
            for t in task.successors.values():
                if t.earliest_start == t.latest_start and t not in bad:
                    path.push(t)
                    return _visits(t)
            return False
        
        for t in top:
            if _visits(t):
                break
            pop = path.pop()
            bad.add(t)
        return path
    
    def topological(self, start='START'):
        '''
        return a list topological sorted nodes using a depth-first search. 
        
        '''
        def _visit(task):
            if task.name not in visited:
                visited.add(task.name)
                for t in task.predecessors:
                    _visit(t)
                topo.append(task)
                
        topo = []
        visited = set()
        
        for task in self.tasks.itervalues():
            _visit(task)
        
        return topo
        
    @property
    def size(self):
        return len(self.tasks)
    
    def _debug(self):
        for t in self.tasks.values():
            print "%s %s >" % (t.name, t.duration),
            for p in t.predecessors:
                print "%s" % p.name,
            print ""
    
    def _p_queue(self, queue):
        print "queue:",
        for k, v in queue:
            print "%s(%s)" % (v.name, k),
        print "\t",

class Task(KeyedComparisonMixin):
    '''
    Representation of a task/activity in a project.
    The inherited classes are implementing rich comparison and hash
    on the returned __key__. This enables the Task to be compareable and
    is used in a priority queue to define the earliest_start of each
    Task.
    
    '''
    def __init__(self, name, duration=None, predecessors=[], **kwargs):
        self.name = name
        self.predecessors = predecessors
        self.successors = dict()
        self.duration = duration
        self.earliest_start = kwargs.pop('earliest_start', None)
        self.latest_start = kwargs.pop('latest_start', None)
    
    def __key__(self):
        return self.earliest_start

    def __hash__(self):
        return hash(self.name)

    def __eq__(self, other):
        return self.name == other

    def __str__(self):
        return "%s@duration: %s, SP: %s, successors. %s" % \
            (self.name, self.duration, self.earliest_start,
            [s.name for s in self.successors.itervalues()])
