

## Count number of palindromic substrings

### The state we compute again if inner strings of range `[i..j]` are palindromes, which only needs to be computed once

### recursive dp code

```java
class Solution {
    int[][] dp;
    public int countSubstrings(String s) {
        // try top down   
        dp = new int[s.length()][s.length()];
        for(int i=0;i<s.length();i++) {
            for(int j=0;j<s.length();j++) {
                dp[i][j] = -1;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<s.length();i++) {
            for(int j=i;j<s.length();j++) {
                if(isPalindrome(i, j, s)) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
    // recursive way to check if palindrome
    boolean isPalindrome(int start, int end, String s) {
        // System.out.println("start = "+ start + " end = " + end);
        if(start == end){
            dp[start][end] = 1;
            return true;
        }

        if(dp[start][end] != -1) {
            return true;
        }
        if(start+1 == end) {
            boolean ans = s.charAt(start) == s.charAt(end);
            // System.out.println("1 start = "+ start + " end = " + end + " ans = "+ ans);
            dp[start][end] = ans ? 1 : -1;
            return ans;
        }
        boolean ans = s.charAt(start) == s.charAt(end) && isPalindrome(start+1, end-1, s);
        // System.out.println("2 start = "+ start + " end = " + end + " ans = "+ ans);
        dp[start][end] = ans ? 1 : -1;
        return ans ; 
    }
}
```

### iterative dp

```java
class Solution {
    public int countSubstrings(String s) {
        int n = s.length(), ans = 0;

        if (n <= 0) 
            return 0;

        boolean[][] dp = new boolean[n][n];

        // Base case: single letter substrings
        for (int i = 0; i < n; ++i, ++ans) 
            dp[i][i] = true;

        // Base case: double letter substrings
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
            ans += (dp[i][i + 1] ? 1 : 0);
        }

        // All other cases: substrings of length 3 to n
        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                dp[i][j] = dp[i + 1][j - 1] && (s.charAt(i) == s.charAt(j));
                ans += (dp[i][j] ? 1 : 0);
            }

        return ans;
    }
}
```

### Expand around centers approach - Naive is O(N^2), optimal is manacher's algorithm - O(N)

TODO - https://leetcode.com/problems/palindromic-substrings/solution/#approach-3-expand-around-possible-centers

## Variation: find longest palindromic substring

## Faster but hard algorithms

Binary Search with a fast rolling hash algorithm (like Rabin-Karp). This approach tries to optimize Approach #3 by speeding up the time to figure out the largest palindrome for each of the 2N-12N−1 centers in logarithmic time. This approach counts all palindromic substrings in O(N \log{N})O(NlogN) time. Here's a Quora answer by T.V. Raziman which explains this approach well.

Palindromic trees (also known as EERTREE). It is a data structure invented by Mikhail Rubinchik which links progressively larger palindromic substrings within a string. The tree construction takes linear time, and the number of palindromic substrings can be counted while constructing the tree in O(N)O(N) time. Additionally, the tree can be used to compute how many distinct palindromic substrings are in a string (it's just the number of nodes in the tree) and how frequently each such palindrome occurs. This blog post does a good job of explaining the construction of a palindromic tree.

Suffix Arrays with quick Lowest common Ancestor (LCA) lookups. This approach utilizes Ukonnen's algorithm to build suffix trees for the input string and its reverse in linear time. Subsequently, quick LCA lookups can be used to find maximum palindromes, which are themselves composed of smaller palindromes. This approach can produce a count of all palindromic substrings in O(N)O(N) time. The original paper describes the algorithm, and this Quora answer demonstrates an example.

Manacher's algorithm. It's basically Approach #3, on steroids.TM The algorithm reuses computations done for previous palindromic centers to process new centers in sub-linear time (which reduces progressively for each new center). This algorithm counts all palindromic substrings in O(N)O(N) time. This e-maxx post provides a fairly simple implementation of this algorithm.

