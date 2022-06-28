
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/most-consistent-ways-of-dealing-with-the-series-of-stock-problems
https://www.youtube.com/watch?v=MyqDgMy-Kew

## Variation 1 (Buy and sell stock once): single stock prices given, return indices i,j such that i < j and a[j] - a[i] is maximum

### Brute force (O(n^2))

Check every pair and maintain `max(a[j] - a[i])`.

### Where I got stuck/learnings

Just taking max/min is not enough,

since min can appear at the end of the array and not useful. 

But minSoFar is useful, since buying has to be done from `[1..i] days`, hence the best min so far would be in it.

### Linear time solution

### Core Idea: keep track of min-so-far as you traverse through the array, and max profit for current day = currentprice - minSoFar

```java
    public int maxProfit(int[] prices) {
        int minSoFar = Integer.MAX_VALUE;
        int maxProfit = 0;
        for(int i=0;i<prices.length;i++) {
            if(prices[i] < minSoFar) {
                minSoFar = prices[i];
            }
            int maxProfitAti = prices[i] - minSoFar;
            maxProfit = Math.max(maxProfit, maxProfitAti);
        }
        return maxProfit;
    }
```

## Variation 2: Buy and sell stock atmost twice

### Brute force solution: try all combination of buy-sell-buy-sell using four indices: i, j, k, l

Time complexity for brute force approach: O(n ^ 4)

### Learnings

#### Divide and conquer approach O(n^2) - n divisions, each division takes O(n) to find buy and sell stock once
1. approach could be divide and conquer - for all possible two subarrays of days e.g. `[1..k], [k+1..n]`. 
2. within each subarray you can  buy and sell stock once, and 
3. from all possible combinations, pick the best sum of two subarrays. 


### Core Idea - bidirectional DP

`P1[i] - max profit including day i with only buying and selling once` - same idea as variation 1.

`P2[i] - max profit on or after day i by buying and selling stock once` - traverse from end of array, maintaining a maxSofar to calculate profits

`ans[i] = max(P1[i] + P2[i])`: 

e.g. lets have input array:

| 12 | 11 | 13 | 9 | 12 | 8 | 14 | 13 | 15 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

`P1[i]` will be

| minSoFar                           | 12    | 11    | 11    | 9     | 9     | 8     | 8     |  8    |  8    |
| :---:                              | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| i                                  | 0     | 1     | 2     |   3   |  4    |    5  |   6   |   7   |   8   | 
| `arr[i]`                           | 12    | 11    | 13    | 9     | 12    | 8     | 14    | 13    |  15   |
| `max(arr[i] - minSoFar, arr[i-1])` | 0     | 0     | 2     | 2     | 3     | 3     | 6     | 6     | 7     |

`P2[i]` will be (traversed from right end i =N to 0)

| maxSoFar                            | 15    | 15    | 15    | 15    | 15    | 15    | 15    |  15   |  15   |
| :---:                               | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| i                                   | 0     | 1     | 2     |   3   |  4    |    5  |   6   |   7   |   8   | 
| `arr[i]`                            | 12    | 11    | 13    | 9     | 12    | 8     | 14    | 13    |  15   |
| `max(maxSoFar - arr[i] , arr[i+1])` | 7     | 7     | 7     | 7     | 7     | 7     | 2     | 2     | 0     |


`Ans[i]` = `P1[i-1] + P2[i]`:
| `P1[i-1]`  | 0  | 0     | 0     | 2     | 2     | 3      | 3     | 6      | 6      | 7/-   |
|:---:       | :---: | :---:     | :---:    | :---:     | :---:     | :---:    | :---:     | :---:     | :---:  | :---: |
| `P2[i]`    |  7 | 7     | 7     | 7     | 7     | 7     | 2      | 2      | 0      | 0/-     |
| `ans[i]`   | 7  |  7    |  7    | 9     | 9     | 10    | 5      | 8      |  6     | 7/-     |

### Code

```java
class Solution {
    public int maxProfit(int[] prices) {
        
        int[] firstProfit = new int[prices.length]; // profit by buying and selling till day i
        int minSoFar = prices[0];// first is min seen so far
        firstProfit[0] = 0;// buying and selling on same day is 0 profit
        for(int i=1 ; i<firstProfit.length ; i++) {
            int currPrice = prices[i];
            if(currPrice < minSoFar) {
                minSoFar = currPrice;
            }
            firstProfit[i] = Math.max(firstProfit[i-1], currPrice-minSoFar);
        }
        // System.out.println(Arrays.toString(firstProfit));
        
        int[] secondProfit = new int[prices.length];// profit by buying and selling on + after ithday
        int maxSofar = prices[prices.length-1];// last is max seen so far
        secondProfit[prices.length - 1] = 0; // buying and selling on last day is 0 profit
        for(int i=secondProfit.length-2; i>=0; i--) {
            int currPrice = prices[i];
            if(currPrice > maxSofar) {
                maxSofar = currPrice;
            }
            secondProfit[i] = Math.max(secondProfit[i+1], maxSofar - currPrice);
        }
        // System.out.println(Arrays.toString(secondProfit));

        
        int[] ans = new int[prices.length];
        int ansMax = 0;
        for(int i=0;i<prices.length;i++) {
            ans[i] = (i == 0 ? 0 : firstProfit[i-1]) + secondProfit[i];
            if(ans[i] > ansMax) {
                ansMax = ans[i];
            }
        }
        // System.out.println(Arrays.toString(ans));
        
        return ansMax;
    }
}
```

### recursion

numTransactions = 0 lastStockHoldOrNot = 0 dayNum = 0
numTransactions = 0 lastStockHoldOrNot = 1 dayNum = 1
numTransactions = 1 lastStockHoldOrNot = 0 dayNum = 2
numTransactions = 1 lastStockHoldOrNot = 1 dayNum = 3
numTransactions = 1 lastStockHoldOrNot = 0 dayNum = 3

numTransactions = 0 lastStockHoldOrNot = 1 dayNum = 2
numTransactions = 1 lastStockHoldOrNot = 0 dayNum = 3
numTransactions = 0 lastStockHoldOrNot = 1 dayNum = 3
numTransactions = 0 lastStockHoldOrNot = 0 dayNum = 1
numTransactions = 0 lastStockHoldOrNot = 1 dayNum = 2
numTransactions = 1 lastStockHoldOrNot = 0 dayNum = 3
numTransactions = 0 lastStockHoldOrNot = 1 dayNum = 3
numTransactions = 0 lastStockHoldOrNot = 0 dayNum = 2
numTransactions = 0 lastStockHoldOrNot = 1 dayNum = 3
numTransactions = 0 lastStockHoldOrNot = 0 dayNum = 3

## Variant: buy and sell stock k times, 

### Brute force

Try each of 2k days, resulting in O(2 ^ 2k) complexity

### Dynamic programming formulation

### Partial top down recursion

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        int ans = backtrackHelper(0, 0, 0, k, prices);
        return ans;
    }
    
    /**
    return best ans for k transactions and prices,
    give we are considering dayNum, already numTransactions have finished, and lastStockwas hold or not.
    */
    int backtrackHelper(int numTransactions, int lastStockHoldOrNot, int dayNum, int k, int[] prices) {
        System.out.println("numTransactions = "+numTransactions+" lastStockHoldOrNot = "+lastStockHoldOrNot + " dayNum = " +dayNum);
        if(numTransactions == k) {
            return 0;// no more transactions can be done
        }
        
        if(dayNum == prices.length) {
            return 0;// we are out of days to consider
        }
        
        // we can buy
        if(lastStockHoldOrNot == 0) {
            backtrackHelper(numTransactions, 1, dayNum+1, k, prices);
        }
        
        // we can sell
        if(lastStockHoldOrNot == 1) {
            backtrackHelper(numTransactions+1, 0, dayNum+1, k, prices);
        }
        
        // we can hold
        backtrackHelper(numTransactions, lastStockHoldOrNot, dayNum+1, k, prices);
        return 0;
    }
}
```

## Variant buy and sell stock infinite number of times, nesting transactions not allowed

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Buy and sell on same day is allowed.

### Example

`[1,2,3,4]` => `1+1+1` = `3`
`[5,4,3,2]` => `0`
`[4,2,7,1,5]` => `(7-2) + (5-1)` => `5 + 4` = `9`

### Proceed greedily (between consecutive days), ignore if next day decreases

Any time you see increase in stock between current and next day, accumulate that profit.


### Code 

```java
class Solution {
    public int maxProfit(int[] prices) {
        // greedy approach - check current and prev day and sell if increasing
        
        int ans = 0;
        for(int i=1;i<prices.length;i++) {
            if(prices[i] > prices[i-1]) {
                ans+= prices[i] - prices[i-1];
            }
        }
        
        return ans;
    }
}
```

## Variation: with cooldwon

Refer [Buy and sell stock with cooldwon](../Arrays/BuyAndSellStockWithCooldown.md)
