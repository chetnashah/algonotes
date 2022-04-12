
## why?

`Priority Queue` by itself has no notion of:
1. search - `getIdx(k)`
2. update a keyed entity - `update(k, v)`
3. delete a keyed element - `delete(k)`

But many algorithms need this functionality, hence IndexedPriorityQueue

## Resources

https://algs4.cs.princeton.edu/24pq/
https://www.youtube.com/watch?v=jND_WJ8r7FE
https://algs4.cs.princeton.edu/24pq/IndexMinPQ.java.html

## Indexed priority Queue ADT interface
Indexed priority Queue is an ADT with following interface:

`Item extends Comparable<Item>`
1. `insert(int k, Item item)` - insert item, associate it with k
2. `update(int k, Item item)` - change item associated with k to item
3. `contains(int k)` - is k associate with some item
4. `delete(int k)` - delete item associated with k
5. `min()` - return the min item
6. `deleteMin()` - return and delete the min item
7. `size()` - size of the priority queue


## Applications

1. Djikstra's Algorithm to find single source shortest path.
2. 