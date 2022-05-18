

## Brute force approach

We track max with a single variable.

`Enqueue`: tracking max is simple, we update max with previous known max.
`Dequeue`: We must track max by checking against all the remaining elements in queue.

## Insight

In a queue, both end pointer moves on adding elements, and front pointer moves on dequeueing elements.
hence you can think of these two pointers forming a sliding window.


