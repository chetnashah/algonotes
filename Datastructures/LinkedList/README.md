

## Should I use `curr.next != null` or `curr != null` in loop traversal?

* If you want `while loop code executed for all nodes including the last non-null one` -> Use `curr != null`.
  * Make sure you are not setting curr.next in this loop to anything other than null.

* if you do `curr.next != null`, the **while loop code shall not be executed for last node**, you must add special handling after the loop ends for doing anything about the last node.


