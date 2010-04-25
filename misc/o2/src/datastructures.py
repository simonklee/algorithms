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
   A priority queue based on heapq and set. 
   
   '''
   def __init__(self, items=[]):
      self.keys = set(items)
      self.heap = items
      heapq.heapify(self.heap)
   
   def contains(self, item):
      return item in self.keys

   def get(self, item):
      return item if self.contains(item) else None
   
   def pop(self):
      item = heapq.heappop(self.heap)
      self.keys.remove(item)
      return item
   
   def pop_big(self):
      try:
         i = self.heap[-1]
         self.keys.remove(i)
         self.heap.remove(i)
         return i
      except KeyError:
         pass

   def push(self, item):
      if not self.contains(item):
         self.keys.add(item)
         heapq.heappush(self.heap, item)
      
   def push_replace(self, item):
      raise NotImplemented
   
   def peek(self):
      try:
         return self.heap[0]
      except KeyError:
         pass
   
   @property
   def size(self):
      return len(self.keys)