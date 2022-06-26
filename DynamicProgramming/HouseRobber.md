
##

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

##

Example 1:
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:
```
```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

Constraints:
```
1 <= nums.length <= 100
0 <= nums[i] <= 400
```

## Code

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        if(nums.length == 1) {
            return nums[0];
        }
        
        int[] bestMoney = new int[nums.length];
        
        bestMoney[0] = nums[0];
        for(int i=1;i<nums.length;i++) {
            bestMoney[i] = Math.max(bestMoney[i-1],(i-2 >= 0 ? bestMoney[i-2] : 0) +nums[i]);// either we select previous and not select current, or we select current and one before
        }
        
        return bestMoney[nums.length - 1];
    }
}
```

### Recursive with memo code

```java
class Solution {
    int[] ans;
    public int rob(int[] nums) {
        
        if(nums.length == 1) {
            return nums[0];
        }
        
        ans = new int[nums.length];
        for(int i=0;i<nums.length;i++) {
            ans[i] = -1;
        }
        
        ans[0] = nums[0];
        ans[1] = Math.max(nums[0], nums[1]);
        
        return robAtIdx(nums.length-1, nums);
    }
    
    int robAtIdx(int idx, int[] nums) {
        // check memo
        if(ans[idx] != -1) {
            return ans[idx];
        }
        
        // rob at this indx
        int ans1 = nums[idx] + robAtIdx(idx-2, nums);
        // do not rob at this idx
        int ans2 = robAtIdx(idx-1, nums);
        
        int finalAns = Math.max(ans1, ans2);
        ans[idx] = finalAns;
        return ans[idx];
    }
}
```

## House robber but in a circle

In a circle, `1` and `n-1` cannot be chosen together so pick better of `robMax([1..n-2])` or `robMax([2..n-1])`

Slightly tricky impl because using same array, can be simplified if we run above procedure on two different arrays:
```java
class Solution {
    static int[] ans;
    public int rob(int[] nums) {
        // 1 and n-1 cannot be chosen together 
        // so pick better of [1..n-2] or [2..n-1]
        
        if(nums.length == 1) {
            return nums[0];
        }
        
        if(nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        
        int n = nums.length;
        ans = new int[n];
        for(int i=0;i<nums.length;i++) {
            ans[i] = -1;
        }
        
        
        int firstRange = robAtIdx(n-2, nums, true);
        
        // clear again
        for(int i=0;i<nums.length;i++) {
            ans[i] = -1;
        }

        int secondRange = robAtIdx(n-1, nums, false);
        
        return Math.max(firstRange, secondRange);
    }
    
    int robAtIdx(int idx, int[] nums, boolean firstPickAllowed) {
        if(ans[idx] != -1) {
            return ans[idx];
        } 
        if(idx == 0 && firstPickAllowed) {
            return nums[0];
        } else if(idx == 0 && !firstPickAllowed) {
            return 0;
        }
        if(idx == 1 && firstPickAllowed) {
            return Math.max(nums[0], nums[1]);
        } else if ( idx == 1 && !firstPickAllowed) {
            return nums[1];
        }
        
        //pick at idx
        int ans1 = nums[idx] + robAtIdx(idx-2, nums, firstPickAllowed);
        
        // not pick at idx
        int ans2 = robAtIdx(idx-1, nums, firstPickAllowed);
        
        // memo and return
        ans[idx] = Math.max(ans1, ans2);
        return ans[idx];
    }   
}
```
