
For LCS, refer [DP](DynamicProgramming/../../DynamicProgramming/LongestCommonSubsequence.md)

## Reverse the string and find LCS of reverse with original

## Code

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        int ans = getLCS(s, rev);
        return ans;
    }
    
    public int getLCS(String a, String b) {
        int[][] lcs = new int[a.length()][b.length()];
        
        lcs[0][0] = a.charAt(0) == b.charAt(0) ? 1: 0;
        
        // fill first col
        for(int i=1;i<a.length();i++) {
            lcs[i][0] = Math.max(lcs[i-1][0], a.charAt(i) == b.charAt(0) ? 1 : 0);
        }
        
        // fill first row
        for(int i=1;i<a.length();i++) {
            lcs[0][i] = Math.max(lcs[0][i-1], a.charAt(0) == b.charAt(i) ? 1 : 0);
        }
        
        for(int i=1;i<a.length();i++) {
            for(int j=1;j<b.length();j++){ 
                lcs[i][j] = Math.max(lcs[i-1][j-1] + 
                                     (a.charAt(i) == b.charAt(j) ? 1 : 0),
                                     Math.max(lcs[i-1][j], lcs[i][j-1])
                                    );
            }
        }
        
        return lcs[a.length()-1][b.length()-1];
    }
}
```