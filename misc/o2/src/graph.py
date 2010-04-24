#!../ve/bin/python
from collections import deque
from numpy import zeros


class Stack(list):
    '''
    A very thin wrapper around python's built-in list. Implements a simple
    stack-like interface. It uses last-in first-out where push appends to
    the list, and pop returns the last element.

    '''
    def __init__(self, *args, **kwargs):
        super(Stack, self).__init__(*args, **kwargs)

    def peek(self):
        return self[-1]

    def push(self, item):
        self.append(item)


class Graph(object):

    def __init__(self, MAX_NUM=20):
        '''
        Init will create a empty multi-dimensional array of size MAX_NUM
        initialized with 0's. We use the conventional NumPy module to perform
        this step in a one-liner.

        '''
        self.MAX_NUM = MAX_NUM
        self.vertex = list()
        self.adjacency_matrix = zeros((MAX_NUM, MAX_NUM), dtype='uint8')

    def depth_search(self, start=0):
        '''
        Rules for the depth-first search:

            * R1: If possible, visit an adjacent unvisted vertex, mark it, and
              push it to the stack

            * R2: If you can't follow R1, then, if possible, pop a vertex of
              the stack.

            * R3: if you can't follow R1 or R2, you're done.

        Returns the result in a stack. Makes it easier to test.
        '''
        stack = Stack([start])
        self.vertex[start].visited = True
        res_stack = Stack([self.vertex[start].name])

        while len(stack) > 0:
            v = self._first_unvisited(stack.peek())
            if v >= 0:
                res_stack.push(self.vertex[v].name)
                stack.push(v)
                self.vertex[v].visited = True
            else:
                stack.pop()
        self._reset()
        return res_stack

    def breadth_search(self, start=0):
        '''
        Rules for the breadth-first search:

            * R1: Visit the next unvisited vertex (if there is one) thats
              adjacent to the current vertex, mark it, and insert it into the
              queue.

            * R2: if you can't carry out R1 because there are no more unvisited
              vertices, remove a vertex from the queue (if possible) and make
              it the current vertex.

            * R3: if you can't carry out R2 because the queue is empty, you're
              done.

        '''
        queue = deque([start]) # dequeue has fast push and pop on both ends.
        self.vertex[start].visited = True
        res_stack = Stack([self.vertex[start].name])

        while len(queue) > 0:
            current = queue.popleft()
            for adj in self._find_adjacency(current):
                self.vertex[adj].visited = True
                queue.append(adj)
                res_stack.push(self.vertex[adj].name)
        self._reset()
        return res_stack

    def minimum_spanning(self, start=0):
        '''
        A minimum spanning tree is created by using the breadth first algorithm
        and recording the steps in a list which is returned.
        
        '''
        queue = deque([start])
        self.vertex[start].visited = True
        res = list()
        while len(queue) > 0:
            current = queue.popleft()
            for adj in self._find_adjacency(current):
                self.vertex[adj].visited = True
                queue.append(adj)
                res.append([self.vertex[current].name, self.vertex[adj].name])
        self._reset()
        return res
    
    def topological_sorting(self, start=0):
        '''
        Think this should be ok. Does not check for circular conditions. 
        '''
        top = self.breadth_search(start)
        top.reverse()
        return top
    
    def add_vertex(self, char):
        self.vertex.append(Vertex(char))

    def add_edge(self, start, end):
        self.adjacency_matrix[start][end] = 1
        self.adjacency_matrix[end][start] = 1
        
    def add_dir_edge(self, start, end):
        self.adjacency_matrix[start][end] = 1

    @property
    def size(self):
        return len(self.vertex)

    def _first_unvisited(self, vertex):
        '''
        Return the first adjucency which is not visited yet.

        '''
        for adj in range(self.size):
            if self.adjacency_matrix[vertex][adj] and not self.vertex[adj].visited:
                return adj
        return -1

    def _find_adjacency(self, vertex):
        '''
        This function returns an iterator(generator) over the unvisited
        verteces for the current vertex. 

        '''
        for adj in range(self.size):
            if self.adjacency_matrix[vertex][adj] != 0 and not \
                    self.vertex[adj].visited:
                yield adj
    
    def _end(self, vertex):
        '''
        Return the end of the graph, that is, a vertex without successors.
        
        '''
    
    def _reset(self):
        for v in self.vertex:
            v.visited = False


class Vertex(object):
    '''
    A node-element in the graph

    '''
    def __init__(self, char):
        self.name = char
        self.visited = False

if __name__ == '__main__':
    pass
