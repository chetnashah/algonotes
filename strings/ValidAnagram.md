

##

https://leetcode.com/problems/valid-anagram/

##

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:
```
Input: s = "anagram", t = "nagaram"
Output: true
```
Example 2:
```
Input: s = "rat", t = "car"
Output: false
```

Constraints:
```
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
```

## Followup - unicode chars?

Use a hash table instead of a fixed size counter. Imagine allocating a large size array to fit the entire range of unicode characters, which could go up to more than 1 million. A hash table is a more generic solution and could adapt to any range of characters.


## Faster approach - freq count and compare - O(n) time and O(A) space, where A is the size of the alphabet

## Sort and compare (n lg n)

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        // if unequal length, cannot be anagram
        if(s.length() != t.length()) {
            return false;
        }
        char[] schars = s.toCharArray();
        char[] tchars = t.toCharArray();
        
        // sort all chars
        Arrays.sort(schars);
        Arrays.sort(tchars);
        
        // one by one comparision
        for(int i=0;i<schars.length;i++) {
            if(schars[i] != tchars[i]) {
                return false;
            }
        }
        return true;
    }
}
```

