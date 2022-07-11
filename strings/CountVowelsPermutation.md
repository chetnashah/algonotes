

##

https://leetcode.com/problems/count-vowels-permutation/

##

## Core Idea: DP

`dp[i][vowel] = i length string ending in vowel a,e,i,o,u`

Ans = `dp[n][0] = num of chars ending in a` +  `dp[n][1] = num of chars ending in e` + `dp[n][2] = num of chars ending in i`
+ `dp[n][3] = num of chars ending in o` + `dp[n][4] = num of chars ending in u`.


## Code

```java
class Solution {
    public int countVowelPermutation(int n) {
        if(n == 1) {
            return 5;
        }
        
        long MOD = 1000000007;
        // n > 1
        // dp[i][vowel] = i length string that ends in voewel : a, e, i, o, u
        long[][] ans = new long[n+1][5];
        ans[1][0] = 1L; // a
        ans[1][1] = 1L;// e
        ans[1][2] = 1L; // i
        ans[1][3] = 1L;// o
        ans[1][4] = 1L;// u 
        
        for(int i=2;i<n+1;i++){
            ans[i][0] = (ans[i-1][1] % MOD + ans[i-1][4] % MOD + ans[i-1][2] % MOD) % MOD; // a can appear after u or i or e
            ans[i][1] = (ans[i-1][0] % MOD + ans[i-1][2] % MOD) % MOD; // e can appear after a, or after i
            ans[i][2] = (ans[i-1][3] % MOD + ans[i-1][1] % MOD) % MOD;// i cann appear after o or e
            ans[i][3] = (ans[i-1][2] % MOD ) % MOD; // o can appear after i
            ans[i][4] = (ans[i-1][2] % MOD + ans[i-1][3] % MOD) % MOD; // u can appear after i or o
        }
    
        long finalAns = 0;
        for(int i=0;i<5;i++) {
            // System.out.println("ans[n][i] = "+ ans[n][i]);
            finalAns = (finalAns % MOD + ans[n][i] % MOD) % MOD;
        }
        
        return (int)finalAns;
    }
}
```