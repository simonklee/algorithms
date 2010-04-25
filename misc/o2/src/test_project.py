#!../ve/bin/python
import unittest

from datastructures import KeyedHashingMixin, KeyedComparisonMixin, PriorityQueue
from project import Project, Task

class ProjectTest(unittest.TestCase):
    
    def __init__(self, *args, **kwargs):
        self.p = Project('testproject.txt')    
        super(ProjectTest, self).__init__(*args, **kwargs)

    def test_project(self):
        #self.p.dijkstra()
        pass


class Item(KeyedHashingMixin, KeyedComparisonMixin):
    
    def __init__(self, x):
        self.x = x
        
    def __key__(self):
        return self.x


class TestPriorityQueue(unittest.TestCase):
    
    items = [Item(x) for x in range(10)]
    
    def test_init_pop(self):
        pq = PriorityQueue(self.items)
        self.assertEqual(pq.peek().x, 0)
        [self.assertEqual(pq.pop().x, i) for i in range(pq.size)]
        self.assertEqual(pq.size, 0)
    
    def test_push_pop(self):
        pq = PriorityQueue([])
        pq.push(Item(5))
        pq.push(Item(1))
        pq.push(Item(3))
        self.assertEqual(pq.pop().x, 1)
    
    def test_contains(self):
        pq = PriorityQueue(self.items)
        self.assertEqual(pq.contains(Item(4)), True)

if __name__ == '__main__':
    unittest.main()
    #project = Project('testproject.txt')