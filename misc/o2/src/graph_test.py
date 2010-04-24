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


class TestSpanningTree(unittest.TestCase):
    
    def __init__(self, *args, **kwargs):
        self.graph = Graph()
        for c in range(65, 71):
            self.graph.add_vertex(chr(c))
        self.graph.add_edge(0, 1) # AB
        self.graph.add_edge(0, 2) # AC
        self.graph.add_edge(0, 3) # AD
        self.graph.add_edge(0, 4) # AE
        self.graph.add_edge(1, 2) # BC
        self.graph.add_edge(1, 3) # BD
        self.graph.add_edge(1, 4) # BE
        self.graph.add_edge(2, 3) # CD
        self.graph.add_edge(2, 4) # CE
        self.graph.add_edge(3, 4) # DE
        self.graph.add_edge(4, 5) # EF
        super(TestSpanningTree, self).__init__(*args, **kwargs)
    
    def test_spanning_tree(self):
        '''
        Test the Minimum spanning tree.
        E(edges) should be E = V - 1. Using a breadth-first search so the
        edges will be sort of centralized (find all edges for current first,
        then look for more etc.).
        
        '''
        expected = [
            ['A', 'B'],
            ['A', 'C'],
            ['A', 'D'],
            ['A', 'E'],
            ['E', 'F']
        ]
        res = self.graph.minimum_spanning()
        self.assertEqual(res, expected)
        self.assertEqual(len(res), self.graph.size - 1)


class TestSorting(unittest.TestCase):
    
    def __init__(self, *args, **kwargs):
        self.graph = Graph()
        self.graph.add_vertex('Start')
        for c in range(65, 71):
            self.graph.add_vertex(chr(c))
        self.graph.add_dir_edge(0, 1) # START A
        self.graph.add_dir_edge(0, 2) # START B
        self.graph.add_dir_edge(1, 4) # AD
        self.graph.add_dir_edge(1, 5) # AE
        self.graph.add_dir_edge(2, 3) # BC
        self.graph.add_dir_edge(3, 7) # C END
        self.graph.add_dir_edge(4, 6) # DF
        self.graph.add_dir_edge(5, 7) # E END
        self.graph.add_dir_edge(6, 7) # F END
        self.graph.add_vertex('End')
        super(TestSorting, self).__init__(*args, **kwargs)
        
    def test_topological_sorting(self):
        print self.graph.topological_sorting()
        
if __name__ == '__main__':
    unittest.main()