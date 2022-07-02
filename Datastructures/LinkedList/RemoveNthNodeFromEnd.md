
##

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

##



##

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
    public ListNode removeNthFromEnd(ListNode head, int n) {// counting starts from end in 1-indexed format
        
        if(head.next == null) { // single node, only it can be removed, remove it
            return null;
        }
        
        // more than one node
        // get length of list : length is num of nodes
        ListNode curr = head;
        int len = 0;
        while(curr != null) {
            len++;
            curr = curr.next;
        }
        
        if(len == n) { // head needs to be removed
            return head.next;
        }
        
        // non-head needs to be removed
        // kth node from end is (N-k+1)th node from start in 1 based indexing
        int cnt=1;// cnt is number of nodes behind curr
        ListNode prev;
        curr = head.next;
        prev = head;
        while(cnt != len-n) {
            cnt++;
            prev = curr;
            curr = curr.next;
        }
        // curr points to node to be removed
        prev.next = curr.next;
        
        return head;
    }
}
```