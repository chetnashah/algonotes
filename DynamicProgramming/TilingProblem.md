

Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.


This is one dimensional dp on n.
`dp[n] = no. of ways you can tile nxm`, where n is the horizontal dimension i.e. width.

Without loss of generality we will consider n to be horizontal dimension i.e. grows from left to right.
Consider these cases:
1. `n < m` -> the only way to fill this is place 1xm tiles next to each other, so 1.
2. `n = m` -> the only way to place these is either all tiles vertically or all horizontall, so 2.
3. `n > m` -> We now have room to place tiles both horizontally and vertically. in this case we have two transitions possible:
   1. consider placing tile verticaly - no of ways is `dp[n-1]`
   2. consider placing tile horizontally - no of ways is `dp[n-m], n-m >= 0`

Here is a sample solution:
```java
	public static long solve(int N, int M) {
		long MOD = 1000000007;
		long[] dp = new long[N+1];
		dp[0] = 0;
		for(int i=1;i<N+1;i++) {
			if(i<M) {
				dp[i] = 1;
			} else if(i == M) {
				dp[i] = 2;
			} else {
				dp[i] = (dp[i-1] % MOD + dp[i-M] % MOD) % MOD;
			}
		}
		return dp[N] % MOD;
	}
```