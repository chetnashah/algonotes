

##

https://leetcode.com/problems/max-consecutive-ones-ii/

##

Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

 

Example 1:
```
Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
```
Example 2:
```
Input: nums = [1,0,1,1,0,1]
Output: 4
 ```

Constraints:
```
1 <= nums.length <= 105
nums[i] is either 0 or 1.
```

## Bi directional dp (Prefix sums from left, and prefix sums from right)

Calculate prefix sums from left and right, reset when you encounter 0.

At each zero, consider max available from both sums to the left or right of a zero, and add 1

## Important edge case: check all 1s

## Code

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
     
        if(nums.length == 1) {
            return 1;
        }
        
        int[] prefixSumFromLeft = new int[nums.length];
        int[] prefixSumFromRight = new int[nums.length];
        
        
        prefixSumFromLeft[0] = nums[0];
        for(int i=1;i<nums.length;i++) {
            if(nums[i] == 0) {
                prefixSumFromLeft[i] = 0;
            } else {
                prefixSumFromLeft[i] += prefixSumFromLeft[i-1] + 1;
            }
        }
        
        // System.out.println(prefixSumFromLeft);
        prefixSumFromRight[nums.length-1] = nums[nums.length-1];
        for(int i=nums.length-2;i>=0;i--) {
            if(nums[i] == 0) {
                prefixSumFromRight[i] = 0;
            } else {
                prefixSumFromRight[i] += prefixSumFromRight[i+1] + 1;
            }
        }
        // System.out.println(prefixSumFromRight);

        
        int maxSeen = 0;
        for(int i=0;i<nums.length;i++) {
            if(nums[i] == 0) {
                if(i == 0) {
                    int ans = Math.max(prefixSumFromLeft[1], prefixSumFromRight[1]) + 1;
                    maxSeen = Math.max(maxSeen, ans);
                } else if (i == nums.length - 1) {
                    int ans = Math.max(prefixSumFromLeft[i-1], prefixSumFromRight[i-1]) + 1;
                    maxSeen = Math.max(maxSeen, ans);
                } else { // middle numbers
                    maxSeen = Math.max(maxSeen, prefixSumFromLeft[i-1] + prefixSumFromRight[i+1] + 1);
                }
            }
        }
        
        // edge case all 1s
        return maxSeen == 0 ? nums.length : maxSeen;
    }    
}
```


