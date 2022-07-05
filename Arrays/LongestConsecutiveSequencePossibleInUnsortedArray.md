

##

https://leetcode.com/problems/longest-consecutive-sequence/

##

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```
Example 2:
```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 ```

Constraints:
```
0 <= nums.length <= 105
-109 <= nums[i] <= 109
```

## Core idea: elements consecutive to each other should be represented by a common set representative

In the end we count the size of all such sets, the one with highest number of elements is the answer.
Refer Union find:
https://github.com/chetnashah/algonotes/blob/main/Datastructures/UnionFind(DisjointSets).md

## Code

```java
import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
    
        // for Union find refer: https://github.com/chetnashah/algonotes/blob/main/Datastructures/UnionFind(DisjointSets).md
        UnionFind uf = new UnionFind();
        Set<Integer> seen = new HashSet<>();
        
        for(int i=0;i<nums.length;i++) {
            uf.encountered(nums[i]);// adjacent numbers should have same representative 
        }
        // at this stage paths are fully not compressed
        // do one more round to compress paths and count at the same time
        Map<Integer,Integer> freq = new HashMap<>();
        for(int i=0;i<nums.length;i++) {
            if(seen.contains(nums[i])) {
                continue;
            }
            int representative = uf.find(nums[i]);
            freq.put(representative, freq.getOrDefault(representative, 0) + 1);
            seen.add(nums[i]);
        }
        
        int max = 0;
        for(Integer i: freq.values()) {
            max = Math.max(max, i);
        }
        
        return max;
    }
}

// union find is a tricky algorithm to get right
// modified version that uses hashmap
class UnionFind {

    Map<Integer, Integer> hmap;
    
    public UnionFind() {// size of set
        hmap = new HashMap<>();
    }
    
    void encountered(int x) {
        if(hmap.get(x) != null){
            return;// ignore if already encountered
        }
        hmap.put(x,x);
        if(hmap.containsKey(x-1)) {
            union(x-1,x);
        }
        
        if(hmap.containsKey(x+1)) {
            union(x+1,x);
        }
        
        // if(!hmap.containsKey(x-1) && !hmap.containsKey(x+1)) {
        //     hmap.put(x, x); // representative of x is itself
        // }
    }
    
    void union(int a, int b) {
        // find representative of a
        // find representative of b
        hmap.put(find(a), find(b));
    }
    
    int find(int x) {
        int parX = hmap.get(x);
        if(parX != x) {
            parX = find(hmap.get(x));
            hmap.put(x, parX);
        }
        return hmap.get(x);
    }
}
```