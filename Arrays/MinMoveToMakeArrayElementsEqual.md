

##



## Approach 1: (does not work) calculate mean and difference from mean 

Failing test case: `[1,0,0,8,6]` : avg = 15/5 = 3
2, 3,3,5,3 = 16

expected = 14 => to reach 2 => 1+2+2+6+4 = 15

to reach 4 => 3 + 4 + 4 + 4 + 2 => 17

**to reach 1 => 0 + 1 + 1 + 7 + 5 => 14.**

## **Observation and fact**: Sum of distances from median is always the minimum!

## Approach2: Sort and find median, calculate difference from median

Proof: ?

```java
class Solution {
    public int minMoves2(int[] nums) {
     
        Arrays.sort(nums);
        int median = nums[nums.length/2];
        
        int ans=0;
        for(int i=0;i<nums.length;i++) {
            ans += Math.abs(nums[i] - median);
        }
        
        return ans;
    }
    
}
```