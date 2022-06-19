
##

https://leetcode.com/problems/squares-of-a-sorted-array/

##

```java
class Solution {
    public int[] sortedSquares(int[] nums) {
        // we start from the middle element, i.e. nearest to zero,
        // and maintain two pointers - one for positive number, one for negative number
        // pick the number which has smaller absolute value and push it in a new array
        
        int smallestPosIdx = nums.length;// after the first el
        int smallestNegIdx = -1;// before last el
        int cnt =0;
        int[] ans = new int[nums.length];
        for(int i=0;i<nums.length;i++) {
            if(nums[i] == 0) {
                ans[cnt++] = nums[i];
            }
            if(nums[i] >0 && smallestPosIdx > nums.length-1) {
                smallestPosIdx = i;// update only once
            }
            if(nums[i]<0) {
                smallestNegIdx = i;
            }
        }
        
        // tricky part: take care of zeros, with lot of zeros or missing pos, neg numbers, edge cases can be tricky sometimes
        while(smallestNegIdx >=0 && smallestPosIdx <= nums.length-1) {
            int posIdxSquare = nums[smallestPosIdx] * nums[smallestPosIdx];
            int negIdxSquare = nums[smallestNegIdx] * nums[smallestNegIdx];
            if(posIdxSquare < negIdxSquare) {
                ans[cnt++]  = posIdxSquare;
                smallestPosIdx++;
            } else {
                ans[cnt++] = negIdxSquare;
                smallestNegIdx--;
            }
        }
        
        // fill in remaining elements
        if(smallestNegIdx>=0) {
            while(smallestNegIdx >=0) {
                ans[cnt++] = nums[smallestNegIdx] * nums[smallestNegIdx];
                smallestNegIdx--;
            }
        } else if( smallestPosIdx <= nums.length - 1) {
            while(smallestPosIdx <= nums.length - 1) {
                ans[cnt++] = nums[smallestPosIdx] * nums[smallestPosIdx];
                smallestPosIdx++;
            }
        }
        
        return ans;
    }
}
```