

##

Find four elements in an array that sum to a given target

https://leetcode.com/problems/4sum/

##

Given an array nums of n integers, return an array of all the unique quadruplets `[nums[a], nums[b], nums[c], nums[d]` such that:
```
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
```
You may return the answer in any order.

## Test cases

Example 1:
```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```
Example 2:
```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```

## Constraints

```
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
```

## Note: all indices must be distinct, and the numbers themselves in answer must also be distinct

## Things I tried

### Dividing into two sets - first half, and second half

There would be following sub-cases:
1. 2 elements in first half, 2 elements in second half
2. 1 element in first half, 3 elements in second half
3. 3 elements in first half, 1 element in second half
4. all elements in first half, no elements in second half
5. no elements in first half, all elements in second half

## O (N^3), just build on top of O(N^2) twosum.

In general `KSum` can be done in O(N^(k-1)), if `k` is arbitrary and coming from input, it can be done via recursion.

## Problem variant : a,b,c,d do not need to be distinct, nums.length = 10^9

