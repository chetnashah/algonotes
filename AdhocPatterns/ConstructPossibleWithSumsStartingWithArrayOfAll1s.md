
##

https://leetcode.com/problems/construct-target-array-with-multiple-sums/

##

You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that `0 <= i < n` and set the value of arr at index `i` to `x`.
You may repeat this procedure as many times as needed.
Return true if it is possible to construct the target array from arr, otherwise, return false.

Example 1:
```
Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```
Example 2:
```
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
```
Example 3:
```
Input: target = [8,5]
Output: true
```

Constraints:
```
n == target.length
1 <= n <= 5 * 104
1 <= target[i] <= 109
```

## Code

```java
class Solution {
    public boolean isPossible(int[] target) {
        if(target.length == 1) {
            if(target[0] == 1) {
                return true;
            } else {
                return false;
            }
        }
        
        // more than one items in list
        int totalSum = 0;// updated sum of all numbers in the list
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int i=0;i<target.length;i++) {
            totalSum += target[i];
            pq.add(target[i]);
        }
        
        // till there are non reduced item in heap
        while(pq.peek() > 1) {
            int largest = pq.poll();
            int restSum = totalSum - largest;
            
            if(restSum == 1) { // only happens when n = 2
                return true; // we can reach other by consecutively substracting 1
            }
            
            int reducedLargest = largest % restSum;// useful trick to reduce numbers, use modulo instead of substracting
            
            if(reducedLargest < 1 || reducedLargest == largest) {// the equals comparision when largest does not go down, e.g. consider -> [1,1,1,2] where reducedLargest = 2 % 3 = 2 = largest 
                return false;
            }
            pq.add(reducedLargest);
            totalSum = totalSum - largest;
            totalSum = totalSum + reducedLargest;
        }
        return true;
    }
}
```