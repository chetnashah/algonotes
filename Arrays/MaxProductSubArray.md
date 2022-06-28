

##

https://leetcode.com/problems/maximum-product-subarray/

##

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
 

Example 1:
```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```
Example 2:
```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 ```

Constraints:
```
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
```

## Note

Note that array can contain negative numbers!

## Brute force approach - O(N^3)

Try all subarrays -> O(N^2) and calculate product of it -> O(n) and keep track of max

## Brute force pairs + Prefix mult improves brute force by moving from O(N^3) -> O(n^2), by allowing range products in O(1) instead of O(n)

O(N^2)

## What does not work

### Kadanes algorithm does not work

e.g.
`[2,3,-2,4, -2]`, kadanes would report `[2,3]` as largest subarray product, but whole array results in final positive ans.

### Prefix mult

If we take 
`[-1,2,3,4]` ->
Prefix mult will have
`[-1,-2,-6, -24]` , and we dont have any answer
where the answer should have been 24.

### Prefix mult from both sides

Breaks down for this test case: `[0,2]` -> `[0,0]` and `[0,2]`

and `[-3,0,1,-2]` -> left side prefix Mult: `[-3,0,0,0]` and right side prefix mult: `[0,0,-2,-2]` 

This is because 0 will put holes in the logic,  there can be some subarrays between 0 that can multiply to larger numbers.

## Observation: we improve upon prefix mult from both sides (bidirectional DP), by using kadane style reset whenever a 0 is seen.

e.g. taking above example
and `[-3,0,1,-2]` -> left side prefix Mult: `[-3,0,0,0]` and right side prefix mult: `[0,0,-2,-2]` 

We improve this by resetting multprefix, whenever we see a 0.
left prefix: `[-3,0,1,-2]` -> `[-3, 0, 1, -2]`
right prefix: `[-3,0,1,-2]` -> `[-3, 0, -1, -2]`

The max in both arrays is the answer.

### Code

```java
class Solution {
    public int maxProduct(int[] nums) {
        int[] maxProductFromFront = new int[nums.length];
        int[] maxProductFromEnd = new int[nums.length];
        
        int maxSeenSoFar;
        
        maxProductFromFront[0] = nums[0];
        maxSeenSoFar = nums[0];
        // prefix mult from left end
        for(int i=1;i<nums.length;i++) {
            if(nums[i-1] == 0) {// kadane style reset, if prev was a 0.
                maxProductFromFront[i] = nums[i];
            } else {
                maxProductFromFront[i] = nums[i]*maxProductFromFront[i-1]; 
            }
            
            if(maxProductFromFront[i] > maxSeenSoFar) {
                maxSeenSoFar = maxProductFromFront[i];
            }
        }
        
        // prefix mult from right end
        maxProductFromEnd[nums.length-1] = nums[nums.length - 1];
        maxSeenSoFar = Math.max(maxSeenSoFar, nums[nums.length - 1]);
        for(int i=nums.length-2;i>=0;i--) {
            if(nums[i+1] == 0) { // kadane style reset, 0 results in bad mults
                maxProductFromEnd[i] = nums[i];
            } else {
                maxProductFromEnd[i] = nums[i]*maxProductFromEnd[i+1];
            }
            if(maxProductFromEnd[i] > maxSeenSoFar) {
                maxSeenSoFar = maxProductFromEnd[i];
            }
        }
        
        return maxSeenSoFar;
    }
}
```

## Variation: report index range of max subarray product





