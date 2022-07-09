
##

https://leetcode.com/problems/integer-break/

##

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:
```
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
```
Example 2:
```
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 ```

Constraints:
```
2 <= n <= 58
```

##

## Where I got stuck

* Could not find a subproblem structure

## Core idea

For any other number other than original, you can break up using forloop ranging from `1` to `n-1`.

## Core recursive function

`dfs(i)`: return max possible product possible, with or without breaking `i`.

For initial given `i`, we must break it up, by keeping initial max 0.
For others, we can start by initialMax = i.

## code

```java
class Solution {
    int num;
    int[] ans;
    public int integerBreak(int n) {
        // one approach - try all possible partitions and find max product
    
        ans = new int[n+1];
        ans[1] = 1;
        for(int i=2;i<=n;i++) {
            ans[i] = -1;
        }
        
        num = n;
        return dfs(n);
    }
    
    // max product we can get with or without splitting n
    public int dfs(int n) {
        if(n == 1) {
            return 1;
        }
    
        // memo step
        if(ans[n] != -1) {
            return ans[n];
        }
        
        int res = (n == num) ? 0 : n;// if n is original num, we must break it up and keep initialmax 0
        // if n is not original num, we can have initial max as the n itself
        
        for(int i=1;i<n;i++) {
            int product = i * dfs(n-i);// get possible products by different partitions
            // System.out.println("n = " + n + " product = " + product);
            res = Math.max(res, product);// keep track of max product 
        }
        ans[n] = res;
        return res;
    }
}
```