
## Learnings

* backtracking state
* Breaking string backtracking

### dp state

`dp[i] = string starting at index i to end is part of dict`

### dp transition

For all possible breaking of string, check if remaining string is part is also satisfies dictionary recursively.

### Time complexity

O(N^3) - but do not know how - TODO figure out how.

### Recursion with memoization

code:
```java
class Solution {
    Set<Integer> fulfills;
    Set<Integer> doesNotFulfill;
    public boolean wordBreak(String s, List<String> wordDict) {
        fulfills = new HashSet<Integer>();
        doesNotFulfill = new HashSet<Integer>();
        return wordBreakBacktrack(s, new HashSet<String>(wordDict), 0);
    
    }
    
    // try checking if string starting at start index in s, can be completely found in dict
    private boolean wordBreakBacktrack(String s, Set<String> dict, int start) {
        if(fulfills.contains(start)) {// check memo
            return true;
        }
        if(doesNotFulfill.contains(start)) {// check memo
            return false;
        }
        if(start == s.length()) { // termination condition, all string before this was part of dict, and we have nothing to process
            return true;
        }
        for(int end=start+1; end<=s.length();end++) {// backtrack
            String firstPart = s.substring(start, end); // end idx is not included
            if(dict.contains(firstPart) && wordBreakBacktrack(s, dict, end)) {//
                fulfills.add(start);// save in memo
                return true;
            }
        }
        doesNotFulfill.add(start);// save in memo
        return false;
    }
}
```

## BFS approach

