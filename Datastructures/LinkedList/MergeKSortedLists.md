
## Idea might be clear but implementation is tricky

## Divide and conquer approach

We already know how to merge two sorted lists inside [merge two sorted lists](MergeTwoSortedLists.md)

We merge consecutive pairs of lists like this, until we have single list remaining.

Complexity: TODO


## Priority Queue approach

### We put nodes on priority queue, and whenever popped, we can push its next into priority queue

### Priority queue comparator should work on node values

### dont push null nodes onto priority queue

### Complexity

TODO

### Code

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
    public ListNode mergeKLists(ListNode[] lists) {
        // base conditions
        if(lists.length == 0) {
            return null;
        }
        if(lists.length == 1) {
            return lists[0];
        }
        
        Comparator<ListNode> comparator = new Comparator<>(){
            @Override
            public int compare(ListNode l1, ListNode l2) {
                return Integer.compare(l1.val, l2.val);
            }
        };
        
        PriorityQueue<ListNode> pq = new PriorityQueue<>(comparator);
        
        // more than one sorted lists to merge
        // put head of all lists in priority queue
        // the node itself contains next pointer, which must be traversed on pop
        for(int i=0;i<lists.length;i++) {
            ListNode ithList = lists[i];
            if(ithList != null) {
                pq.add(ithList);
            }
        }
        
        ListNode finalAns = null;
        ListNode finalCurr = null;
        
        while(!pq.isEmpty()) {
            ListNode poppedNode = pq.poll();
            if(poppedNode.next != null) {
                pq.add(poppedNode.next);
            }
            poppedNode.next = null;
            
            if(finalAns == null) {
                finalAns = poppedNode;
                finalCurr = poppedNode;
            } else {
                finalCurr.next = poppedNode;
                finalCurr = finalCurr.next;
            }
        }
        return finalAns;
    }
}
```