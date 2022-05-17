

## Dp state

`dp[i]` = max sum that can be formed upto ith index

## Dp transition

keep including and incrementing current value till it keeps the total sum i.e. `dp[i]` positive,
if `dp[i]` becomes negative on including current elemtn, skip and reset start pointer for max seen.

Also keep track of `maxSeenSoFar`.

## variant also report start end for max subarray sum