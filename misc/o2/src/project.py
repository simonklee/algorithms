#!../ve/bin/python
import re
import pdb
from datastructures import KeyedComparisonMixin, KeyedHashingMixin, PriorityQueue

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
    
    def dijkstra(self, start='START'):
        '''
        Will find the shortest path for each task limited by the tasks
        prerequisites, that is, every task before it in the one-directional
        tree. As a result the tasks in the ``tasks`` dict will have
        their earliest_start updated. This is a sort of reversed dijkstra
        shortest path algorithm. It looks for the longest path.
        
        '''        
        def add_to_pq(successor, tasks=[]):
            for t in tasks:
                if t in tree:
                    continue
                old_task = pq.get(t)
                new_cost = t.duration + successor.earliest_start
                if old_task == None:
                    t.earliest_start = new_cost
                    pq.push(t)
                    print "added earliest_start(%s) to \"%s\"" % (t.earliest_start, t.name)
                #elif old_task.earliest_start > new_cost:
                #    print "changed earliest_start(%s -> %s) to \"%s\"" % (
                #        t.earliest_start, new_cost, t.name)
                #    t.earliest_start = new_cost
        
        def add_to_tree(task):
            add_to_pq(task, task.successors.itervalues())
            tree.update({task.name: task})
        
        tree = dict()           # store result
        pq = PriorityQueue([])  # lookup table of what is next.
        
        # init by setting the ``start`` as the first task in the tree.
        start_task = self.tasks[start] 
        start_task.earliest_start = start_task.duration
        add_to_tree(start_task)
        
        while(pq.size > 0):
            add_to_tree(pq.pop_big())
        return tree

    @property
    def size(self):
        return len(self.tasks)
    
    def _debug(self):
        for t in self.tasks.values():
            print "%s %s >" % (t.name, t.duration),
            for p in t.predecessors:
                print "%s" % p.name,
            print ""


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

if __name__ == '__main__':
    tree = Project('testproject.txt').dijkstra()
    for t in tree.values():
        print t.name, t.earliest_start
            

    