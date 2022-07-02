
##

We defined linked list length as number of nodes in the linked list, instead of number of edges.

## Code

```java
int length(ListNode head) {
    ListNode curr = head;
    int len = 0;
    while(curr != null) {// no node ahead
        len++;// increment count of node, before traversing the edge
        curr = curr.next;
    }
    return len;
}
```
