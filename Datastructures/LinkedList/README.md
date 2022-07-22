

## Should I use `curr.next != null` or `curr != null` in loop traversal?

* (preferred choice) If you want `while loop code executed for all nodes including the last non-null one` -> Use `curr != null`.
  * Make sure you are not setting `curr.next` in this loop to anything other than null.

* if you do `curr.next != null`, the **while loop code shall not be executed for last node, essentially it runs code per edge before the last node**, you must add special handling after the loop ends for doing anything about the last node.


## Deleting a node is simple, if you have reference to its previous node

so try to keep your loops in such a way that you reach the node previous to the one that has to be deleted.
`prevNode.next = nodeToBeRemoved.next`.

### What if head has to be deleted?

Keep a special marker if necessary.


