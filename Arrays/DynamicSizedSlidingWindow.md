
window size can vary continuously as we keep processing arr elements

### approach 1: both start and end pointers start from 0

### Main outer loop

endIndex goes from `0` to `n-1`

i.e.
`for endIdx in range(len(arr))`


### startIdx increment condition

This usually depends on the type of the problem, 
which decides when do we want to shrink the window.


### How many dynamically sized windows possible in an array of size N?

N windows of size 1.
N-1 windows of size 2.
N-2 windows of size 3.
N-3 windows of size 4.
...
N-k+1 windows of size k. (Refer to Arrays/FixedSizeSlidingWindow.md for this formula)
...
1 indow of size N.

Total number of windows:
1 + 2 + 3 + .... + N = n * (n + 1)/2 = O(n ^ 2).

### Application

1. Many "longest/smallest substring" satisfaction problems can be solved this way
2. 