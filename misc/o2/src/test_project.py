#!../ve/bin/python
import unittest

from datastructures import KeyedHashingMixin, KeyedComparisonMixin, PriorityQueue
from project import Project, Task


class ProjectTest(unittest.TestCase):
    
    def __init__(self, *args, **kwargs):
        self.p = Project('testproject.txt')    
        super(ProjectTest, self).__init__(*args, **kwargs)

    def test_earliest(self):
        expected = (
            ('START', 0),
            ('A', 0),
            ('B', 0),
            ('C', 4),
            ('D', 3),
            ('E', 3),
            ('F', 4),
            ('END', 7),
        )
        tree = self.p.earliest()
        for name, earliest_start in expected:
            self.assertEqual(tree[name].earliest_start, earliest_start)
            #print "%s @ earliest_start: %s" % (name, tree[name].earliest_start)
        #for k, v in tree.iteritems():
        #    print "%s @ %s" % (k, v.earliest_start)
    
    def test_latest(self):
        expected = (
            ('START', 0),
            ('A', 0),
            ('B', 0),
            ('C', 4),
            ('D', 3),
            ('E', 5),
            ('F', 4),
            ('END', 7),
        )
        p = Project('testproject.txt')
        p.earliest(debug=False)
        tree = p.latest(debug=False)
        for name, latest_start in expected:
            self.assertEqual(tree[name].latest_start, latest_start)
           # print "%s @ latest_start: %s" % (name, tree[name].latest_start)
        #for k, v in tree.iteritems():
        #    print "%s @ %s" % (k, v.latest_start)

    def test_critical(self):
        '''
        The critical path function will return one critical path.
        
        This path is expected with the testproject.txt-file.
        
        name : START, ea: 0, la: 0, dur: 0
        name : A,     ea: 0, la: 0, dur: 3        
        name : D,     ea: 3, la: 3, dur: 1
        name : F,     ea: 4, la: 4, dur: 3
        name : END,   ea: 7, la: 7, dur: 0
        
        name : START, ea: 0, la: 0, dur: 0
        name : B,     ea: 0, la: 0, dur: 4
        name : C,     ea: 4, la: 4, dur: 3
        name : END,   ea: 7, la: 7, dur: 0
        
        name : START, ea: 0, la: 0, dur: 0
        name : A,     ea: 0, la: 0, dur: 3   
        name : E,     ea: 3, la: 5, dur: 2
        STOP

        '''
        expected = ('START', 'A', 'D', 'F', 'END')
        
        p = Project('testproject.txt')
        p.earliest()
        p.latest()
        path = p.critical()
        
        for i, t in enumerate(path):
            #print "name : %s, ea: %s, la: %s, dur: %s" % \
            #(t.name, t.earliest_start, t.latest_start, t.duration)
            self.assertEqual(t.name, expected[i])
        
        

    def test_topological(self):
        expected = ('START', 'A', 'B', 'C', 'E', 'D', 'F', 'END')
        p = Project('testproject.txt')
        p.earliest()
        p.latest()
        
        for i, t in enumerate(p.topological()):
            #print "%s, %s" % (t.name, expected[i])
            self.assertEqual(t.name, expected[i])

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
        pq = PriorityQueue(lambda i: i.__key__(), self.items)
        self.assertEqual(pq.peek().x, 0)
        [self.assertEqual(pq.pop().x, i) for i in range(pq.size)]
        self.assertEqual(pq.size, 0)
    
    def test_push_pop(self):
        pq = PriorityQueue(lambda i: i.__key__(), [])
        pq.push(Item(5))
        pq.push(Item(1))
        pq.push(Item(3))
        self.assertEqual(pq.pop().x, 1)
    
    def test_contains(self):
        pq = PriorityQueue(lambda i: i.__key__(), self.items)
        self.assertEqual(pq.contains(Item(4)), True)
    
if __name__ == '__main__':
    unittest.main()
