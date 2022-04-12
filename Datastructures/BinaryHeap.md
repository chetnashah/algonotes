

## Resources

https://www.youtube.com/watch?v=HqPJF2L5h9U
https://algs4.cs.princeton.edu/24pq/
https://www.youtube.com/watch?v=g9YK6sftDi0
https://www.youtube.com/watch?v=VkKmmwzfIG4
https://www.youtube.com/watch?v=B7hVxCmfPtM
https://www.youtube.com/watch?v=KkeIB6soiVI
https://visualgo.net/en/heap?slide=1

Two childed tree for getting min/max items easily
Basic version only supports values, not key-value pairs, for that refer [Indexed Priority Queue](IndexedPriorityQueue.md)

## Constraint - Must be a complete binary tree

Must be a complete binary tree -> filling it left-to right and then top to bottom
Due to this property they can be easily packed in an array with a formula to get parent/child indexes,
instead of managing pointers.

## Constraint - Heap ordering

A binary tree is heap-ordered,
 if the key in each node is larger than (or equal to) the keys in that nodes two children (if any).

## structural representation in an array

array  `pq[]` of length `n + 1`, with `pq[0] unused i.e. - (for easier implementation)` and 
the heap in `pq[1]` through `pq[n]`.
`A[0] = _`, i.e. unused first element

### Parent of a given index i

```py
Parent(i) = floor(i/2)
```

### Left child of given index i

```py
LeftChild(i) = 2*i;
```

### Right child of given index i

```py
RightChild(i) = 2 * i + 1
```

## Construction and complexity

Naive construction - O(n log n)
Smart construction - O(n)


## Heapifying an existing array in O(N), How?

Idea: Only internal nodes nead to be heapified(i.e. sink/swim). so only nodes 1 to floor(n/2) need to be heapified.
Since this is a complete binary tree, roughly half the nodes are leaves, and the remaining half are internal nodes.

A clever method that is much more efficient is to proceed from right (i.e mid) to left (zero), using sink() to make subheaps as we go. Every position in the array is the root of a small subheap; sink() works or such subheaps, as well. If the two children of a node are heaps, then calling sink() on that node makes the subtree rooted there a heap.

```java
// arr holds the original array to be heapified
for(i = Math.floor(arr.size/2) - 1; i = 0; i--) {
    heapify(i); // heapify does either sink/swim depending on heap type
}
```

## sink operation - O(lg n)

Needed for heap invariant restoration (Heap ordering property)
Typically used after last element promotion to top.
Bring an element to its final position starting from the top.

In case of min heap, 
`smaller of the two children is picked to take parent's place`.
In case of max heap,
`larger of the two children is picked to take paren'ts place`.

```java
private void sink(int k) {// percolating down starting from index k
   while (2*k <= N) {
      int j = 2*k; // left child index
      if (j < N && less(j, j+1)) { 
          j++;// if right child is bigger (j+1 = 2*k+1), use it
      }
      if (!less(k, j)) // parent(k) is not less than child(j), no need to do anything, break out of the loop
        break;
      // fix smaller parent than child by swapping
      exch(k, j); // swap
      k = j;// new index to process is that of child
   }
}
```

## swim/bubble/percolate operation - O(lg n)

Needed for heap invariant restoration (Heap ordering property)
Typically used after a new element is inserted at the bottom.
Bring an element to its final position starting from the bottom.

Swim code is relatively simple:
```java
// assuming max heap, larger values swim to top
private void swim(int k) {
   while (k > 1 && less(k/2, k)) {// why k > 1 and not k > 0? // parent less than child, need to fix it
      exch(k, k/2);// fix by exchanging
      k = k/2; // iterate on parent idx
   }
}
```
## Common operations of priority Queue ADT

1. `peek` i.e. lookup largest/smallest - O(1)
2.` remove largest/smallest` i.e. ExtractMax - O(log n)
3. `size` O(1)
4. `add/insert` - O(log n)
5. Remove arbitrary element given Key = Indexed Priority Queue ([Indexed Priority Queue](IndexedPriorityQueue.md)
) or Balanced BSTs. We could get index to process by searching the key linearly, but that would be O(n).
6. Replace priority/key = ([Indexed Priority Queue](IndexedPriorityQueue.md) or Balanced BSTs. We could get index to process by searching the key linearly, but that would be O(n).

**Note** - No notion of a search operation.

## Removing from the heap

The heap top element is removed and returned to the caller.
To do the heap restoration,
The last element in the heap is promoted to the top, and `sink` is called on it.

Why is last element chosen for promotion to top?
Because we would still keep the structure as a complete binary tree.

## Applications

Can be used in problems involving `Largest`/`Smallest` keywords.
