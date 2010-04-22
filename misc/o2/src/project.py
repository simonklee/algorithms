#!../ve/bin/python
import re


class Project(object):
    '''
    A project is nothing more then a list of tasks.
    
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
    
    def _debug(self):
        for t in self.tasks.values():
            print "%s %s >" % (t.name, t.duration),
            for p in t.predecessors:
                print "%s" % p.name,
            print ""


class Task(object):
    '''
    Representation of a task/activity in a project.
    
    '''
    def __init__(self, name, duration=None, predecessors=[], **kwargs):
        self.name = name
        self.predecessors = predecessors
        self.duration = duration
        self.earliest_start = kwargs.pop('earliest_start', None)
        self.latest_start = kwargs.pop('latest_start', None)

if __name__ == '__main__':
    project = Project('testproject.txt')
