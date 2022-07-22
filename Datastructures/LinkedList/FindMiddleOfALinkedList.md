
## Maintain two pointers: fast and slow

Both pointers start at head

## fast moves two steps, slow moves one step, iteration stopping condition

```java
Node slow, fast = head;
while(fast && fast.next) {
    fast = fast.next.next;
    slow = slow.next;
}
```

## Termination

At the end of termination,
slow points to middle of list
1. exact middle in case of odd length list
2. start of second half of linked list in case of even length list

Fast points to end of list
1. last node in case of odd length linked list
2. Null node in case of even length list

## 

![linkedlistmiddle](images/linkedlistmiddle.jpg)


## Applications

Delete middle element of linkedlist (the one to the right in case of even length).

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
    public ListNode deleteMiddle(ListNode head) {
        ListNode nodeBeforeSlow = null;// because removing head might be a possibility
        ListNode fast = head;
        
        // only single node, remove it
        if(head.next == null) {
            return null;
        }
        
        // fast moves two steps, slow moves one step but stays to the element before the node to be deleted
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            if(nodeBeforeSlow == null) {
                nodeBeforeSlow = head;
            } else {
                nodeBeforeSlow = nodeBeforeSlow.next;
            }
        }
        
        // delete the node in question
        nodeBeforeSlow.next = nodeBeforeSlow.next.next;
        return head;
        
    }
}
```