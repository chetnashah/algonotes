
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
`P2[i] - max profit after day i by buying and selling stock once` - traverse from end of array, maintaining a maxSofar to calculate profits

`ans[i] = max(P1[i] + P2[i])`: 

e.g. lets have input array:

| 12 | 11 | 13 | 9 | 12 | 8 | 14 | 13 | 15 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

`P1[i]` will be

| minSoFar                           | 12    | 11    | 11    | 9     | 9     | 8     | 8     |  8    |  8    |
| :---:                              | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| `arr[i]`                           | 12    | 11    | 13    | 9     | 12    | 8     | 14    | 13    |  15   |
| `max(arr[i] - minSoFar, arr[i-1])` | 0     | 0     | 2     | 2     | 3     | 3     | 6     | 6     | 7     |

`P2[i]` will be

