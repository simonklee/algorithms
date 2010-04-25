#!../ve/bin/python
import unittest

from datastructures import KeyedHashingMixin, KeyedComparisonMixin, PriorityQueue
from project import Project, Task

class ProjectTest(unittest.TestCase):
    
    def __init__(self, *args, **kwargs):
        self.p = Project('testproject.txt')    
        super(ProjectTest, self).__init__(*args, **kwargs)

    def test_project(self):
        expected = (
            ('START', 0),
            ('A', 3),
            ('B', 4),
            ('C', 7),
            ('D', 4),
            ('E', 5),
            ('F', 7),
            ('END', 7),
        )
        tree = self.p.dijkstra()
        for name, earliest_start in expected:
            self.assertEqual(tree[name].earliest_start, earliest_start)

    def test_tasks(self):
        a = Task('A', 2)
        aa = Task('A', 2)
        aaa = Task('A', 3)
        b = Task('B', 2)
        c = Task('C', 3)
        
        self.assertTrue(a.__eq__(aa))
        self.assertTrue(aa.__eq__(a))
        self.assertTrue(aaa.__eq__(a))
        self.assertFalse(a.__eq__(b))
        self.assertFalse(b.__eq__(a))
        
        se = set([a, b])
        self.assertTrue(a in se)
        self.assertTrue(aa in se)
        self.assertTrue(b in se)
        self.assertFalse(c in se)
        
        c.earliest_start = 2
        a.earliest_start = 1
        self.assertFalse(a > c)
  

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
        
    def test_project(self):
        p = Project('testproject.txt')

if __name__ == '__main__':
    unittest.main()
    #project = Project('testproject.txt')