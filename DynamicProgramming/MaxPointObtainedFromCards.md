

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

## 

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


Example 1:
```
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
```
Example 2:
```
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
```
Example 3:
```
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 ```

Constraints:
```
1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length
```



## Memory TLE DP Approach I tried is DP on sub-ranges but got memory TLE for n^2 where n = 10^5

```java
class Solution {
    int[][] dp;
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        dp = new int[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j] = -1;
            }
        }
        
        return getBestInRange(0, n-1, cardPoints, 0, k);
    }
    
    int getBestInRange(int l, int r, int[] nums, int currentK, int k) {
        if(currentK >= k) {
            return 0;
        }
        if(l == r) {
            return nums[l];
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int bestAfterChoosingLeft = nums[l] + getBestInRange(l+1, r, nums, currentK+1, k);
        
        int bestAfterChoosingRight = nums[r] + getBestInRange(l, r-1, nums, currentK+1, k);
        
        dp[l][r] = Math.max(bestAfterChoosingLeft, bestAfterChoosingRight);
        
        return dp[l][r];
    }
}
```

## important observation: Three sub arrays formed: one at start (picked), one in the middle unpicked, and one in the last(picked)

the k cards that we choose will form two contiguous subarrays: one at the start, and one at the end of the input array.

## Sliding window approach (with prefix sums for range/subarray sums) - find min (unpicked) Subarray in the middle, so it can be dropped, and rest two on the ends can be picked

### Since we have to select k items to form max sum, we should select a subarray of size n-k in between which has minimum sum

Sum for each range of size k can be calculated in O(1) using prefix sum.
There will be `n-k` such ranges so answer can be calculated in O(N) time and O(N) space

## Sliding window approach without prefix sums

Refer fixed size subarray variant in [Max subarray sum with subarrays of size K](MaxSubarraySum.md) 

## DP approach (with prefix sums of first and last K items)

### Calculate prefix sum of first k items, also create prefix sums of last k items 

We shall create two arrays to calculate prefix sum of first k items and prefix sum of last k items.

TODO: finish checking all approaches from : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/solution/