

## DP state

`dp[j][i]` = if `charArray[j..i]` is a palindromme

## DP state transition.

wE fill the dp table from left to right, inner loop from top to bottom.
we consult palindrome result saved for smaller strings to consult larger strings that are palindromes

## Code

```java
import java.util.*;
public class Main {
    public static void main (String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] dp = new int[n][n];
		String line = sc.next();
		char[] charArray = line.toCharArray();
		int T = sc.nextInt();

		preprocess(charArray, dp);
		for(int i=0;i<T;i++) {
			int start = sc.nextInt();
			int end = sc.nextInt();
			System.out.println(solve(start,end, dp));
		}
    }

	public static void preprocess(char[] charArray, int[][] dp) {
		for(int i=0;i<charArray.length; i++) {
			dp[i][i] = 1; // single char are palindrome by default
		}
		// dp[j][i] = if charArray[j..i] is a palindromme
		for(int i=0;i<charArray.length;i++) { // i is the col no.
			for(int j=0;j<i;j++) { // j is the row num per col
				boolean firstLastSameChar = (charArray[j] == charArray[i]);

				if(dp[j][i] == 1) continue;
				if(j+1 == i && firstLastSameChar) { // adjacent, 2 char strings
					dp[j][i] = 1;
					continue;
				}
				// more than 2char strings, we have middle to check
				int prev1 = dp[j+1][i-1];
				if(prev1 == 1 && firstLastSameChar) {
					dp[j][i] = 1;
				}
			}
		}
	}

	public static String solve(int start, int end, int[][] dp) {
		return dp[start-1][end-1] == 1 ? "YES" : "NO";
	}
}
```