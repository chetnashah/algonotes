
##

https://leetcode.com/problems/move-zeroes/

##

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:
```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```
Example 2:
```
Input: nums = [0]
Output: [0]
 ```

Constraints:
```
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
```

## Code

```java
class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length == 1){
            return;
        }
        
        // count number of zeros
        int zeroCnt = 0;
        for(int i=0;i<nums.length;i++) {
            if(nums[i] == 0) {
                zeroCnt++;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<nums.length;i++){
            // trample in-place in order of observation
            if(nums[i]!=0) {
                nums[cnt++] = nums[i];
            }
        }
        // fill last all nums with zeros
        for(int i=nums.length-zeroCnt;i<nums.length;i++) {
            nums[i] = 0;
        }
        // System.out.println(Arrays.toString(nums));
    }    
}
```