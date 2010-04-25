#!../ve/bin/python
import unittest
import heapq


class KeyedEqualityMixin(object):
   def __eq__(self, other):
       return self.__key__() == other.__key__()
   def __ne__(self, other):
       return self.__key__() != other.__key__()


class KeyedComparisonMixin(KeyedEqualityMixin):
    def __lt__(self, other):
        return self.__key__() < other.__key__()
    def __le__(self, other):
        return self.__key__() <= other.__key__()
    def __gt__(self, other):
        return self.__key__() > other.__key__()
    def __ge__(self, other):
        return self.__key__() >= other.__key__()


class KeyedHashingMixin(KeyedEqualityMixin):
    def __hash__(self):
        return hash(self.__key__())


class PriorityQueue(object):
    '''
    A priority queue based on heapq and set. Memory usage isn't very good,
    but the lookup is. Based on an example found on stackoverflow.com
    
    '''
    def __init__(self, items=[]):
        self.keys = set(items)
        self.heap = items
        heapq.heapify(self.heap)
    
    def contains(self, item):
        return item in self.keys
    
    def pop(self):
        item = heapq.heappop(self.heap)
        self.keys.remove(item)
        return item
    
    def push(self, item):
        if item not in self.keys:
            self.keys.add(item)
            heapq.heappush(self.heap, item)
    
    def peek(self):
        try:
            return self.heap[0]
        except KeyError:
            pass
    
    @property
    def size(self):
        return len(self.keys)