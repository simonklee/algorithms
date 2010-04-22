#!../ve/bin/python
import os
import sys
import re


class Project(object):

    def __init__(self, filename):
        self.tasks = dict()
        self._load(filename)

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

                print "Task: %s duration: %s preds: " % (name, duration),
                for l in predecessors:
                    print "%s" % l.name,
                print ""
        except IndexError:
            print 'Failed to desipher the tasks-file. Please check your syntax'
            exit()


class Task(object):

    def __init__(self, name, duration=None, predecessors=[], **kwargs):
        self.name = name
        self.predecessors = []
        self.duration = duration
        self.earliest_start = kwargs.pop('earliest_start', None)
        self.latest_start = kwargs.pop('latest_start', None)

if __name__ == '__main__':
    project = Project('testproject.txt')
