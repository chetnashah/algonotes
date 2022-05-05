
It's a deque with an interesting property - the elements in the deque from head to tail are in decreasing order (hence the name monotonic)..

when we push an element into the deque, we first pop everything smaller than it out of the deque.

This enforces the decreasing order.

## Time complexity

The time complexity is `O(N)`. This is because each element in the original array can only be pushed into and popped out of the deque once.`

