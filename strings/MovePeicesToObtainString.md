

You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

 

Example 1:
```
Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to "L______RR".
Since it is possible to get the string target from start, we return true.
```
Example 2:
```
Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
```
Example 3:
```
Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
 ```

Constraints:
```
n == start.length == target.length
1 <= n <= 105
start and target consist of the characters 'L', 'R', and '_'.
```

## Approach tried: dp from left and right

## Tough test case

```
"R_L__R__R_"
"_L______RR"
```

Expected: false, my algo: true

What I missed: Check number of Ls and Rs should be equal

## Code

```java
class Solution {
    public boolean canChange(String start, String target) {
        int[] numOfRsToTheLeft = new int[start.length()];
        int[] numOfLsToTheRight = new int[start.length()];
        
        int numOfLsInStart = 0;
        int numOfRsInStart = 0;
        
        int numOfLsInTarget = 0;
        int numOfRsInTarget = 0;
        
        for(int i=0;i<start.length();i++) {
            if(start.charAt(i) == 'L') {
                numOfLsInStart++;
            } else if (start.charAt(i) == 'R') {
                numOfRsInStart++;
            }
        }
        
        for(int i=0;i<target.length();i++) {
            if(target.charAt(i) == 'L') {
                numOfLsInTarget++;
            } else if (target.charAt(i) == 'R') {
                numOfRsInTarget++;
            }
        }

        if(numOfLsInStart != numOfLsInTarget || numOfRsInStart != numOfRsInTarget) {
            return false;
        }
        
        numOfRsToTheLeft[0] = start.charAt(0) == 'R' ? 1 : 0;
        for(int i=1;i<start.length();i++) {
            if(start.charAt(i) == 'L') {
                numOfRsToTheLeft[i] = 0;
            }
            if(start.charAt(i) == 'R') {
                numOfRsToTheLeft[i] = numOfRsToTheLeft[i-1] + 1;
            } 
            if(start.charAt(i) == '_') {
                numOfRsToTheLeft[i] = numOfRsToTheLeft[i-1];
            }
        }
        
        numOfLsToTheRight[start.length() - 1] = start.charAt(start.length() - 1) == 'L' ? 1 : 0;
        for(int i=start.length() - 2; i>=0;i--) {
            if(start.charAt(i) == 'L') {
                numOfLsToTheRight[i] = numOfLsToTheRight[i+1] + 1;
            }
            if(start.charAt(i) == 'R') {
                numOfLsToTheRight[i] = 0;
            }
            if(start.charAt(i) == '_') {
                numOfLsToTheRight[i] = numOfLsToTheRight[i+1];
            }
        }
        
        // System.out.println(Arrays.toString(numOfRsToTheLeft));
        // System.out.println(Arrays.toString(numOfLsToTheRight));

        boolean canDo = true;
        for(int i=0;i<target.length();i++) {
            char targetChar = target.charAt(i);
            
            if(targetChar == 'L') {
                canDo = canDo && numOfLsToTheRight[i] > 0;
            }
            if(targetChar == 'R') {
                canDo = canDo && numOfRsToTheLeft[i] > 0;
            }
        }
         
        return canDo;
    }
}
```
