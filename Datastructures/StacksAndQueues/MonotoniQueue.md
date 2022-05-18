
##

Monotonic Queue is a data structure that keeps it’s elements either entirely in non-increasing, or entirely in non-decreasing order.

In general, the following "prototype" problems can be solved by monotonic queue:

```
Any DP problem where A[i] = min(A[j:k]) + C 
where j < k <= i
```
This is a sliding max/min window problem.

