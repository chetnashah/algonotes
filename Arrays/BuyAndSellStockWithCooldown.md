
## 

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

https://www.youtube.com/watch?v=4wNXkhAky3s

##

You are given an array prices where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:
```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```
Example 2:
```
Input: prices = [1]
Output: 0
 ```

Constraints:
```
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
```

## Observation 1: Problem specifies that sell should happen before Buy, so patterns would be like BSBSBS 

It is not possible to nest transactions e.g. following is not allowed: `BBSS` or `BBSSBS` etc are not allowed. **Nesting is not allowed**.

## Observation 2: store two arrays `buy[i]` and `sell[i]`

## Top down DP state

`int getBestProfitFromFirst[idx][lastSellDone]`

## DP recurrence diagram



## Code

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

## Top down DP

TODO understand this logic

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!