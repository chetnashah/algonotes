

##

https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

https://www.youtube.com/watch?v=mBk4I0X46oI

##

Given an integer array nums and an integer k, return true if it is possible to **divide this array into k non-empty subsets whose sums are all equal**.

**Note** - this is different than count subsets with sum k - [count num of subsets with sum k](../DynamicProgramming/NumberOfSubsetsWithSumK.md)

**Note** - here we partition, so each element must be exactly present in one subset and no more, no less.

if `k=2`, it is same problem as https://leetcode.com/problems/partition-equal-subset-sum/


Example 1:
```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```
Example 2:
```
Input: nums = [1,2,3,4], k = 3
Output: false
```

Constraints:
```
1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
```

## Test cases

```
[4,3,2,3,5,2,1]
4
[1,2,3,4]
3
[5,5,5,5,4,4,4,4,3,3,3,3]
4
[1,1,2,2,2]
4
[3,3,3,3,4]
4
[3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269]
5
[2240,3029,520,203,1908,505,2600,739,696,345,1197,76,394,2902,1276]
6
[114,96,18,190,207,111,73,471,99,20,1037,700,295,101,39,649]
4
[6,4,5,4,1,1,10,1,7,6,4,2,10,1,3,5]
10
```

## Backtracking idea 1 : O(k^n) solution

each element can go in any one of k subsets.
recursive solution

### Code

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        // we want k subsets with equal sum s
        int totalSum = 0;
        for(int i=0;i<nums.length;i++) {
            totalSum += nums[i];
        }
        
        // totalSum must be multiple of k, so that it can have all subsets with sum -> totalSum/k
        if(totalSum % k != 0) {
            return false;
        }
        
        int targetSumPerSubset = totalSum / k;
        
        // all elements must be less than or equal to targetSumPerSubset
        for(int i=0;i<nums.length;i++) {
            if(nums[i] > targetSumPerSubset) {
                return false;
            }
        }
        
        // subset sums array
        int[] subsets = new int[k];
        
        // sorting in reverse order so that larger nums appear first
        Arrays.sort(nums);
        Collections.reverse(Arrays.asList(nums));
        
        boolean ans = backtrackHelper(nums, 0, subsets, targetSumPerSubset, k);
        return ans;
    }
    
    boolean backtrackHelper(int[] nums, int idx, int[] subsetsums, int targetSumPerSubset, int k) {
        // termination condition, all elements have been put somewhere
        if(idx == nums.length) {
            boolean ans = true;
            for(int i=0;i<k;i++) {
                ans = ans && subsetsums[i] == targetSumPerSubset;
            }
            return ans;
        }
        
        
        boolean ans = false;
        for(int i=0;i<k;i++) {
            // make a choice (pruned)
            if(subsetsums[i] + nums[idx] <= targetSumPerSubset) {
                subsetsums[i] += nums[idx];
                ans = ans || backtrackHelper(nums, idx+1, subsetsums, targetSumPerSubset, k);
                // backtrack
                subsetsums[i] -= nums[idx];
            }
        }
        
        return ans;
    }
}
```

## Alternative recursion (n!)

### alternative recursion definition

`count` -  variable that counts how many subsets with a sum equal to the target we have made from our array
when `count` becomes `k - 1`, that means we have k equal sum subsets in our array.

If we reach the condition: `currentSum` equals `targetSum`, that means we made one subset with the target sum.
So now we can increment a `count` variable that counts how many subsets with a sum equal to the target we have made from our array, and reset `currentSum` to 0 for next subset.

```java
    // count is num of subsets already done with sum targetSumPerSubset
    // currentSum is running sum for current subset under consideration
    // taken[] tracks elements already taken for current or previous subsets
    boolean backtrackHelper(int[] nums, int count, int currentSum, int targetSumPerSubset, int k, boolean[] taken) {/*...*/}
```

### Code

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        // we want k subsets with equal sum s
        int totalSum = 0;
        for(int i=0;i<nums.length;i++) {
            totalSum += nums[i];
        }
        
        // totalSum must be multiple of k, so that it can have all subsets with sum -> totalSum/k
        if(totalSum % k != 0) {
            return false;
        }
        
        int targetSumPerSubset = totalSum / k;
        
        // all elements must be less than or equal to targetSumPerSubset
        for(int i=0;i<nums.length;i++) {
            if(nums[i] > targetSumPerSubset) {
                return false;
            }
        }
        
        // sort array in decreasing order - optimization for large elemnts up front
        Arrays.sort(nums);
        Collections.reverse(Arrays.asList(nums));
        
        // taken elements array
        boolean[] taken = new boolean[nums.length];
        
        boolean ans = backtrackHelper(nums,0, 0, targetSumPerSubset, k, taken);
        return ans;
    }
    
    // count is num of subsets already done with sum targetSumPerSubset
    // currentSum is running sum for current subset under consideration
    // taken[] tracks elements already taken for current or previous subsets
    boolean backtrackHelper(int[] nums, int count, int currentSum, int targetSumPerSubset, int k, boolean[] taken) {
        
        // we made k-1 subsets with sum equal to targetSumPerSubset
        // last one will also have targetSumPerSubset, because we did divisibility check
        if(count == k-1) {
            return true;       
        }
        
        // currentSum same as targetSumPerSubset, increase satisfied count, and reset currentSum
        if(currentSum == targetSumPerSubset) {
            return backtrackHelper(nums, count+1, 0, targetSumPerSubset, k, taken);
        }
        
        // currentSum is not same as targetSumPerSubset
        // try some non-taken elements to do so
        for(int i=0;i<nums.length;i++){
            if(!taken[i]) {
                taken[i] = true;
                // prune and backtrack/recurse
                if(currentSum+nums[i] <= targetSumPerSubset && backtrackHelper(nums, count, currentSum + nums[i], targetSumPerSubset, k, taken)){
                    return true;
                }
                // backtrack
                taken[i] = false;
            }
        }
        return false;
    }
}
```

## Improvement in alternative recursion (O(k * 2^n))

Instead of starting our search for each element to include from the 0th index, again and again, we can continue the search from the last picked element, for current subset sum. 

When a subset is completed, only then will we start the search from the 0th `index`, as we can now include the previously skipped elements in new subsets.

This idea to similar in subset sum, where we move index ahead after deciding to pick/not pick each element.

### Add an index in backtrack state definition

```java
    // can we satisfy k-1 counts of targetSum, starting & including picking elems at index idx, and current sum currSum with given taken configuration. 
private boolean backtrack(int[] arr, int index, int count, int currSum, int k, 
                            int targetSum, boolean[] taken) {
                                //...
}
```

Here we will **see two loops**: 
1. one loop is recursive `index` picking a subset from the list and marking it as taken.
2. Another outer for-loop `j` by backtracking, takes first non-taken elements and tries finding a subset in list, starting at it by following step 1.

### Code 

```java
class Solution {
    // can we satisfy k-1 counts of targetSum, starting & including picking elems at index idx, and current sum currSum with given taken configuration. 
    private boolean backtrack(int[] arr, int index, int count, int currSum, int k, 
                              int targetSum, boolean[] taken, int nestCnt) {

        int n = arr.length;
      
        String padding = String.join("", Collections.nCopies(nestCnt, " "));

        System.out.println(padding+"0 invoke: " + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + Arrays.toString(taken));

        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            System.out.println(padding + "1 ans = true "  + "index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + Arrays.toString(taken));

            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            System.out.println(padding + "2 ans = false "  + "index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + Arrays.toString(taken));
            return false;
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            boolean ans = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, nestCnt+1);
            System.out.println(padding+"3 ans = "+ ans  + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + Arrays.toString(taken));
            return ans;
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            System.out.println(padding+"index = "+index + " j = "+ j);
            if (!taken[j]) {
                // Include this element in current subset.
                taken[j] = true;
                System.out.println(padding+"selecting/taking elem j = " + j + " value = " + arr[j]);
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, nestCnt+1)) {
                    System.out.println(padding+"4 ans = true" + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + Arrays.toString(taken));
                    return true;
                }
                
                System.out.println(padding+"un-select/un-take elem j = " + j + " value = " + arr[j]);
                // Backtrack step.
                taken[j] = false;
            } else {
                System.out.println(padding+ "j " + j + " was taken so ignoring ");
            }
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        System.out.println(padding+"5 ans = false" + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + Arrays.toString(taken));
        return false;
    }
    
    void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) { 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        // Sort in decreasing order.
        Arrays.sort(arr);
        reverse(arr);
        
        System.out.println("array starting = " + Arrays.toString(arr));
        
        int targetSum = totalArraySum / k;
        System.out.println("targetSum = "+targetSum);
        boolean[] taken = new boolean[n];
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken, 1);
    }
}
```


### sample trace

trace
```
array starting = [5, 4, 3, 3, 2, 2, 1], total = 20, k = 4
targetSum = 5
 0 invoke:  index = 0 currSum = 0 count = 0 taken = [false, false, false, false, false, false, false]
 index = 0 j = 0
 selecting/taking elem j = 0 value = 5
  0 invoke:  index = 1 currSum = 5 count = 0 taken = [true, false, false, false, false, false, false]
   0 invoke:  index = 0 currSum = 0 count = 1 taken = [true, false, false, false, false, false, false]
   index = 0 j = 0
   j 0 was taken so ignoring 
   index = 0 j = 1
   selecting/taking elem j = 1 value = 4
    0 invoke:  index = 2 currSum = 4 count = 1 taken = [true, true, false, false, false, false, false]
    index = 2 j = 2
    selecting/taking elem j = 2 value = 3
     0 invoke:  index = 3 currSum = 7 count = 1 taken = [true, true, true, false, false, false, false]
     2 ans = false index = 3 currSum = 7 count = 1 taken = [true, true, true, false, false, false, false]
    un-select/un-take elem j = 2 value = 3
    index = 2 j = 3
    selecting/taking elem j = 3 value = 3
     0 invoke:  index = 4 currSum = 7 count = 1 taken = [true, true, false, true, false, false, false]
     2 ans = false index = 4 currSum = 7 count = 1 taken = [true, true, false, true, false, false, false]
    un-select/un-take elem j = 3 value = 3
    index = 2 j = 4
    selecting/taking elem j = 4 value = 2
     0 invoke:  index = 5 currSum = 6 count = 1 taken = [true, true, false, false, true, false, false]
     2 ans = false index = 5 currSum = 6 count = 1 taken = [true, true, false, false, true, false, false]
    un-select/un-take elem j = 4 value = 2
    index = 2 j = 5
    selecting/taking elem j = 5 value = 2
     0 invoke:  index = 6 currSum = 6 count = 1 taken = [true, true, false, false, false, true, false]
     2 ans = false index = 6 currSum = 6 count = 1 taken = [true, true, false, false, false, true, false]
    un-select/un-take elem j = 5 value = 2
    index = 2 j = 6
    selecting/taking elem j = 6 value = 1
     0 invoke:  index = 7 currSum = 5 count = 1 taken = [true, true, false, false, false, false, true]
      0 invoke:  index = 0 currSum = 0 count = 2 taken = [true, true, false, false, false, false, true]
      index = 0 j = 0
      j 0 was taken so ignoring 
      index = 0 j = 1
      j 1 was taken so ignoring 
      index = 0 j = 2
      selecting/taking elem j = 2 value = 3
       0 invoke:  index = 3 currSum = 3 count = 2 taken = [true, true, true, false, false, false, true]
       index = 3 j = 3
       selecting/taking elem j = 3 value = 3
        0 invoke:  index = 4 currSum = 6 count = 2 taken = [true, true, true, true, false, false, true]
        2 ans = false index = 4 currSum = 6 count = 2 taken = [true, true, true, true, false, false, true]
       un-select/un-take elem j = 3 value = 3
       index = 3 j = 4
       selecting/taking elem j = 4 value = 2
        0 invoke:  index = 5 currSum = 5 count = 2 taken = [true, true, true, false, true, false, true]
         0 invoke:  index = 0 currSum = 0 count = 3 taken = [true, true, true, false, true, false, true]
         1 ans = true index = 0 currSum = 0 count = 3 taken = [true, true, true, false, true, false, true]
        3 ans = true index = 5 currSum = 5 count = 2 taken = [true, true, true, false, true, false, true]
       4 ans = true index = 3 currSum = 3 count = 2 taken = [true, true, true, false, true, false, true]
      4 ans = true index = 0 currSum = 0 count = 2 taken = [true, true, true, false, true, false, true]
     3 ans = true index = 7 currSum = 5 count = 1 taken = [true, true, true, false, true, false, true]
    4 ans = true index = 2 currSum = 4 count = 1 taken = [true, true, true, false, true, false, true]
   4 ans = true index = 0 currSum = 0 count = 1 taken = [true, true, true, false, true, false, true]
  3 ans = true index = 1 currSum = 5 count = 0 taken = [true, true, true, false, true, false, true]
 4 ans = true index = 0 currSum = 0 count = 0 taken = [true, true, true, false, true, false, true]
```

### Repeating subproblems in trace w.r.t taken 

Find many repeating subproblems in [repeating subproblems](./partitiontoksubsetswithequalsumtrace.txt)

e.g. search `0111111100111111` in that file

### Accepted (taken configuration memoization)

```java
class Solution {
    
    HashMap<String, Boolean> memo;
    
    // can we satisfy k-1 counts of targetSum, starting & including picking elems at index idx, and current sum currSum with given taken configuration. 
    private boolean backtrack(int[] arr, int index, int count, int currSum, int k, 
                              int targetSum, char[] taken, int nestCnt) {

        int n = arr.length;
      
        String padding = String.join("", Collections.nCopies(nestCnt, " "));

        // System.out.println(padding+"0 invoke: " + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + new String(taken));

        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            // System.out.println(padding + "1 ans = true "  + "index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + new String(taken));
            memo.put(new String(taken), true);
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            // System.out.println(padding + "2 ans = false "  + "index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + new String(taken));
            memo.put(new String(taken), false);
            return false;
        }
      
        if(memo.containsKey(new String(taken))){
            return memo.get(new String(taken));
        }
        
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            boolean ans = backtrack(arr, 0, count + 1, 0, k, targetSum, taken, nestCnt+1);
            // System.out.println(padding+"3 ans = "+ ans  + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + new String(taken));
            memo.put(new String(taken), ans);
            return ans;
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            // System.out.println(padding+"index = "+index + " j = "+ j);
            if (taken[j] == '0')  {
                // Include this element in current subset.
                taken[j] = '1';
                // System.out.println(padding+"selecting/taking elem j = " + j + " value = " + arr[j]);
                // If using current jth element in this subset leads to make all valid subsets.
                if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken, nestCnt+1)) {
                    // System.out.println(padding+"4 ans = true" + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + new String(taken));
                    memo.put(new String(taken), true);
                    return true;
                }
                
                // System.out.println(padding+"un-select/un-take elem j = " + j + " value = " + arr[j]);
                // Backtrack step.
                taken[j] = '0';
            } 
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        // System.out.println(padding+"5 ans = false" + " index = "+index + " currSum = "+currSum + " count = "+ count + " taken = " + new String(taken));
        memo.put(new String(taken), false);
        return false;
    }
    
    void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) { 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
  
    public boolean canPartitionKSubsets(int[] arr, int k) {
        int totalArraySum = 0;
        int n = arr.length;
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }
      
        memo = new HashMap<>();
        // Sort in decreasing order.
        Arrays.sort(arr);
        reverse(arr);
        
        // System.out.println("array starting = " + Arrays.toString(arr));
        
        int targetSum = totalArraySum / k;
        // System.out.println("targetSum = "+targetSum);
        char[] taken = new char[n];
        for(int i=0;i<n;i++) {
            taken[i] = '0';
        }
        return backtrack(arr, 0, 0, 0, k, targetSum, taken, 1);
    }
}
```

## Better recursion - O(k * 2^n)

### targetSumPerSubset = total/k

### Core idea 1 : find subset with sum targetSumPerSubset (O(2^n)) and remove it from original set

### repeat this step for k times, at the end we must have empty set

### TODO code



### Code

```java

```