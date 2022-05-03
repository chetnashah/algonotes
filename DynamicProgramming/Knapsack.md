

## REsources

https://stackoverflow.com/questions/17246670/0-1-knapsack-dynamic-programming-optimization-from-2d-matrix-to-1d-matrix

https://atcoder.jp/contests/dp/tasks

https://www.youtube.com/watch?v=U4O3SwDamA4

Survey of knapsack problems - http://www.algonotes.com/en/knapsacks/


## Given capacity N and a set K, maximize or count number of ways to fill N.

There are 𝑁 items. The 𝑖-th item has weight 𝑤𝑖 (positive) and value 𝑣𝑖. 
Find a set 𝑆 such that ∑𝑖∈𝑆 (𝑤𝑖≤𝐶) and ∑𝑖∈𝑆(𝑣𝑖) is maximized.

Two variants:
1. unbounded - same item can be picked any number of times
2. bounded - each item can be picked exactly once.

## 0-1 knapsack

you can either pick or ignore an item completely. No fractional stuff allowed.

Base cases:
1. you can always create a capacity of 0 by choosing no coins/items to 
fill the knapsack = 1 way

### State shape

`dp[i,w]` - `i` is the item being considered (goes from 0 to N-1 or 1 to N depending on indexing used), 
`w` is the accumulated weight seen so far (goes from 0 to W inclusive).


### Grid size is weight + 1 (W+1) because we want to fill table for 0 .. W

e.g.
```cpp
int dp[N][W+1];
```

Recursive knapsack (with memo):
```cpp
#include<cstdio>
#include<algorithm>
#include<vector>

int N, W;
long long dp[101][100001];// limits are N+1 x W+1, where N is no of items, W is possible weights

// recursive knapsack, two dimensional recursion: itemIds increasing, weight decreasing
long long solveDP(int itemId, int remW, std::vector<std::pair<int, int>>& items){
    // printf("itemId = %d remW = %d\n", itemId, remW);
    // base case, for either dimension of recursion - items , weight capactiy
    if(itemId == N || remW <= 0) {
        return 0ll;
    }

    // 
    if(dp[itemId][remW] != -1ll) {
        // printf("found in memo: %d %d\n", itemId, remW);
        return dp[itemId][remW];
    }

    // case where cannot fit, ignore this item and let the remaining items solve
    if(items[itemId].first > remW) {
        long long ans = solveDP(itemId+1, remW, items);
        dp[itemId][remW] = ans;
        return ans;
    }
    // case where we pick and don't pick
    long long ans = std::max(
        // not picked
        solveDP(itemId+1, remW, items),
        // picked
        items[itemId].second + solveDP(itemId+1, remW - items[itemId].first, items)
    );
    dp[itemId][remW] = ans;
    // printf("Final return ans = %lld for itemId = %d, remW = %d\n", ans, itemId, remW);
    return ans;
}

int main(){
    scanf("%d %d", &N, &W);
    std::vector<std::pair<int,int>> items;
    memset(dp, -1ll, sizeof dp);
    for(int i=0;i < N; i++) {// items are indexed from 0 to 99
        int wi, vi;
        scanf("%d %d", &wi, &vi);
        items.push_back({ wi, vi});
    }
    printf("%lld", solveDP(0, W, items));// We could have done this as (0, 0, items), if our recursion state transition was adding weights instead of removing, and base case would have been total capacity check instead of less thn or equal to 0 remaining weight.
    return 0;
}
```

Tabulation based knapsack (1-indexed table for dp-table and 0 to W for weight):
So `dp[N+1][W+1]`

```cpp
#include<cstdio>
#include<algorithm>
#include<vector>

int N, W;
// N * W table
// 1-indexed tabulation, items will be considered from 1 to N
// Weights will be considered from 0 to W, so total W+1 needed.
long long dp[101][100001];// limits are N+1 x W+1, where N is no of items, W is possible weights

// tabulated knapsack
long long solveDP(std::vector<std::pair<int, int>>& items){
    // base case 1 - N items allowed to pick,but 0 weight constraint
    for(int i=0;i<N;i++) {
        dp[i][0] = 0;// 0 because there is no weight is allowed and each item weighs something positive
    }

    // base case 2 - 0 items allowed to pick, all possible weights
    for(int j=0;j<=W;j++) {
        dp[0][j] = 0;
    }
    
    // dp is 1-indexed, items is 0-indexed
    for(int i=1;i<=N;i++) {// outer loop on items
        for(int j=1;j<=W;j++) {// inner loop on weights
            // we are now considering item i for upto J weight
            if(items[i-1].first > j) {// cannot fit coz weight of item under consideration is larger than capacity, cannot be picked
                dp[i][j] = dp[i-1][j];// not picking ith item, get from upper row i.e. previous items
            } else {
                dp[i][j] = std::max(
                    dp[i-1][j],// not picking i'th item, get from upper row previous items
                    items[i-1].second + dp[i-1][j-items[i-1].first]// picking ith item, remaining weight was filled with previous items
                );
            }
        }
    }

    return dp[N][W];
}

int main(){
    scanf("%d %d", &N, &W);
    std::vector<std::pair<int,int>> items;// items is 0-indexed collection of items.
    memset(dp, 0ll, sizeof dp);// in tabulation init all with 0
    for(int i=0;i < N; i++) {// items are indexed from 0 to 99
        int wi, vi;
        scanf("%d %d", &wi, &vi);
        items.push_back({ wi, vi});
    }
    printf("%lld\n", solveDP(items));
    return 0;
}
```

## One dimensional 0-1 knapsack - O(n*S)

Outer items loop is same - 1 to N.
Inner weights loop is reversed i.e. from W down to 0.

`W` : Weight Array for items
`V` : Value Array for items

`S` : Total Capacity of knapsack

### State shape

**`X[i]` corresponds to maximum total value of items you can put in a knapsack of capacity/weight exactly `i`**. i.e. only weight dimension. `i ranges from 0 to S`.
### State transitions
```cpp
for i from 1 to n// consider item i one by one
    for j from S down to W[i]// start from end wt capacity down to limit where we can jump by W[i] in left direction, note the reverse direction is important so that we do not consider ouselves twice in 0/1 knapsack.
       dp[j] = max(dp[j],dp[j-W[i]]+V[i])// consider adding item i, and improving maximizing value
```
Your required answer is simply `dp[S]`.

Example in cpp:
```cpp
int N, W;
long long dp[100001];// W+1, W is possible weights
// pair<int, int> is <wt, value>
long long solveDP(std::vector<std::pair<int, int>>& items){
    for(auto item: items) {
        for(long long j = W; j >= item.first;j--) {
            dp[j] = std::max(dp[j], dp[j-item.first] + item.second);
        }
    }
    return dp[W];
}
```

## 0/k knapsack

Each item is allowed to be picked `k` times.

Can be done in O(n*S).


## Unbounded knapsack

Repitition of picking of items is allowed

There are 𝑁 items. The 𝑖-th item has weight 𝑤𝑖 and value 𝑣𝑖. 
Find a multiset 𝑆 such that ∑𝑖∈𝑆 (𝑤𝑖≤𝐶) and ∑𝑖∈𝑆(𝑣𝑖) is maximized.

### State shape
`[i,w]` - `i` is the item being considered, and `w` is the weight accumulated so far.

### State transitions


## Knapsack variant - Large Weight-limit/Capacity i.e. 10^9 and smaller value gain per item e.g. 10^3

Here is an example: https://atcoder.jp/contests/dp/tasks/dp_e

Capacity limit might be upto 10^9, so `dp[10^9]` is not possible, so weight dimension is not a possibility.

### State definition change to have value dimension (instead of weight)

`dp[i]` = The minimum possible weight total for value exactly `i`.

Answer would be given by iterating this array backwards, and finding the first total_wt that is less than or equalt to our capacity S. (You can also probably Binary search this answer).

What should be the total size of dp?
Ans: `[(n * maxValuePerItem)+1]`: This is because lets say each item has max value and each item is included, then we would have. extra 1 for 0 value. 

Sample example:
1 <= N <= 100 // 100 items
1 <= W <= 10^9 // knapsack capacity
1 <= wi <= W // indidvidual item weight
1 <= vi <= 10^3 // individual item value

Here dp size would be:
`dp[100 * 10^3+1]` - holding min weight for each possible value i.
### State transition logic

since this is weight minimization, `min` function shall be used.

jumps will be `v[i]` since dimension under consideration is value dimension.

Base case `dp[0]` = min weight to have value of `0` = `0`.

Since we are minimizing, inital amount in the `dp` array should be `INF` for all other indexes.



## Integer partition problem (Same as coin change ways)

Count no. of partitions e.g.
no. partitions of 5 = 7
1 + 1 + 1 + 1 + 1
1 + 1 + 1 + 2
1 + 1 + 3
1 + 4
1 + 2 + 2
2 + 3
5 + 0

A variation on unbounded knapsack. a 2-d dp on all targets vs items/coins.
We are looking for all multiset S such that sum of elements in multi set equals Target C.


## Subset sum

There are 𝑁 items. The 𝑖-th item has weight 𝑤𝑖. 
Find a set 𝑆 such that ∑𝑖∈𝑆(𝑤𝑖=𝐶)

It is variant of knapsack where we are looking for subset that sums exact weight C.
Another variant: count such subsets which add up to weight C.
Another variant: canSum -> returning true/false if a subset exists that can sum to weight C.