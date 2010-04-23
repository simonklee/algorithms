#!../ve/bin/python
from numpy import zeros
import unittest

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
    
    def add_vertex(self, char):
        self.vertex.append(Vertex(char))
    
    def add_edge(self, start, end):
        self.adjacency_matrix[start][end] = 1
        self.adjacency_matrix[end][start] = 1
    
    @property
    def size(self):
        return len(self.vertex)

    def depth_search(self, start=0):
        '''
        Rules for the depth-first search:
        
            R1: If possible, visit an adjacent unvisted vertex, mark it, and
            push it to the stack
            
            R2: If you can't follow R1, then, if possible, pop a vertex of the
            stack.
            
            R3: if you can't follow R1 or R2, you're done.        
        
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
        for v in self.vertex:
            v.visited = False
        return res_stack

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
        Return a list of adjuceants for this vertex
        
        '''
        return [adj for adj in range(self.size)
            if self.adjacency_matrix[vertex][adj] != 0]


class Vertex(object):
    '''
    A node-element in the graph
    
    '''
    def __init__(self, char):
        self.name = char
        self.visited = False


class TestGraph(unittest.TestCase):
    '''
    Test the basic graph operations.
    
    '''
    def setUp(self):
        self.graph = Graph()
    
    def test_1setup(self):
        self.assertEqual(self.graph.size, 0)
        self.assertEqual(self.graph.adjacency_matrix.sum(), 0)
        self.assertEqual(self.graph.adjacency_matrix.size, 400)
    
    def test_2add(self):
        size = self.graph.size + 1
        self.graph.add_vertex('A')
        self.assertEqual(self.graph.vertex[0].name, 'A')
        self.assertEqual(self.graph.vertex[0].visited, False)
        self.assertEqual(self.graph.size, size)
    
    def test_3edge(self):
        for c in range(66, 70):
            self.graph.add_vertex(chr(c))
        self.graph.add_edge(0, 1) # AB
        self.graph.add_edge(1, 2) # BC
        self.graph.add_edge(0, 3) # AD
        self.graph.add_edge(3, 4) # DE
        self.assertEqual(self.graph.adjacency_matrix[1][2], 1)


class TestSearch(unittest.TestCase):
    '''
    Kind of ugly test search class, but I couldnt get it to work in a different
    way due to some mechanics in the unittest framework which are unknown to me.
    
    '''        
    def __init__(self, *args, **kwargs):
        self.graph = Graph()
        for c in range(65, 70):
            self.graph.add_vertex(chr(c))
        self.graph.add_edge(0, 1) # AB
        self.graph.add_edge(1, 2) # BC
        self.graph.add_edge(0, 3) # AD
        self.graph.add_edge(3, 4) # DE
        super(TestSearch, self).__init__(*args, **kwargs)
    
    def test_depth_search(self):
        '''
        Performs a search and records the result. Test to see if the order is
        correct.
        
        '''
        self.assertEqual(self.graph.depth_search(), ['A', 'B', 'C', 'D', 'E'])

if __name__ == '__main__':
    graph = Graph()
    for c in range(65, 70):
        graph.add_vertex(chr(c))
    graph.add_edge(0, 1) # AB
    graph.add_edge(1, 2) # BC
    graph.add_edge(0, 3) # AD
    graph.add_edge(3, 4) # DE
    graph.depth_search()
    unittest.main()
