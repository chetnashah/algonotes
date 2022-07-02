
##

https://leetcode.com/problems/search-insert-position/

##

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.


Example 1:
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```
Example 2:
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```
Example 3:
```
Input: nums = [1,3,5,6], target = 7
Output: 4
 ```

Constraints:
```
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
```

## Logic

Refer [Logic](README.md)

## Code

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        return bsearch(0, nums.length-1, nums, target);
    }
    
    public int bsearch(int lo, int hi, int[] nums, int target) {
        while(lo<hi) {
            int mid = lo + (int)Math.floor((hi - lo)/2);
            
            int midEl = nums[mid];
            if(midEl >= target) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        
        if(lo == nums.length-1 && nums[nums.length-1] < target) {
            return nums.length;
        }
        if(lo == 0 && nums[0] > target) {
            return 0;
        }
        return lo;
    }
}
```