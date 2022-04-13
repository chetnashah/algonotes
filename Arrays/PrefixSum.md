
## PRefix sum is a simple technique that can be useful in many problems

Idea: `prefixSum[i]` = cumulative sum upto array index i inclusive

```py
def calculatePrefixSum(arr):
    prefixSum = [0] * len(arr)
    prefixSum[0] = arr[0]
    for i in range(1, len(arr)):
        prefixSum[i] = prefixSum[i-1] + arr[i] # previous item has all prefix sums  
    return prefixSum
```

## Applications

1. range sums in range (r,l) - get prefix sum for range via `prefixSum[0,r] - prefixSum[0, l-1]` 
