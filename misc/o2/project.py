
import os
import sys


class Project(object):
    
    def __init__(self, filename):
        self.tasks = dict()
        self._load(filename)

    def _load(self, filename):
        '''
        Load tasks from filename and store them in the 
        Tasks dictionary.
        
        '''
        with open(filename, mode='r') as fp:
            for line in fp:
                name, duration = line.split(None, 2)

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
    
