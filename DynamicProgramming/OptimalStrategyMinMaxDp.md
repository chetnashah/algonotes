

## Dp state

`f(i,j)` = max score player A can collect from idx `i` to `j`.

## DP base case

`i = j` => there is single element to pick, pick it ie. `f(i,i) = a[i]`.


## DP recurrence

We get to pick either element `i` or `j`,
1. If we pick `i`:
   1. opponent can pick `i+1`
   2. or opponent can pick `j`
2. If we pick `j`:
   1. Opponent can pick `j-1`
   2. or oppnonet can pick `i`
```
            | a[i] + min | f(i+2, j)
            |            | f(i+1, j-1) // see this repeating subproblem
f(i,j) = max|
            | a[j] + min | f(i, j-2)
            |            | f(i+1, j-1)  // see this repeating subproblem
```

## Problem and code

https://leetcode.com/problems/predict-the-winner/

## Alternative approach: effective score by substracting other player's score

if we obtain the score for the remaining elements(leaving `x`), this score, now belongs to Player 2. Thus, since Player 2 is competing against Player 1, this score should be subtracted from Player 1's current(local) score(x) to obtain the effective score of Player 1 at the current instant.

Similar argument holds true for Player 2's turn as well i.e. we can subtract Player 1's score for the remaining subarray from Player 2's current score to obtain its effective score. By making use of this observation, we can omit the use of turnturn from winner to find the required result by making the slight change discussed above in the winner's implementation.

```java
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        Integer[][] memo = new Integer[nums.length][nums.length];
        return winner(nums, 0, nums.length - 1, memo) >= 0;// final effective score positive means winner
    }
    public int winner(int[] nums, int s, int e, Integer[][] memo) {// s is for start, e is for end.
        if (s == e)
            return nums[s];
        if (memo[s][e] != null)
            return memo[s][e];
        int a = nums[s] - winner(nums, s + 1, e, memo);// effective score a
        int b = nums[e] - winner(nums, s, e - 1, memo);// effective score b
        memo[s][e] = Math.max(a, b);
        return memo[s][e];
    }
} 
```