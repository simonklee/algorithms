// I'll try out a more generic and c-specific approach to bsearch.

#ifndef __BINARYSEARCHG_H
#define __BINARYSEARCHG_H

// The bsearch() function searches an array of nmemb objects,
// the initial member of which is pointed to by base,  for  a
// member  that  matches  the  object pointed to by key.  The
// size of each member of the array is specified by size.

// The contents of the array should be  in  ascending  sorted
// order  according  to the comparison function referenced by
// compar.  The compar routine is expected to have two  argu‐
// ments  which  point to the key object and to an array mem‐
// ber, in that order, and  should  return  an  integer  less
// than,  equal to, or greater than zero if the key object is
// found, respectively, to be less  than,  to  match,  or  be
// greater than the array member.

// The  bsearch()  function  returns  a pointer to a matching
// member of the array, or NULL if no  match  is  found.   If
// there  are  multiple elements that match the key, the ele‐
// ment returned is unspecified.

// -- man bsearch

// se info bsearch for even more info, or search.h

void *BinarySearchG(const void *key, const void *base,
            size_t nmemb, size_t size,
            int (*compar)(const void *, const void *));

// Compare functions are needed since binary search function doesn't know
// how to compare void *'s.

int IntegerCompare(const void *a, const void *b);
int StringCompare(const void *a, const void *b);

#endif
