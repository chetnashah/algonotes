
## 

Given 3 strings, tell if third string is an interleaving of the first two.

https://leetcode.com/problems/interleaving-string/

Important applications in concurrency testing.
Note the ordering is preserved considering chars of a single string.

## variation: TODO: see if you can generat alll possible interleavings



## Initial wrong approach: 2 pointers: greedily match and increment pointers in first two till we can satisfy the full 3rd string

Failing test case:
```
"aabc"
"abad"
"aabadabc"
```

## Recursive approach TLE

We can choose from the end.
We have two options:
1. pick from first string
2. or pick from second string.

Test case:
```
"cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc"
"abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb"
"abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb"
```


## multi dimensional DP approach with TLE

```java
class Solution {
    
    int[][][][] ans;
    public boolean isInterleave(String s1, String s2, String s3) {
        // two pointers - one in first string, 2nd in second string

        if(s3.length() != s1.length() + s2.length()) {
            return false;
        }
        
        ans = new int[200+1][100+1][100+1][2];
        for(int i=0;i<201;i++) {
            for(int j=0;j<101;j++) {
                for(int k=0;k<101;k++) {
                    ans[i][j][k][0] = -1;
                    ans[i][j][k][1] = -1;
                }
            }
        }
        
        
        int isReachable1 = checkReachable(s3.length(), s2.length(), s1.length(), 1, s1,s2,s3);
        int isReachable2 = checkReachable(s3.length(), s2.length(), s1.length(), 0, s1,s2,s3);

        return (isReachable1 == 1) || (isReachable2 == 1);
    }
    
    // can we reach till p3 using p1 and p2
    // let p1, p2, p3 be 1 indexed
    // 1 is true, 0 is false
    int checkReachable(int p3, int p2, int p1, int lastPickOne, String s1, String s2, String s3) {
        if(ans[p3][p2][p1][lastPickOne] != -1) {
            return ans[p3][p2][p1][lastPickOne];
        }

        if(p1 == 0 && p2 == 0 && p3 == 0) {
            ans[p3][p2][p1][lastPickOne] = 1;
            return 1;
        }
        
        
        if(p1 == 0 && p2 != 0) {
            // check all p2 chars
            int pp3 = p3;
            for(int i=p2-1;i>=0;i--) {
                if(s2.charAt(i) != s3.charAt(pp3-1)){
                    ans[p3][p2][p1][lastPickOne] = 0;
                    return 0;
                }
                pp3--;
            }
            ans[p3][p2][p1][lastPickOne] = 1;
            return 1;
        } 
        
        if(p2 == 0 && p1 != 0) {
            // check all p1 chars
            int pp3 = p3;
            for(int i=p1-1;i>=0;i--) {
                if(s1.charAt(i) != s3.charAt(pp3-1)){
                    ans[p3][p2][p1][lastPickOne] = 0;
                    return 0;
                }
                pp3--;
            }
            ans[p3][p2][p1][lastPickOne] = 1;
            return 1;
        }
        
        // some chars remaining in all 3
        if(lastPickOne == 1){
            if(s1.charAt(p1-1) == s3.charAt(p3-1)) {
                int reach1 = checkReachable(p3-1, p2, p1-1, 1, s1,s2,s3);
                int reach2 = checkReachable(p3-1, p2, p1-1, 0, s1,s2,s3);
                int canReach = (reach1 == 1 || reach2 == 1) ? 1 : 0;
                ans[p3][p2][p1][lastPickOne] = canReach;
                return canReach;
            } else {
                ans[p3][p2][p1][lastPickOne] = 0;
                return 0;
            }
        } else { // lastPickTwo
            if(s2.charAt(p2-1) == s3.charAt(p3-1)) {
                int reach1 = checkReachable(p3-1, p2-1, p1, 1, s1,s2,s3);
                int reach2 = checkReachable(p3-1, p2-1, p1, 0, s1,s2,s3);
                int canReach = (reach1 == 1 || reach2 == 1) ? 1 : 0;
                ans[p3][p2][p1][lastPickOne] = canReach;
                return canReach; 
            } else {
                ans[p3][p2][p1][lastPickOne] = 0;
                return 0;
            }
        }
        
    }
}
```

## MultiDim DP - After optimizing array initialization, and short-circuit length check in recursion, got AC

```java
class Solution {
    
    int[][][][] ans;
    public boolean isInterleave(String s1, String s2, String s3) {
        // two pointers - one in first string, 2nd in second string

        if(s3.length() != s1.length() + s2.length()) {
            return false;
        }
        
        ans = new int[s3.length()+1][s2.length()+1][s1.length()+1][2];
        for(int i=0;i<s3.length()+1;i++) {
            for(int j=0;j<s2.length()+1;j++) {
                for(int k=0;k<s1.length()+1;k++) {
                    ans[i][j][k][0] = -1;
                    ans[i][j][k][1] = -1;
                }
            }
        }
        
        
        int isReachable1 = checkReachable(s3.length(), s2.length(), s1.length(), 1, s1,s2,s3);
        int isReachable2 = checkReachable(s3.length(), s2.length(), s1.length(), 0, s1,s2,s3);

        return (isReachable1 == 1) || (isReachable2 == 1);
    }
    
    // can we reach till p3 using p1 and p2
    // let p1, p2, p3 be 1 indexed
    // 1 is true, 0 is false
    int checkReachable(int p3, int p2, int p1, int lastPickOne, String s1, String s2, String s3) {
        if(ans[p3][p2][p1][lastPickOne] != -1) {
            return ans[p3][p2][p1][lastPickOne];
        }
        
        if(p1 + p2 != p3) {
            ans[p3][p2][p1][lastPickOne] = 0;
            return 0;
        }

        if(p1 == 0 && p2 == 0 && p3 == 0) {
            ans[p3][p2][p1][lastPickOne] = 1;
            return 1;
        }
        
        
        if(p1 == 0 && p2 != 0) {
            // check all p2 chars
            int pp3 = p3;
            for(int i=p2-1;i>=0;i--) {
                if(s2.charAt(i) != s3.charAt(pp3-1)){
                    ans[p3][p2][p1][lastPickOne] = 0;
                    return 0;
                }
                pp3--;
            }
            ans[p3][p2][p1][lastPickOne] = 1;
            return 1;
        } 
        
        if(p2 == 0 && p1 != 0) {
            // check all p1 chars
            int pp3 = p3;
            for(int i=p1-1;i>=0;i--) {
                if(s1.charAt(i) != s3.charAt(pp3-1)){
                    ans[p3][p2][p1][lastPickOne] = 0;
                    return 0;
                }
                pp3--;
            }
            ans[p3][p2][p1][lastPickOne] = 1;
            return 1;
        }
        
        // some chars remaining in all 3
        if(lastPickOne == 1){
            if(s1.charAt(p1-1) == s3.charAt(p3-1)) {
                int reach1 = checkReachable(p3-1, p2, p1-1, 1, s1,s2,s3);
                int reach2 = checkReachable(p3-1, p2, p1-1, 0, s1,s2,s3);
                int canReach = (reach1 == 1 || reach2 == 1) ? 1 : 0;
                ans[p3][p2][p1][lastPickOne] = canReach;
                return canReach;
            } else {
                ans[p3][p2][p1][lastPickOne] = 0;
                return 0;
            }
        } else { // lastPickTwo
            if(s2.charAt(p2-1) == s3.charAt(p3-1)) {
                int reach1 = checkReachable(p3-1, p2-1, p1, 1, s1,s2,s3);
                int reach2 = checkReachable(p3-1, p2-1, p1, 0, s1,s2,s3);
                int canReach = (reach1 == 1 || reach2 == 1) ? 1 : 0;
                ans[p3][p2][p1][lastPickOne] = canReach;
                return canReach; 
            } else {
                ans[p3][p2][p1][lastPickOne] = 0;
                return 0;
            }
        }
        
    }
}
```

## 2D recursion

Why is 2D recursion possible?
We would have two choices at every step, either select from 1st string, or select from 2nd string.

### Observation: if we maintain one pointer p1 in s1 and one pointer p2 in s2, p3 should always be p1+p2


Here, We are going from 0 -> n instead of n->0.
```java
public class Solution {
    public boolean is_Interleave(String s1, int s1CharsConsideredSoFar, String s2, int s2CharsConsideredSoFar, String res, String s3)
    {
        // instead of char comparision, we do string building and string comparision here
        if(res.equals(s3) && s1CharsConsideredSoFar == s1.length() && s2CharsConsideredSoFar == s2.length()) {
            return true;
        }
        boolean ans = false;
        if(i < s1.length()) {// only branch if possible
            ans |= is_Interleave(s1, s1CharsConsideredSoFar + 1, s2, s2CharsConsideredSoFar, res + s1.charAt(i), s3);
        }
        if(j < s2.length()) {// only branch if possible
            ans |= is_Interleave(s1, s1CharsConsideredSoFar, s2, s2CharsConsideredSoFar + 1, res + s2.charAt(j), s3);
        }
        return ans;
    }


    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        return is_Interleave(s1, 0, s2, 0, "", s3);
    }
}
```

### We can improve the above 2D recursion with Memo or iterative approach

```java
 public class Solution {
    public boolean is_Interleave(String s1, int i, String s2, int j, String s3, int k, int[][] memo) {
        if (i == s1.length()) {// s1 is over, check remaining of s2 with s3
            return s2.substring(j).equals(s3.substring(k));
        }
        if (j == s2.length()) {// s2 is over, check remaining of s1 with s3
            return s1.substring(i).equals(s3.substring(k));
        }
        // note there is some extra calculation before memo
        if (memo[i][j] >= 0) {// none of the two are over, but we have computed this before, return it
            return memo[i][j] == 1 ? true : false;
        }
        // none of the two are over, and we have not comptutd this before. 
        // check ends of both and try to answer
        boolean ans = false;
        if (s3.charAt(k) == s1.charAt(i) && is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)
                || s3.charAt(k) == s2.charAt(j) && is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int memo[][] = new int[s1.length()][s2.length()];
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                memo[i][j] = -1;
            }
        }
        return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
    }
}
```

## 2D dynamic programming - iterative table filling

We will reserve up `[s1.length()+1][s2.length()+1]` amount of space, meaning, algorithm is 1-indexed.

### DP state
`dp[i][j] = is it possible to obtain substring of length i+j which is prefix of s3, by interleaving prefixes of length i chars of s1 and prefix of length j chars of s2`.

### DP base case

`dp[0][0] = true` - it is possible to reach substring of length 0 in s3, by interleaving 0 char of s1 and 0 char of s2.

Assuming we layout s1 in row fashion
and s2 against it in column fashion

Filling first row - char by char comparision of s1 with s3

Filling first column - char by char comparision of s2 with s3

### DP transitions

If matching with veertical string, subproblem to check is smaller vertical with same horizontal - think of it like this: I am matching a char in vertical string, see if i can also interleave one length shorter of the same string with 1 length shorter s3.

If matching char with horizontal string, subrpoblem to chck is smaller horizontal before - think of it like this: I am matching a char in vertical string, see if i can also interleave one length shorter of the same string with 1 length shorter s3.

```java
        // s1 laid out vertically
        // s2 laid out horizontally
        ans = new boolean[s1.length()+1][s2.length()+1];

       ans[i][j] = 
           // match from i, i.e s1, i.e vertical, subrproblem in vertical above
           s1.charAt(i-1) == s3.charAt(i+j-1) && ans[i-1][j]
           || 
           // match from j, i.e s2 i.e. horizontal, subrproblem in horizontal before
           s2.charAt(j-1) == s3.charAt(i+j-1) && ans[i][j-1];
```

```java
class Solution {
    
    boolean[][] ans;
    public boolean isInterleave(String s1, String s2, String s3) {
    
        if(s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        // s1 laid out vertically
        // s2 laid out horizontally
        ans = new boolean[s1.length()+1][s2.length()+1];
    
    
        ans[0][0] = true;
        
        // fill first row
        for(int i=1;i<s2.length()+1;i++) {
            ans[0][i] = ans[0][i-1] && s2.charAt(i-1) == s3.charAt(i-1);
        }
        
        // fill first column
        for(int i=1;i<s1.length()+1;i++) {
            ans[i][0] = ans[i-1][0] && s1.charAt(i-1) == s3.charAt(i-1);
        }
        
        // fill the inner table
        for(int i=1;i<s1.length()+1;i++) {
            for(int j=1;j<s2.length()+1;j++) {
                ans[i][j] = 
                    // match from i, i.e s1, i.e vertical, subrproblem in vertical above
                    s1.charAt(i-1) == s3.charAt(i+j-1) && ans[i-1][j]
                    || 
                    // match from j, i.e s2 i.e. horizontal, subrproblem in horizontal before
                    s2.charAt(j-1) == s3.charAt(i+j-1) && ans[i][j-1];
            }
        }
        
        return ans[s1.length()][s2.length()];
    }
}
```


## 1D dynamic programming 

If we observe 2D table filling in above explaination, it only uses two rows at a time: current row and previous row.
So it can be optimized to be O(smallerString.length())

