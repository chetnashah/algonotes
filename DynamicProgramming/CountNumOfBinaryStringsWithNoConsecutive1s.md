

## Problem
You are provided an integer N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

## DP approach

Dp on length of string ending in 0 or 1

Base case: 
1. No of "1" length string with no consecutive 1's and ending in 0 = 1.
2. No of "1" length string with no consecutive 1's ending in 1 = 1.
   
### Recurrence:
For creating a string of length i ending in 0, we can append both 1 and 0 to a string of length `i-1` 
`dp[i][0] = dp[i-1][0] + dp[i-1][1]` 

For creating a string of length i ending in 1, we can append only 0, because otherwise we would have consecutive 1s. 
`dp[i][1] = dp[i-1][0]`

Total no. of strings of length i (With no consecutive 1s) = `dp[i][0] + dp[i][1]`


## Solution
```java
	public static long solve(int N) {
		if(N == 0) {
			return 0;
		}
		if(N == 1) {
			return 2;
		}
		long [][] dp = new long [N+1][2]; // dp[N][0] = number of strings of length N ending in 0, dp[N][1] = number of strings of length N ending in 1
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[1][0] = 1; 
		dp[1][1] = 1;
		for(int i=2;i<=N; i++) {
			dp[i][0] = dp[i-1][0] + dp[i-1][1]; // we can count both strings ending with 0 and ending with 1, and append 0
			dp[i][1] = dp[i-1][0];// we can add 1 if smaller string ends with 0
		}
		return dp[N][0] + dp[N][1];
	}
```