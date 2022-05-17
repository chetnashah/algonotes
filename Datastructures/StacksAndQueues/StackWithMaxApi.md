
## resource

https://www.youtube.com/watch?v=nGwn8_-6e7w

https://www.youtube.com/watch?v=0bpDvc2VjPU

https://www.youtube.com/watch?v=QMlDCR9xyd8

## A max() api that returns max element present in the stack 

API:


Usually it is easy to maintain max while pushing, but popping is when we need to remember extra state.

## Solution with extra auxillary space O(N) for storing max till given index

we cache max value after each push in an auxillary array `maxSeenTillIndex`.

```java
  public static class Stack  {
    ArrayList<Integer> arrayList = new ArrayList<>();
    ArrayList<Integer> maxSeenTillIndex = new ArrayList<>();// stores max for each stack index possible
    public boolean empty() {
      return arrayList.size() == 0;
    }
    public Integer max() {
      return maxSeenTillIndex.get(arrayList.size()-1);
    }
    public Integer pop() {
      maxSeenTillIndex.remove(arrayList.size()-1);
      return arrayList.remove(arrayList.size()-1);
    }
    public void push(Integer x) {
      arrayList.add(x);
      Integer maxSeen;
      int maxSeenTillLastIdx = maxSeenTillIndex.size() == 0 ? Integer.MIN_VALUE : maxSeenTillIndex.get(maxSeenTillIndex.size()-1);
      maxSeen = Math.max(x, maxSeenTillLastIdx);
      maxSeenTillIndex.add(maxSeen);
    }
  }
```

## Variant : popMax() + max() api

https://leetcode.com/problems/max-stack/
https://www.youtube.com/watch?v=9by6MxQOjeM

`MaxStack()` Initializes the stack object.
`void push(int x)` Pushes element x onto the stack.
`int pop()` Removes the element on top of the stack and returns it.
`int top()` Gets the element on the top of the stack without removing it.
`int max()` Retrieves the maximum element in the stack without removing it.
`int popMax()` Retrieves the maximum element in the stack and removes it (other items are not removed). If there is more than one maximum element, only remove the top-most one. 

Here auxillary storing state array like above does not work.

### Doubly linked list + TreeMap

O(N) space for storing these nodes
O(logN) for all operations except peek/top which is O(1), where N is the number of operations performed. Treemap ops are logN.

Core idea:

double linked list as our "stack". This reduces the problem to finding which node to remove, since we can remove nodes in O(1)O(1) time.

The tree map would be multi set tree map, and for each item inserted (e.g. integer), value in hashmap could be an arraylist of nodes, each of which point to nodes in DLL.
```java
class Node {
    int val;
    Node prev, next;
    public Node(int v) {val = v;}
}

TreeMap<Integer, ArrayList<Node>> map;// list of nodes against an int takes care of duplicate ints in the stack, the later elements of DLL appear towards end of this array list
DoubleLinkedList dll;
```

1. When we `MaxStack.push(x)`, 
   1. we add a node to our dll, and 
   2. add or update our entry `map.get(x).add(node)`.

2. When we `MaxStack.pop()`, 
   1. we find the value `val = dll.pop()`, and 
   2. remove the node from our map, deleting the entry if it was the last one.

3. When we `MaxStack.popMax()`, 
   1. we use the map to find the relevant node to unlink, and return it's value.



