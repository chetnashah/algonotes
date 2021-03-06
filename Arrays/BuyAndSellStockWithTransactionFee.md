

##

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

##

You are given an array prices where `prices[i]` is the price of a given stock on the `ith` day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 
##

Example 1:
```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```
Example 2:
```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 ```

Constraints:
```
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
```


## Observation 1: Problem specifies that sell should happen before Buy, so patterns would be like BSBSBS 

It is not possible to nest transactions e.g. following is not allowed: `BBSS` or `BBSSBS` etc are not allowed. **Nesting is not allowed**.


##  DP state

`int getBestProfitFromFirst[idx][lastSellDone]`

## DP recurrence diagram

![Buy sell with fee recurrence](images/../../DynamicProgramming/images/buysellwithfeerecurrence.jpg)

## Top down DP

TODO understand this logic

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!

### Code

```java
class Solution {
    int[][] ans;
    int sentinel = -9999999;
    public int maxProfit(int[] prices, int fee) {
        
        ans = new int[prices.length][2];
        
        for(int i=0;i<prices.length;i++) {
            ans[i][0] = sentinel;
            ans[i][1] = sentinel;
        }
        
        // lastSellDone : false -> 0, true -> 1
        int getBestProfitWithLastSell = getBestProfit(prices.length - 1, 0, prices, fee);
        
        return getBestProfitWithLastSell;
    }
    
    // get best profit upto idx, with sell allowed
    int getBestProfit(int idx, int lastSellDone, int[] prices, int fee) {
        // System.out.println("idx = "+idx+" lastSellDone = "+lastSellDone);
        if(ans[idx][lastSellDone] != sentinel) {
            return ans[idx][lastSellDone];
        }
        if(idx == 0) {
            // buy at this 
            if(lastSellDone == 1) {// finish the buy
                return -1*prices[0];
            }
            // do nothing
            int ans3=0;
            return ans3;
        }
        
        // sell
        int ans1 = (lastSellDone == 0) ? (getBestProfit(idx-1, 1, prices, fee) + prices[idx] - fee): sentinel;
        // buy 
        int ans2 = (lastSellDone == 1) ? (getBestProfit(idx-1, 0, prices, fee) - prices[idx]) : sentinel;
        // do nothing
        int ans3 = getBestProfit(idx - 1, lastSellDone, prices, fee);
        
        int finalAns = Math.max(ans1, Math.max(ans2, ans3));
        // System.out.println("finalAns for idx = " +idx +" ans = "+ finalAns);
        ans[idx][lastSellDone] = finalAns;
        return finalAns;
    }
}
```