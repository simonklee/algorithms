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


class PriorityQueue(object):
   '''
   A priority queue based on heapq and hashmap.
   
   This is a overly complicated solution for something that shouldn't be that
   hard. My input to the program was.
   
      * be able to choose key to sort after.
      * be unique and uniqueness aka __eq__() should not have something to
        do with key.
      * be able to pop from both ends.
      * be fast lookup.
      
   I think a sorted array would have been better than this, even though the
   lookup with b-search in a sorted array is worst-case, it's less memory use
   and overhead then keeping track of two datastructures.
   
   '''
   def __init__(self, key, items=[]):
      self.keys = dict((item, item) for item in items)
      self.heap = list((key(item), item) for item in items)
      self.key = key
      heapq.heapify(self.heap)
   
   def contains(self, item):
      return item in self.keys

   def get(self, item):
      return item if self.contains(item) else None
   
   def pop(self):
      prio, item = heapq.heappop(self.heap)
      return self.keys.pop(item)      
   
   def pop_big(self):
      try:
         prio, item = self.heap[-1]
         self.heap.remove((prio,item))
         return self.keys.pop(item)
      except KeyError:
         pass

   def push(self, item):
      if not self.contains(item):
         self.keys.update({item:item})
         heapq.heappush(self.heap, (self.key(item), item))
      
   def push_replace(self, item):
      raise NotImplemented
   
   def peek(self):
      try:
         pr, item = self.heap[0]
         return item
      except KeyError:
         pass
   
   @property
   def size(self):
      return len(self.keys)
