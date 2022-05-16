
This is a variant of knapsack in following terms:
N -> amount we want to fulfill
coins -> items we want to fill/pick to make change for N.

# variant 1 - Min no. of coins needed 

Min number of coins needed to make change

## given coins c

c = {c1, c2, ... cn}

## recurrence

solve(x) = min(solve(x - c1)+1, solve(x-c2)+1, ... , solve(x-cn)+1)

## recursive solution

```cpp
int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }
    return best;
}
```

## memoization applied

## bottom up iterative tabulation

## constructing solution

# variant 2 - count number of ways(ordering matters), each coin be picked any number of times?

# variant 2 - count number of ways(ordering matters), each coin be picked once

# variant 3 - count number of ways (ordering does not matter), each coin can be picked any number of times

# variant 3 - count number of ways (ordering does not matter), each coin can be picked once
