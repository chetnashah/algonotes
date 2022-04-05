
### Resources
https://www.educative.io/courses/grokking-the-coding-interview/7D5NNZWQ8Wr
https://www.youtube.com/watch?v=MK-NZ4hN7rs


###

Fixed size window: window first grows to size `k`, and then slides to the right on each step (both start/end pointers are incremented).

A running aggregate that updates as a window made by start and end pointer is slid towards the right.

### Two pointers start and end

### Start both pointer with 0 idx

### Outer/main loop starts with end-idx going from 0 to n-1, (no loop for startIdx, only ++ inside if condition)
```py
startIdx = endIdx = 0
```

### A aggregate variable for running calculation e.g. `windowSum`

Running variable aggregate updated at the start of loop combined with newest end-idx.

### Invariant: aggregate always signifies aggregate of current window, so whenever window slides, aggregate needs to be stored toa result arr

#### When should start pointer be incremented? (when window starts sliding)

For all end-pointer-idx when `end-pointer-idx >= k - 1`, startIdx++.
Because before that we have not processed the first window, and after this condiiton each step is a sliding step,
hence startIdx movement.

### decide the window size to be k

### Aggregate operation (sum/min/avg)

On starting of window sliding (condition mentioned above)
the aggregate is saved into result array, `result[start] = aggregate`
aggregate is updated by moving out the startidx contribution: `aggregate -= arr[start]`
Finally we update the start to actually keep track of it: `start++`


### How many `k` sized windows are possible for an array of Size N?

Ans: `len(N) - len(k) +1`
First window: 0 to k-1 idx
Second window: 1 to k idx
Third window: 2 to k+1 idx
...
Last window:  x to n-1 idx.

How to calculate x? 
Invariant: windowEndIdx - windowStartIdx = k-1 for each window.
so `n - 1 - x = k - 1`
or `x = n - k`

final window: `n-k to n-1` idx

If we see all windows rangeS: `0 to k-1`, `1 to k`, ... `n-k to n-1`.
Which means there are `n-k+1` windows in total.

### Applications

1. Rabin karp rolling hash for all substrings of size |P|
2. max sum subarray of size K.

### Auxilary data structures

You can also have auxilary array,set, map to store some window aggregate/summaries.