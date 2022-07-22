
##

https://leetcode.com/problems/reverse-linked-list-ii/

##

## Note: we are given positions (not values) for the subsection of linked list

### Two passes: one pass to get the leftNode and rightNode

### Another pass to reverse the list from leftNode to rightNode, and put the reversed list in proper place

## Code

```java
class Solution {
  public ListNode reverseBetween(ListNode head, int left,int right) {
    ListNode nodeBeforeNewHead = null;
    ListNode nodeAfterNewTail = null;
    ListNode newHead = null;
    ListNode newTail = null;
    ListNode finalHead = head;

    ListNode leftNode = null;
    ListNode rightNode = null; 
    // take the list and reverse from left to right
    //

    ListNode curr = head;
    ListNode prevCurr = null;

    int cnt = 1;// one indexed count num of node for curr
    while(curr != null) {
      if(cnt == left) {
        nodeBeforeNewHead = prevCurr;
        leftNode = curr;
      }
      if(cnt == right) {
        rightNode = curr;
        nodeAfterNewTail = rightNode.next;
      }
      if(prevCurr == null) {
        prevCurr = head;
      } else {
        prevCurr = prevCurr.next;
      }
      curr = curr.next;
      cnt++;
    }

    // 3, 5
    // nodes were not found
    if(leftNode == null || rightNode == null) {
      return finalHead;
    }

    // now we have leftNode and rightNode, we must reverse the list from leftNode to rightNode
    //
    ListNode[] newHeadTail = reverseList(leftNode, rightNode);
    newHead = newHeadTail[0];
    newTail = newHeadTail[1];

    if(nodeBeforeNewHead == null) {
      finalHead = newHead;
    } else {
      nodeBeforeNewHead.next = newHead;
    }
    newTail.next = nodeAfterNewTail;

    return finalHead;
  }

  ListNode[] reverseList(ListNode leftNode, ListNode rightNode) {
    if(leftNode == rightNode) {
      return new ListNode[]{ leftNode, rightNode };
    }
    // leftNode and rightNode are different
    //
    ListNode prev = leftNode;
    ListNode curr = leftNode.next;

    prev.next= null;
    ListNode newTail = prev;
    while(curr != rightNode) {
      ListNode tempNext = curr.next;
      curr.next = prev;
      prev = curr;
      curr = tempNext;
    }
    // run one more time for rightNode
    curr.next = prev;
    ListNode newHead = curr;

    return new ListNode[]{ newHead, newTail };
  }
}

```