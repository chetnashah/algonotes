
https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

## Two variations, just get length vs printing longest increasing subsequence

## Longest increasing subsequence length

### DP state

`dp[i] = longest length increasing subsequence upto and including ith element`.

### DP reucrrence idea

Look back to every element that is smaller than us, 
pick one with best subeq count and increment 1.


if all previous entries are larger than current element, `LIS[i] = 1`
else `LIS[i] = 1 + Max[LIS[j]] such that j < i and A[j] < A[i]`

### code

```cpp
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1);// initially all lengths 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {// among previous lower elements
                d[i] = max(d[i], d[j] + 1); // pick the one with best outcome
            }
        }
    }

    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i]);
    }
    return ans;
}
```

This approach takes O(N^2) time

## LIS in O(N lg N)

https://www.youtube.com/watch?v=S9oUiVYEq7E
https://www.youtube.com/watch?v=on2hvxBXJH4
https://www.youtube.com/watch?v=66w10xKzbRM

## LIS via DFS + cache

