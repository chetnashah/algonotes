
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

## Single past technique (slow and fast pointers), 


### only start slow pointer after n movements of the fast one

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // n=5 means first node from the head ->
        // n=1 means last node in the linked list -> already checked
        // slow & fast pointer
        ListNode slow = null;
        ListNode fast = head;
        ListNode finalHead = head;

        if(head.next == null && n == 1) {
            return null;
        }
        
        // fast pointer always moves ahead
        // slow pointer should only start moving after fast reaches n
        int cnt = 1;// cnt is number of nodes fast has seen
        while(fast != null) {
            if(cnt > n) {
                if(slow == null) {
                    slow = head;
                } else {
                    slow = slow.next;
                }
            }
            cnt++;
            fast = fast.next;
        }

        if(slow == null) {
            // remove head
            finalHead = head.next;
        } else {
            // invariant: now slow's next should be deleted
            // when fast pointer reaches the end, slow pointer's next can be deleted
            ListNode nextAfterSlowNode = slow.next;
            if(nextAfterSlowNode != null) {
                slow.next = nextAfterSlowNode.next;
            }
        }

        return finalHead;
        
    }
}
```

## Another way of thinking as a node processing loop: ie. loop contents will process node.

```java
// fast pointer always moves ahead
// slow pointer should always be n nodes behind fast
int cnt = 1;// cnt is current fast node (1-indexed)
while(fast != null) {// execute for each node in the list
    // in the processing of fast node, we should increase slow pointer first
    if(cnt > n) {
        // increment slow pointer first, why? because no processing possible after last node processed.
        if(slow == null) {
            slow = head;
        } else {
            slow = slow.next;
        }
    }
    fast = fast.next;// increment fast pointer
    cnt++;
}
// fast is null now
```


## Another approach where we first move n steps ahead, then fast point to (n+1)th node - indexed, and start processing slow node as well

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // n=5 means first node from the head ->
        // n=1 means last node in the linked list -> already checked
        // slow & fast pointer
        ListNode slow = head;// slow points to node before the removed node
        ListNode fast = head;
        ListNode finalHead = head;

        if(head.next == null && n == 1) {
            return null;
        }

        // move fast n steps/edges ahead first, 
        for(int i=0;i<n;i++) {
            fast = fast.next;
        }// after this loop, fast point to n+1th node according 1-indexing of nodes
        
        // special case:
        // if after we have traversed n edges, we are pointing to null end of list,
        // slow has never moved, we have to remove head/slow, special handling
        if(fast == null) {
            return head.next;
        }
        
        // non-special case: slow points to node before the one to be removed
        while(fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        
        if(slow == null) {
            // remove head
            finalHead = head.next;
        } else {
            // invariant: now slow's next should be deleted
            // when fast pointer reaches the end, slow pointer's next can be deleted
            ListNode nextAfterSlowNode = slow.next;
            if(nextAfterSlowNode != null) {
                slow.next = nextAfterSlowNode.next;
            }
        }

        return finalHead;
        
    }
}
```