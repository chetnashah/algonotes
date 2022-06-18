
##

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`, i.e. they sum together to 0.

**Notice that the solution set must not contain duplicate triplets.**

##

Example 1:
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
```
Example 2:
```
Input: nums = []
Output: []
```
Example 3:
```
Input: nums = [0]
Output: []
```

## Constraints
```
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
```

## Things to be aware of:

If numbers are duplicated, in the array, we can have many index triplets, that satisfy the sum, we must ignore those..

### OBservation 1: since the final sum needs to be zero, it is guaranteed that some of the numbers will be negative.

## Brute force approach - 3 variables - O(n^3)

## Improved approach : N^2:

### Sort the array first

Original array:
| -1  | 0   | 1   | 2   | -1  | -4  |
|:---:|:---:|:---:|:---:|:---:|:---:|

After sorting:
| -4  | -1  | -1  | 0   | 1   | 2   |
|:---:|:---:|:---:|:---:|:---:|:---:|

### For every a, we find `b` and `c` in the remaining array using (two pointers for 2sum sorted) technique

To understand the 2Sum sorted technique in O(N) refer [2Sum sorted](2SumSorted.md)

| -4  | -1   | -1  | 0   | 1   | 2   |
|:---:|:---: |:---:|:---:|:---:|:---:|
| a   | b -> |     |     |     | <- c|

We use two pointer technique so that sum `b+c` is `-a`

### Pointer update conditions

1. if `b+c` is less than `-a`, increment `b`.
2. If `b+c` is greater than `-a`, decrement `c`.

As soon as you find that `b+c` is `-a`, report the answer.

### implementation considerations
Before deciding `a`, see if it is same as previous, then ignore it, because it will result in duplicate triplets

e.g. in further iterations:
| -4  | -1   | -1  | 0   | 1   | 2   |
|:---:|:---: |:---:|:---:|:---:|:---:|
|     | a    | b ->|     |     | <- c|

and in next iteration, we skip starting with `a = -1`, because we have already calculated everything for `a = -1` in previous step:
| -4  | -1   | -1  | 0   | 1   | 2   |
|:---:|:---: |:---:|:---:|:---:|:---:|
|     |      | X   | a   | b ->| <- c|


