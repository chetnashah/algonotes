
##

https://leetcode.com/problems/partition-list/

##

Given the head of a linked list and a value x, **partition it such that all nodes less than x come before nodes greater than or equal to x.**

You should preserve the original relative order of the nodes in each of the two partitions.

## 
Example1:
```
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```
Example 2:
```
Input: head = [2,1], x = 2
Output: [1,2]
 ```

Constraints:
```
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
```

## Approach

### Keep two separate heads & running ends for each list, and one main iteration node curr

```java
ListNode firstListCurr = null;// running end node for first list
ListNode secondListCurr = null;// running end node for second list
ListNode firstListHead = null;
ListNode secondListHead = null;

ListNode curr = head;
```

### Create a method: insertAfter(node, insertNode) to insert a node after a given node

```java
public void insertAfter(ListNode node, ListNode nodeToBeInserted) {
    nodeToBeInserted.next = null;
    node.next = nodeToBeInserted;
}
```

### Iterate over main list, keeping track of which list to insert in

```java
ListNode curr = head;
while(curr != null) {
    ListNode nextNode = curr.next;// record before manipulation
    /*
    processing step -> add to correct list based on curr.val
    */
    curr = nextNode;
}
```

### Gotchas/Things I missed

1. for main `curr` iteration, record nextNode to iterate on, before modification
2. firstList or secondList might be null

## Code

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode firstListCurr = null;// running end node for first list
        ListNode secondListCurr = null;// running end node for second list
        ListNode firstListHead = null;
        ListNode secondListHead = null;
        
        ListNode curr = head;
        while(curr != null) {
            // System.out.println("curr = " + curr.val);
            ListNode nextNode = curr.next;// record before manipulation
            if(curr.val < x ) {// candidate for first list
                if(firstListHead == null) {
                    firstListHead = curr;
                    firstListCurr = curr;
                    firstListHead.next = null;// dont forget this!
                } else {
                    insertAfter(firstListCurr, curr);
                    firstListCurr = firstListCurr.next;
                }
            } else { // curr.val >= x, so goes in second list
                if(secondListHead == null) {
                    secondListHead = curr;
                    secondListCurr = curr;
                    secondListHead.next = null;
                } else {
                    insertAfter(secondListCurr, curr);
                    secondListCurr = secondListCurr.next;
                }
            }
            curr = nextNode;
        }
        
        // now append second list to first list
        // and return first
        if(firstListCurr != null) {
            firstListCurr.next = secondListHead;
        } else { // all elements were greater than or equal to x
            firstListHead = secondListHead;
        }

        return firstListHead;
    }
    
    public void insertAfter(ListNode node, ListNode nodeToBeInserted) {
        nodeToBeInserted.next = null;
        node.next = nodeToBeInserted;
    }
}
```
