
## Maintain one pointer to each list, pick the smaller one and link it to a final list

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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null) {
            return null;
        }
        if(list1 != null && list2 == null) {
            return list1;
        }
        if(list1 == null && list2 != null) {
            return list2;
        }
        
        // now both are non-null nodes
        ListNode finalHead = null;
        ListNode finalCurr = null;
        ListNode l1Next = null;
        ListNode l2Next = null;
        ListNode l1Head = list1;
        ListNode l2Head = list2;
        while(l1Head != null && l2Head != null) {
            if(l1Head.val < l2Head.val) {
                l1Next = l1Head.next;
                l1Head.next = null;
                if(finalHead == null) {
                    finalHead = l1Head;
                    finalCurr = l1Head;
                } else {
                    finalCurr.next = l1Head;
                    finalCurr = finalCurr.next;
                }
                // update l1Head
                l1Head = l1Next;
            } else {
                l2Next = l2Head.next;
                l2Head.next = null;
                if(finalHead == null) {
                    finalHead = l2Head;
                    finalCurr = l2Head;
                } else {
                    finalCurr.next = l2Head;
                    finalCurr = finalCurr.next;
                }
                // update l2Head
                l2Head = l2Next;
            }
        }
        
        // now copy over the remaining list directly
        if(l1Head == null) {
            // only l2 remains
            finalCurr.next = l2Head;
        } else {
            finalCurr.next = l1Head;
        }
        
        return finalHead;
    }
}
```