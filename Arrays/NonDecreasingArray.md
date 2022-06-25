

##

Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if `nums[i] <= nums[i + 1]` holds for every i (0-based) such that (0 <= i <= n - 2).

Example 1:
```
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
```
Example 2:
```
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
```

Constraints:
```
n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105
```


## Test cases

```
[4,2,3]
[4,2,1]
[0,1,-1]
[3,2,4,3]
[2,4,2,3]
[3,4,2,3]
```

## Code

```java
// had to look at the solution/discuss section
class Solution {
    public boolean checkPossibility(int[] nums) {
        if(nums.length == 1) {
            return true;
        }
        
        int unsatisfiedCount =  0;
        // more than one element
        for(int i=0;i< nums.length - 1; i++) {// we look at current and the next
            if(nums[i] >= nums[i+1]) {// next element is not fine
                unsatisfiedCount++;
                // remember we have to make an increasing mountain range to satisfy non-decreasing:
                // we have two choices: either take current one down as the next dipped one
                // or left next dipped one up as the current one
                if(i > 0 && nums[i-1] > nums[i+1]) {// middle elements & if prev is greater than next (dip is really bad)
                    nums[i+1] = nums[i]; // make next same as current - lift next up
                } else {// non-middle elements or prev is less than or equal to next (meaning dip is not that bad, we can current can go down as the next dipped)
                    nums[i] = nums[i+1];// make current same as next - go down current
                }
            }
        }
        
        if(unsatisfiedCount>1){
            return false;
        } else {
            return true;
        }
    }
}
```