

## Definition

Any pair of numbers in a list, which are out of order compared to a sorted version of the list is an inversion

e.g. 
1 4 3 2
has following inversions
4 - 3
4 - 2
3 - 2

## Brute force way

check every pair i,j to see if an inversion

## Divide and conquer (mergesort like)

### Where I got stuck

I thought this could be done without doing the merge sort, i.e. in place without affecting array or any new space.

## Using an ordered_set(e.g. TreeSet)

O(N^2)

## Using Fenwick tree (BIT)

https://youtu.be/kPaJfAUwViY?t=1495



