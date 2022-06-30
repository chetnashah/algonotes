
##

https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

##

Given a binary array data, return the minimum number of swaps required to group all 1’s present in the array together in any place in the array.

 

Example 1:
```
Input: data = [1,0,1,0,1]
Output: 1
Explanation: There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
```
Example 2:
```
Input: data = [0,0,0,1,0]
Output: 0
Explanation: Since there is only one 1 in the array, no swaps are needed.
```
Example 3:
```
Input: data = [1,0,1,0,1,0,0,1,1,0,1]
Output: 3
Explanation: One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
``` 

Constraints:
```
1 <= data.length <= 105
data[i] is either 0 or 1.
```

## Observation/fact 2: in the final answer, the num1s will occupy any one of the possible (N-num1s+1) windows.

for input `[1,0,1,0,1]`. N = 5, num1s = 3 (window size), possible windows = 5-3+1 = 3 windows.
Final arrangement could be either:
`[1,1,1,0,0]` using 1 swap.
`[0,1,1,1,0]` using 2 swaps.
`[0,0,1,1,1]` using 1 swap.

### If we slide window of fixed size (num1s), and keep track of min num of zeros per window, we can get min swaps

The logic can be simplified by keeping track of all 0s entering and exiting the window.

### Code

```java
class Solution {
    public int minSwaps(int[] data) {
        if(data.length == 1) {
            return 0;
        }
        
        // count number of 1s
        int countOf1s=0;
        for(int i=0;i<data.length;i++) {
            if(data[i] == 1) {
                countOf1s++;
            }
        }
        
        int k = countOf1s;
        int minZeroSeen = 0;
        // check num of 0s in first window
        int runningZeroCnt=0;
        for(int i=0;i<k;i++) {
            if(data[i] == 0) {
                runningZeroCnt++;
            }
        }
        minZeroSeen = runningZeroCnt;
        // iterate over fixed sized windows of length countOf1s
        // the window with min numbr of 1s is min number of swaps needed from outside the window
        for(int i=k;i<data.length;i++) {
            if(data[i] == 0) {
                runningZeroCnt++;
            }
            if(data[i-k] == 0) {
                runningZeroCnt--;
            }
            minZeroSeen = Math.min(minZeroSeen, runningZeroCnt);
        }
        
        return minZeroSeen;  
    }
}
```