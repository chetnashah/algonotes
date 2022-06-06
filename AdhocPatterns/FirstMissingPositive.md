

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in `O(n)` time and uses constant extra space.

`Note`: 0 is not considered positive integer.

Example 1:
```
Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
```

## Base case

Do an array run, to see if we have any `1`s, if no 1s were found, we just return 1 as answer.
If atleast a single 1 was found, we do further computation.

## Imp Observation 1: first missing positive number must be smaller or equal to n + 1

### Proof

`case 1`: If all numbers are larger than n, 1 is the first missing positive number.
`case 2`: We have all numbers from 1 to n, then smallest missing positive number is `n+1`.
`case 3`: some numbers from 1 to n are missing, then smallest missing positive number must be between 1 and n.

## Based on observation 1, we can get rid of numbers larger than n+1

## Also get rid of -ve numbers, or 0, since they cannot be answer

## We get rid of -ve numbers, 0 and numbers larger than n+1, by replacing them with 1s

### Why replace with 1s?

In cases, where we have all numbers 0, or negative or larger than n+1s, we have already checked for 1s in base case, 
we can repeat it for marking.
`Note`: Before doing this, you must have a base case:
```java
        // Base case.
        int contains = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == 1) {
                contains++;
                break;
            }

        if (contains == 0)
            return 1;

        // data cleanup code
```

## Default approach (hashmap) - O(n) space

count all occurrences in Treemap
iterate treemap in order, and find first positive integer without count.

## We will do one pass through array and mark elment indexes as visited by making them negative

e.g. 
|`arr[i]`                  |  3  |  4  | -1  |  1  |
|:---:                     |:---:|:---:|:---:|:---:|
|data cleanup              |  3  | 4   | 1   |  1  |
|`arr[arr[i]-1]` mark -ve  | -3  |  4  |  -1 | -1  |

Ans = First-non-negative-index + 1 = 1 + 1 = 2

## One more pass through array to find first non-negative entry tells us first missing positive number

Lets consider case where we have 1 to n in array

|`arr[i]`                  |  1  |  2  | 3   |  4  |
|:---:                     |:---:|:---:|:---:|:---:|
|`arr[arr[i]-1]` mark -ve  | -1  |  -2  | -3 | -4  |

In this case our index runs pass through i.e. i = 4 + 1 = 5 as expected.

## Code

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        // Base case.
        int contains = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                contains++;
                break;
            }
        }

        if (contains == 0)
            return 1;


        // atleast one 1 was present, now it is safe to do data cleanup with 1s
        for(int i=0;i<nums.length;i++) {            
            if(nums[i] <= 0 || nums[i] > nums.length) {
                nums[i] = 1;
            }
        }
        
        int i=0;
        while(i<nums.length) {// going through the whole array
            if(nums[i] > 0) {
                int nextIdx = nums[i];
                while(nums[nextIdx - 1] > 0) {// keep seiving and negating
                    int tmp = nextIdx;
                    nextIdx = nums[nextIdx-1];
                    nums[tmp -1] = -1 * nums[tmp -1];
                }
            }
            i++;
        }
        
        int ans=0;
        for(ans =0;ans<nums.length;ans++) {
            if(nums[ans] > 0) {
                break;
            }
        }
        
       // System.out.println(Arrays.toString(nums));
        return ans+1;
    }
}
```