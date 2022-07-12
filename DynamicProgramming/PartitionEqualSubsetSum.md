
##

https://leetcode.com/problems/partition-equal-subset-sum/

## TODO write bottom up dp iteration

## TODO 1 d array dp



## Code

```java
class Solution {
    int[][] memo;
    public boolean canPartition(int[] nums) {
        int total = 0;
        for(int i=0;i<nums.length;i++) {
            total += nums[i];
        }
        
        if(total %2 != 0) {
            return false;
        }
        
        int targetSum = total/2;
        
        for(int i=0;i<nums.length;i++) {
            if(nums[i] > targetSum) {
                return false;
            }
        }
        
        memo = new int[201][20001];
        for(int i=0;i<201;i++) {
            for(int j=0;j<20001;j++) {
                memo[i][j] = -1;
            }
        }
        
        // if we can find one subset, the other one has to be present as well
        return canHaveCapacity(nums, 0, targetSum);
        
    }
    
    boolean canHaveCapacity(int[] nums, int idx, int capacity) {
        // System.out.println("idx = " + idx + " capacity = " + capacity);
        if(capacity == 0) {
            memo[idx][capacity] = 1;
            return true;
        }
        if(capacity < 0) {
            // memo[idx][capacity] = 0;
            return false;
        }
        if(idx == nums.length && capacity > 0) {
            memo[idx][capacity] = 0;
            return false;
        }
        
        // capacity greater than 0
        if(memo[idx][capacity] != -1) {
            return memo[idx][capacity] == 1 ? true : false;
        }
        
        boolean withInclude = canHaveCapacity(nums, idx+1, capacity-nums[idx]);
        boolean withNotInclude = canHaveCapacity(nums,idx+1, capacity);
        
        if(withInclude || withNotInclude) {
            memo[idx][capacity] = 1;
            return true;
        } else {
            memo[idx][capacity] = 0;
            return false;
        }
    }
}
```