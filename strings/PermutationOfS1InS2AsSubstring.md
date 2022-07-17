##

https://leetcode.com/problems/permutation-in-string/

##
Given two strings `s1` and `s2`, return true if `s2` contains a permutation of `s1`, or false otherwise.

In other words, return true if one of `s1`'s permutations is the substring of `s2`.

 
Example 1:
```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```
Example 2:
```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 ```

Constraints:
```
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
```

## Interesting learning: comparing hashmap freq of chars in Any two hashmaps is O(1) i.e. only 26 key/values

## Approach 1: for every substring/window of s2 of size (k = s1.length()), check if substring char freq counts match up with s1 char freq counts

n-k+1 windows * O(1) per window comparision = O(26 * N-k+1) where N = s2.length() and k = s1.length.







