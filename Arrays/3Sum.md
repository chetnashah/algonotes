
##

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`, i.e. they sum together to 0.

**Notice that the solution set must not contain duplicate triplets, and the indices themselves must also be different**

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

**One of the reasons for sorting is to skip repeated values.**

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

* Make sure `b` and `c` are within bounds

* sometimes b can also repeat e.g. in case `[0,0,0,0]`. when you have 0 sum, skip same `b`s.

### Interesting test cases:

Input : `[0,0,0,0]`
Output: `[[0,0,0]]`

### Code

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        if(nums.length == 0 || nums.length == 1 || nums.length == 2)  {
            return ans;
        }
        
        Arrays.sort(nums);
        System.out.println(Arrays.toString(nums));
        
        /*
        | -4  | -1   | -1  | 0   | 1   | 2   |
        | a   | b -> |     |     |     | <- c|
        */
        for(int a=0;a<nums.length-2;a++) {
            if(a>0 && nums[a] == nums[a-1]) {// ignore a's which are already previously considered to avoid duplicates
                continue;
            }
            int b = a+1;
            int c = nums.length - 1;
            // System.out.println("a = " + a + " b = " + b + " c = " + c);
            while(b<c) {
                if(nums[b] + nums[c] > -1 * nums[a]) {
                    c--;
                } else if(nums[b] + nums[c] < -1 * nums[a]) {
                    b++;
                } else {
                    // same
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(nums[a]);
                    triplet.add(nums[b]);
                    triplet.add(nums[c]);
                    ans.add(triplet);
                    b++;
                    while(b < nums.length-1 && nums[b] == nums[b-1]) {// skip same b's when we have zero sum since they will contribute to duplicate answer
                        b++;
                    }
                }
                // System.out.println("inner a = "+a +" b = "+b + " c = "+c);
            }
        }
        return ans;
    }
}
```


## How to do it without sorting?

Check here: https://leetcode.com/problems/3sum/solution/
