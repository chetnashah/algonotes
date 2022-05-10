
## Problem description

There are N wines in a row.
You can sell either leftmost wine or the right most wine.
You are given an array of prices `p[i]`.
The `ith` wine has price `p[i]` and in the `kth` year, the price is `k * p[i]`.
What is the maximum possible revenue?

## Resources

https://www.youtube.com/watch?v=pwpOC1dph6U

## Example array

| 2 | 4 | 6 | 2 | 5 |


## Initial approach preference (greedy)

Since the older wine is getting costly and might result in more profit, we might want to 
sell cheaper wine first and increment that pointer inwards (left or right), till we run out of all items to sell.

Greedy approach for above would result in choosing in following order:(2,4,5,2,6):
` (2 * 1) + (4 * 2) + (5 * 3) + (2 * 4) + (6 * 5)` = 53

But optimal choice is following (2, 5, 2, 4, 6):
= 64.


### Why greedy does not work?

Combinatorial nature of problem.

## Recursive decomposition

This is a classic case of **dp on sub-intervals**. In fact any time you have subproblems that involve same subintervals that show up again and again, dp can be used.

```
maxProfit([1, N]) -> max(maxProfit([1, N-1]) + p[N] , maxProfit([2,N])+p[1]) 
```



## State definition

The state is a interval range `[L, R]`.

## State transition



## Directionality in this problem

