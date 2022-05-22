
## DFS can find a cycle in a graph (but O(N) space for visited set)

Linked list is a kind of graph and hence we can find cycles

## Using O(1) space: Floyd's Cycle Finding Algorithm

considering two pointers at different speed - a slow pointer and a fast pointer. 
**The slow pointer moves one step at a time while the fast pointer moves two steps at a time.**

No cycle case - If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.

Cycle case - Since the fast runner is running two steps, even if the cycle is very long (full list), it will have chance to finish the cycle twice. so it will eventually meet slow runner.
The fast runner is just one step behind the slow runner. In the next iteration, they both increment one and two steps respectively and meet each other.

## Code

https://leetcode.com/problems/linked-list-cycle/