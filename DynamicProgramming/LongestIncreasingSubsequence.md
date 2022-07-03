
https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

https://www.youtube.com/watch?v=cjWnW0hdF1Y (top down - )

## Two variations, just get length vs printing longest increasing subsequence

## Variation: count number of LIS 

https://leetcode.com/problems/number-of-longest-increasing-subsequence/

### Tricky bits 1: there can many ways to form intermediate subsequence lengths

### there can be more than one independent same length longest increasing subsequences

Edge cases:
```
[1,3,5,4,7]
[2,2,2,2,2]
[1,2,4,3,5,4,7,2]
[1,3,2]
[3,2,1]
[1,2,3,1,2,3,1,2,3]
[84,-48,-33,-34,-52,72,75,-12,72,-45]
```

### Code

```java
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        
        int[] count = new int[n];
        Arrays.fill(count, 1);
        
        int maxi = 1;
        
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                
                // firs time max
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    
                    // Inherit
                    count[i] = count[prev];
                }
                // same as existing max, increase count
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
                    
                    // Increase the count
                    count[i] += count[prev];
                }
            }
            
            maxi = Math.max(maxi, dp[i]);
        }
        
        int countLIS = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                countLIS += count[i];
            }
        }
        
        return countLIS;
    }
}
```

## Longest increasing subsequence length

### DP state

`dp[i] = longest length increasing subsequence upto and including ith element`.

### DP reucrrence idea

Look back to every element that is smaller than us, 
pick one with best subeq count and increment 1.


if all previous entries are larger than current element, `LIS[i] = 1`
else `LIS[i] = 1 + Max[LIS[j]] such that j < i and A[j] < A[i]`

### code

```cpp
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1);// initially all lengths 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {// among previous lower elements
                d[i] = max(d[i], d[j] + 1); // pick the one with best outcome
            }
        }
    }

    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i]);
    }
    return ans;
}
```

This approach takes O(N^2) time

## LIS in O(N lg N)

https://www.youtube.com/watch?v=S9oUiVYEq7E
https://www.youtube.com/watch?v=on2hvxBXJH4
https://www.youtube.com/watch?v=66w10xKzbRM

## LIS via DFS + cache

