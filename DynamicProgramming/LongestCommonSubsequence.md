

## Description

Longest Common Subsequence problem, also known as LCS, the goal is for given two strings `S[1..n]` and `T[1..m]`, to find the length of their longest common subsequence. This is a classical problem which can be solved efficiently using dynamic programming approach. 

The idea is to compute `f[i][j]`, which is the length of the longest common subsequence of `S[1..i]` and `T[1..j]`. 

The value of `f[i][j]` can be computed in this problem knowing the values of `f[i-1][j]`, `f[i-1][j-1]` and `f[i][j-1]`. 

Then the final answer is the value of `f[n][m]`. In this approach, an entry in  table is called a state, and since the table is 2-dimensional, this dynamic programming solution is 2-dimensional

## Recursive LCS (without memo)

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        String s = "abaca";
        String t = "daaca";
        System.out.println(getLCS(s,t, s.length()-1, t.length()-1));
    }
    
    static int getLCS(String s, String t, int slen, int tlen) {
        if(slen == -1 || tlen == -1){// one of the strings is empty, no common chars so 0
            return 0;
        }
        if(slen == 0 || tlen == 0) {// single char in one of the strings
            return s.charAt(slen) == t.charAt(tlen) ? 1 : 0;
        }
        return getMax(
            getLCS(s,t, slen -1, tlen), // remove a char from first string
            getLCS(s,t, slen, tlen-1),  // remove a char from second string
            getLCS(s,t, slen-1, tlen-1) + ((s.charAt(slen) == t.charAt(tlen)) ? 1 : 0) // remove char from both strings, while adding one if removed char was same
        );
    }
    
    public static int getMax(Integer... vals) {
        return Collections.max(Arrays.asList(vals)); 
    }
}
```

## Code

```java
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()][text2.length()];// 0-indexed
        // dp[i][j] = lcs for text1 ending in ith char and text2 ending in jth char
        dp[0][0] = text1.charAt(0) == text2.charAt(0) ? 1 : 0;
        for(int i=1;i<text1.length();i++) {// filling first col
            dp[i][0] = Math.max(dp[i-1][0], text2.charAt(0) == text1.charAt(i) ? 1 : 0);
        }
        for(int i=1;i<text2.length();i++) { // fillig first row
            dp[0][i] = Math.max(dp[0][i-1], text1.charAt(0) == text2.charAt(i) ? 1 : 0);
        }
        for(int i=1;i<text1.length();i++) {
            for(int j=1;j<text2.length();j++) {
                dp[i][j] = Collections.max(Arrays.asList(dp[i-1][j], dp[i][j-1], ((text1.charAt(i) == text2.charAt(j) ? 1 : 0) + dp[i-1][j-1])));
            }
        }

        // print dp state
        // for(int i=0;i<text1.length();i++) {
        //     for(int j=0;j<text2.length();j++) {
        //         System.out.print(dp[i][j]);
        //     }
        //     System.out.println();
        // }
        return dp[text1.length() - 1][text2.length() - 1];
    }
```

## Applications

1. Longest palindromic subsequence - 

