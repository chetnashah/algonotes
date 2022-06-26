
Also known as kadanes algorithm

## Brute foce approach O(n^3)

1. check all pairs: i,j : O(n^2) 
   1. compute their sum, and update max: O(n)

## Prefix sum approach: O(n^2)

Calculate cumulative sum and make a new array i.e. which stores `sum[0..i]` which can be populated by a single pass.
In this case, we can compute `sum[L..R]` in constant time, because `sum[L..R] = sum[0..R] - sum[0..L-1]`
so overall time complexity reduces to `O(n^2)`.

## Insight what are we recomputing?

smaller subarray sum can be used to calculate larger subarray sums.
This can lead to O(n^2) storage 

## Dp approach: O(N)

### Dp state

`dp[i]` = positive sum of items upto ith index

### Dp transition

keep including and incrementing current value till it keeps the total sum i.e. `dp[i]` positive,
if `dp[i]` becomes negative on including current elemtn, skip and reset start pointer for max seen.

**Also keep track of `maxSeenSoFar`.**

```
dp[i] = max(arr[i], dp[i-1]+arr[i])
and 
maxSeenSoFar = max(maxSeenSoFar, dp[i])
```

Space improved: no need o keep the dp arr.

### Code
```java
public int maxSubArray(int[] nums) {
    int[] dp = new int[nums.length];
    int maxSoFar = nums[0];
    dp[0] = nums[0]>0 ? nums[0] : 0;// ignoree first element if negative
    for(int i=1;i<dp.length;i++){
        dp[i] = Math.max(nums[i], dp[i-1]+nums[i]); // dp[i] = max sub array sum for all elements including ith element
        maxSoFar = Math.max(maxSoFar, dp[i]);
    }
    return maxSoFar;
}

```

### Divide and conquer approach to solve this: O(N lg N) time, O(lg N) complexity



### variant also report start end for max subarray sum

### Variant: Max subarray sum with subarrays size k.

#### Approach1: sliding window + prefix sums - O(n) time, O(n) space

Prefix sums can give us range-sum of any window of size k in O(1)
We iterate over all `n-k+1` windows and keep track of max.

#### Approach2: Sliding window with running sum (no prefix sums needed) - O(n) time, O(1) space


```java
  int k = 4;

  int presentSubArrayScore = 0;
  int maxSubArrayScore = 0;
  // initially min subarray score is sum of first window
  for(int i=0;i<k;i++) {
      maxSubArrayScore += cardPoints[i];
  }
  
  // find min subarray window
  for(int i=0;i<N;i++) {
      presentSubArrayScore += cardPoints[i]; // add contribution of element sliding in the window
      if(i >= k) {// we are sliding now
          presentSubArrayScore -= cardPoints[i-t]; // remove contribution of element sliding out
          if(presentSubArrayScore > maxSubArrayScore) { // keep track of max sum
              maxSubArrayScore = presentSubArrayScore;
          }
      }
  }

  return maxSubArrayScore;
```