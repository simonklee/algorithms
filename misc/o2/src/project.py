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
        
        '''
        fp = open(filename, mode='r')
        lines = (line.strip().split(' ') for line in fp.readlines()
            if re.search(r'^\w', line))
        fp.close()
        
        for line in lines:
            print "Task: %s duration: %s preds: " % (line[0], line[1]),
            for i, l in enumerate(line[3:]):
                print "%s" % l,
            print ""
        

    def _task(self, name):
        '''
        Create a task for given name if it doesn't exists.
        Returns the task for the given name.

        '''
        if name not in self.tasks:
            tasks[name] = Task(name)
        return tasks[name]
        

class Task(object):
    
    def __init__(self, name):
        self.name = name
        self.predecessors = []

    def set_duration(self, duration):
        self.duration = duration

if __name__ == '__main__':
    project = Project('testproject.txt')
    
