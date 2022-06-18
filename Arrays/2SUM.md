## Brute force - try all pairs O(N^2)

## Store numbers in set/hashmap

1. search in hashmap/set for complement, before adding to the hashmap, this is because we dont want to consider the same element again.
2. if found report the answer.

## Code

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            // Note: we put into the map after search so that we don't want to consider the same element twice
            map.put(nums[i], i);
        }
        // In case there is no solution, we'll just return null
        return null;
    }
}
```