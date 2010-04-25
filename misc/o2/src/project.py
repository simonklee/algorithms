#!../ve/bin/python
import re
from datastructures import KeyedComparisonMixin, KeyedHashingMixin

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
        self._debug()

    def _load(self, filename):
        '''
        Load tasks from filename and store them in the
        Tasks dictionary.

        The tasks are read from file specified. Only lines who start with a
        word will be recognized. the tasks are split by whitespace in the file,
        and a set of predecessors(dependencies) are listed after a colon, those
        are also split by whitespace.

        '''
        with open(filename, mode='r') as fp:
            lines = (line.strip().split(' ') for line in fp.readlines()
                if re.search(r'^\w', line))

        try:
            for line in lines:
                name, duration = line[0], line[1]
                predecessors = [self.tasks[p] for p in line[3:]]
                self.tasks[name] = Task(name, duration, predecessors)
        except IndexError:
            print 'Failed to desipher the tasks-file. Please check your syntax'
    
    def dijkstra(self, start='END'):
        
        def add_to_pq(successor, tasks={}):
            for t in tasks:
                # Check if the tasks cost is lower then the one in PQ before this.
                t.cost = t.duration + successor.earliest_start
                pq.push(t)
        
        def add_to_tree(task):
            add_to_pq(task.sucessors, task)
            tree.append(task)
        
        # init
        tree = []
        pq = PriorityQueue([])
        add_to_tree(tasks[start])
        
        while(pq.size > 0):
            #add_to_tree(pq.pop())
            break
    
    @property
    def size(self):
        return len(self.tasks)
    
    def _debug(self):
        for t in self.tasks.values():
            print "%s %s >" % (t.name, t.duration),
            for p in t.predecessors:
                print "%s" % p.name,
            print ""


class Task(KeyedComparisonMixin, KeyedHashingMixin):
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

