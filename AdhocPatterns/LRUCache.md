

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

## Where I got stuck

1. impl is long /takes time
2. check size properly
3. evict only if item does not exist
4. both k/v pair are given, I initially solved a simpler problem of using just keys

## Code

```java
class Pair <T, R> {
  public T key;
  public R value;

  Pair(T key, R value) {
    this.key = key;
    this.value = value;
  }

  @Override
  public String toString() {
    return "Pair{" +
      "key=" + key +
      ", value=" + value +
      '}';
  }
}

class DoublyLinkedList <T> {
  DoublyLinkedListNode <T> head;
  DoublyLinkedListNode <T> tail;
  int size = 0;

  static class DoublyLinkedListNode <T> {
    DoublyLinkedListNode <T> next;
    DoublyLinkedListNode <T> prev;
    T val;

    @Override
    public String toString() {
      return val.toString();
    }
  }

  public void insertAtFront(T item) {
    DoublyLinkedListNode <T> newHead = new DoublyLinkedListNode<>();
    newHead.val = item;
    if (head != null) {
      head.prev = newHead;
      newHead.next = head;
    } else { // first node is both head and tail
      tail = newHead;
    }
    head = newHead;
    size = size + 1;
  }

  public void eraseNode(DoublyLinkedListNode <T> node) {
    if (node == null) {
      return;
    }
    if (size == 1) {
      head = tail = null;
      size = 0;
      return;
    }
    DoublyLinkedListNode <T> prev = node.prev;
    DoublyLinkedListNode <T> next = node.next;

    if (prev != null && next != null) {
      prev.next = next;
      next.prev = prev;
    } else if (prev == null && next != null) { // we are head
      head.next.prev = null;
      head = head.next;
    } else if (prev != null) { // we are tail
      tail.prev.next = null;
      tail = tail.prev;
    }

    size = size - 1;
  }

  public void moveToFront(DoublyLinkedListNode <T> node) {
    if (node == null || node == head) {
      return; // already at front
    }

    // first remove from its given position
    DoublyLinkedListNode <T> nextNode = node.next;
    DoublyLinkedListNode <T> prevNode = node.prev;

    if (nextNode != null && prevNode != null) {
      nextNode.prev = prevNode;
      prevNode.next = nextNode;
    }
    if (nextNode == null) { // we are tail
      prevNode.next = null;
      tail = prevNode;
    }

    // now make node as new head
    node.next = head;
    head.prev = node;
    head = node;
  }

  public String printLinkedList() {
    DoublyLinkedListNode <T> start = head;
    String str = "";
    while (start != null) {
      str = str + start + "->";
      start = start.next;
    }
    str = str + "NULL";
    return str;
  }

  public T dequeueAtEnd() {
    T ret = null;
    if (tail == null) { // linked list is empty do nothing
      size = 0;
      return null;
    }
    ret = tail.val;
    if (tail == head) { // single node, remove
      tail = head = null;
      size = 0;
      return ret;
    }
    if (tail.prev != null) {
      tail.prev.next = null;
    }
    tail = tail.prev;
    size = size - 1;
    //System.out.println("dequeueFromEnd: "+ret);
    return ret;
  }
}

class LRUCache {
  Integer capacity;
  HashMap <Integer, DoublyLinkedList.DoublyLinkedListNode <Pair<Integer, Integer>>> map;
  DoublyLinkedList <Pair<Integer, Integer>> linkedList;

  public LRUCache(int capacity) {
    this.capacity = capacity;
    //System.out.println("cap = " + capacity);
    linkedList = new DoublyLinkedList<>();
    map = new HashMap<>();

  }

  public int get(int key) {
    //System.out.println("lookup : "+key);
    DoublyLinkedList.DoublyLinkedListNode <Pair<Integer, Integer>> existsInMap = map.getOrDefault(key, null);
    if (existsInMap == null) {
      return -1;
    } else {
      //System.out.println("key " + key + "found in linked list,moving to front");
      linkedList.moveToFront(existsInMap);
    }
    //System.out.println("After lookup of key" +key +" linkedList : " +linkedList.printLinkedList());
    return linkedList.head.val.value;

  }

  public void put(int key, int value) {
    // evict LRU item if necessary
    //System.out.println("inserting key = " + key + " value = " +value + " linkedlistsize = " +linkedList.size);

    DoublyLinkedList.DoublyLinkedListNode <Pair<Integer, Integer>> existsInMap = map.getOrDefault(key, null);
    if (existsInMap == null) {
      if (linkedList.size >= capacity) {
        Pair < Integer, Integer > kv = linkedList.dequeueAtEnd();
        //System.out.println("evicting: " + kv.key);
        map.remove(kv.key);
      }

      linkedList.insertAtFront(new Pair<>(key, value));
      map.put(key, linkedList.head);
    } else {
      linkedList.moveToFront(existsInMap);
      linkedList.head.val.value = value;
    }
    //System.out.println("after insert key" + key +" linkedlist = " + linkedList.printLinkedList());

  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```