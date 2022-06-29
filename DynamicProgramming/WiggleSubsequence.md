
##

https://leetcode.com/problems/wiggle-subsequence/

##

A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, `[1, 7, 4, 9, 2, 5]` is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.

In contrast, `[1, 4, 7, 2, 5]` and `[1, 7, 4, 5, 5]` are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.
 

Example 1:
```
Input: nums = [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
```
Example 2:
```
Input: nums = [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
```
Example 3:
```
Input: nums = [1,2,3,4,5,6,7,8,9]
Output: 2
 ```

Constraints:
```
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
```



## Normal approach: check against previous items to find first small/greater

This approach seems fine but breaks down in very edge cases.

## Failing test case:


```
[98,3,30,60,3,68,82]
```

Debug output gavE:
```
prevGreaterIdx = [-1, 0, 0, 0, 3, 0, 0]
prevSmallerIdx = [-1, -1, 1, 2, -1, 4, 5]
ans dp = 
1 1 
1 2 
3 2 
3 2 
1 4 
5 2  // answer is here, so we must check all numbers in dp
3 2 
```

Still giving wrong answer:
```
[40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15]
```

```
[40,32,48,50,76,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15]
```

```
[40,32,48,50,76,9,79,18,97,67,23,52,38,74,15]
```

```
[40,32,48,50,76,9,79,18,97] -> expected 7, output 6
```

```
[40,32,48,50,76,9] -> expected 4 output 3

prevGreaterIdx = [-1, 0, -1, -1, -1, 4]
prevSmallerIdx = [-1, -1, 1, 2, 3, -1]
 1 1
 1 2
 3 1
 2 1
 2 1
 1 3
```

**Why**?
when we check 9, it picks `50 <- 76 <- 9`
instead of picking `40 <- 32 <- 48 <- 9` which gives better answer.

So nearest smaller/larger previous number is not useful.

## Alternative approach, check all previous to get better estimate

DP state = 
`ans[i][0]` = longest wiggle length upto i, with smaller prev
`ans[i][1]` = longest wiggle length upto i, with larger prev

```java
class Solution {
    public int wiggleMaxLength(int[] nums) {
                
        // now fill the dp table
        int[][] ans = new int[nums.length][2];
        
        // ans[i][0] = longest wiggle length upto i, with smaller prev
        // ans[i][1] = longest wiggle length upto i, with larger prev
        ans[0][0] = 1;
        ans[0][1] = 1;
        
        int maxSeen = 1;
        for(int i=1;i<nums.length;i++) {
            int bestSeqLengthPrevSmaller = 1;
            int bestSeqLengthPrevLarger = 1;
            for(int j=i-1;j>=0;j--) {// look at all previous members
                if(nums[j] < nums[i]) {
                    bestSeqLengthPrevSmaller = Math.max(bestSeqLengthPrevSmaller, 1+ ans[j][1]);
                } else if (nums[j] > nums[i]) {
                    bestSeqLengthPrevLarger = Math.max(bestSeqLengthPrevLarger, 1+ ans[j][0]);
                }
            }
            ans[i][0] = bestSeqLengthPrevSmaller;
            ans[i][1] = bestSeqLengthPrevLarger;
        }
        
        for(int i=0;i<nums.length;i++) {
            for(int j=0;j<2;j++) {
                maxSeen = Math.max(maxSeen, ans[i][j]);
            }
        }
        
        return maxSeen;
    }
}
```

## TODO other approach analysis



## Linear time dynamic programming - O(n) time and O(n) space

Maintain two arrays `up[i]` and `down[i]`.

Proof: ? TODO

Initialize with `up[0] = down[0] = 1`.

### Case 1: no wiggle: nums[i] == nums[i-1]

```java
up[i] = up[i-1];
down[i] = down[i-1];
```

### Case 2: down wiggle: nums[i] < nums[i-1]

```java
down[i] = up[i - 1] + 1;// note opposite side
up[i] = up[i - 1];
```

### Case 3: up wiggle

```java
up[i] = down[i - 1] + 1;// note opposite side
down[i] = down[i - 1];
```

## Greedy approach - O(n) time and O(1) space

This problem is equivalent to finding the number of alternating max. and min. peaks in the array.

Proof: ?



