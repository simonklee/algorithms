#!../ve/bin/python
import unittest
from graph import Graph

class TestGraph(unittest.TestCase):
    '''
    Test the basic graph operations.
    
    '''
    def setUp(self):
        self.graph = Graph()
    
    def test_setup(self):
        self.assertEqual(self.graph.size, 0)
        self.assertEqual(self.graph.adjacency_matrix.sum(), 0)
        self.assertEqual(self.graph.adjacency_matrix.size, 400)
    
    def test_add(self):
        size = self.graph.size + 1
        self.graph.add_vertex('A')
        self.assertEqual(self.graph.vertex[0].name, 'A')
        self.assertEqual(self.graph.vertex[0].visited, False)
        self.assertEqual(self.graph.size, size)
    
    def test_edge(self):
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
    
    def test_breadth_search(self):
        self.assertEqual(self.graph.breadth_search(), ['A', 'B', 'D', 'C', 'E'])

if __name__ == '__main__':
    unittest.main()