
This can also be generalized to subarray sum equals K.

We want to know total number of sub-arrays whose sum equals K.

## 

## Approach 1: O(n) space and O(n^2) time - Range sums can be optimized with prefix sum

Refer [Prefix sums](PrefixSum.md) for details

### For each possible range, check if range sum is zero

This will be O(n^2)

## Approach 2: n^2 time but O(1) space - nested loops with running sum

### For every start point start, initialize sumSeen to 0

### Run a nested end point for each start point

### While incrementing end point from start+1 to N, keep adding to values sumSeen

### If sumSeen == 0, add cnt of subarrays with sum 0

### Code

```java
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}
```

## Approach 3: O(n) time and O(n) space using hashmap

### Core idea: If cumulative sum upto two different indices is same, the sum of values between indices is 0. Extend this idea to k, instead of 0.

### Core Idea 1: store cumulative sums up to all indices in hashmap with number of times that sum occurs.

### Core idea 2: for each cumulative sum, check for times `k - runningPrefixSum` in hashmap, increment ans count by it

### Edgecase that can be missed

Initially add:
`hashMap.put(0) = 1`. meaning we can have a zero sum subarray which is empty array.

### Code

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();// key is cumulativeSumSeen, value is numberoftimes it was seen
        map.put(0, 1);// we can have a sum of 0
        
        int ans = 0;
        int cumSum = 0;
        for(int i=0;i<nums.length;i++) {
            cumSum = cumSum + nums[i];// running prefix sum upto and including current index
            if(map.containsKey(cumSum-k)) { // there exists smaller sub array is having sum: cumSum-k, and all elements upto this index have sum cumSum, so difference between this array and that smaller array contains a sum of k
                ans += map.get(cumSum-k);
            }
            map.put(cumSum, map.getOrDefault(cumSum, 0) + 1);// update cumulative sums seen map
        }
        return ans;
    }
}
```