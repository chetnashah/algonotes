
## Resources

https://labuladong.gitbook.io/algo-en/iii.-algorithmic-thinking/slidingwindowtechnique

##

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

## Template

```cpp
string s, t;
// Looking for the "minimum substring" of t in s
int left = 0, right = 0;
string res = s;

while(right < s.size()) {
    window.add(s[right]);
    right++;
    // When we found a valid window, move left to find smaller window.
    while (found a valid window) {
        // If the window's substring is shorter, update the res
        res = minLen(res, window);
        window.remove(s[left]);
        left++;
    }
}
return res;
```

### Application

1. Many "longest/smallest substring" satisfaction problems can be solved this way
2. 