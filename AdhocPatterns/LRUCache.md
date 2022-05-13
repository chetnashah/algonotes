

## LRU means least recently used (remove oldest accessed entry)

Note - this is different then LFU (least frequently used).
The algorithm is about replacement policy when cache is full and some member needs to be evicted to make space for latest access/write to the cache.

Parameters:

1. fixed cache size `N`.
2. Query api: `Get(x)`, `set(x, y)`
3. Q number of queries
   

## Data structures needed

1. Hashmap - for quick search for hit/miss of entry in cache. It will be `Map<Key, NodeReferenceInDoublyLinkedList>`
2. Doubly linked list - fast access to start/end, items in linked list are in the order of access.
   1. Anytime an existing element is accessed, it needs to be removed from its position and put to the front of the linked list. This require three steps
      1. Searching the node accessed (Hashmap - O(1))
      2. Get its previous pointer, next pointer in doubly linked list (since we will remove the searched element) - O(1)
      3. Append to head (since it is most recently accessed), head appending is in O(1).