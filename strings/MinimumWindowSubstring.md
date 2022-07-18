
##

https://leetcode.com/problems/minimum-window-substring/

https://www.youtube.com/watch?v=jSto0O4AJbM

https://www.youtube.com/watch?v=eS6PZLjoaq8

##

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. 

If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```
Example 2:
```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

Example 3:
```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 ```

Constraints:
```
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
```

## Approach 1 (TLE): Start with windows fo size t, t+1, t+2, ... s and see if freq counts match 

Freq comparision: O(1) -> 26 ops

Number of windows of size t: s-t+1

Number of windows of size (t+1) : s-(t+1)+1

...

Number of windows of size s: 1

In the worst case t = 1, then we have s windows of size 1, s-1 windows of size 2, s-2 windows of size 3...
so overall complexity would be O(S^2). This is tough because S ~ 10^5. So we must do better.

## Where is the extra work being done in above approach?

We can skip some start pointers (and their corresponding windows) if they do not contribute to `t`.
e.g. for "ADOBECODEBANC", start pointers at D,O do not contribute anything extra and are useless, so instead of checking windows starting at those chars, just skip them.

## Approach 2: Sliding window

### We keep track of best length seen -> bestLengthSeen

Initialize `bestLenghtSeen = s.length()` (which means full string)

### Start window keeps increasing to make it invalid (i.e. less than Ts chars)

Whenever we decrease start, if we still have valid, we update bestLengthSeen with a the better estimate.

Reason: we might have useless charachters in prefix, which by removing them can give us a better estimate

### End window keeps increasing to make strng valid (i.e. atleast Ts chars)

Reason: we must explore more chars to make string valid.

### TODO Code

## Follow up: Could you find an algorithm that runs in O(m + n) time?


