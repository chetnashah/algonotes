
## PRefix sum is a simple technique that can be useful in many problems

Idea: `prefixSum[i]` = cumulative sum upto array index `i inclusive`
in short `p[i] = p[i-1] + a[i], i>0`, and `p[0]=a[0]`.

Mathematically
$$ P_i = \sum_{k=0}^i A_k$$

```py
def calculatePrefixSum(arr):
    prefixSum = [0] * len(arr)
    prefixSum[0] = arr[0]
    for i in range(1, len(arr)):
        prefixSum[i] = prefixSum[i-1] + arr[i] # previous item has all prefix sums  
    return prefixSum
```

## Applications

1. O(1) range sums in range (r,l) both inclusive - get prefix sum for range via `prefixSum[l,r] = prefixSum[0,r] - prefixSum[0, l-1]` 


