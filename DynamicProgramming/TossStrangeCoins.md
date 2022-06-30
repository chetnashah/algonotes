
##

https://leetcode.com/problems/toss-strange-coins/

## Gotchas

Lot of edge cases in base cases

probability of having 0 coins and 0 heads = 1.

## Code

```java
class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        int N = prob.length;
        double[][] dp = new double[prob.length+1][target+1];
        
        dp[0][0] = 1;// 0 coins, 0 heads

        dp[1][0] = 1-prob[0];
        // first column
        for(int i=2;i<=prob.length;i++) {
            dp[i][0] = dp[i-1][0]*(1-prob[i-1]);// i coins, 0 heads
        }
        // first row
        for(int i=1;i<=target;i++) {
            dp[0][i] = 0;
        }
                
        // dp[c][k] is the prob of tossing c first coins and get k faced up.   
        // dp[c][k] = dp[c - 1][k] * (1 - p) + dp[c - 1][k - 1] * p)
        for(int i=1;i<=prob.length;i++) {
            double p = prob[i-1];
            for(int j=1;j<target+1;j++) {
                if(j > i) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
                }
            }
        }
        
        return dp[prob.length][target];
    }
}
```