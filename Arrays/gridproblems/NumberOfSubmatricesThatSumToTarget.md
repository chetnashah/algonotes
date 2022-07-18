
##

https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

##

## Approach : brute force

Try all m^2 * n^2 submatrices, sum for each one will take m*n, so resulting in m^3 * n^3

## Approach: optimizing bruteforce via 2d prefix sum - O(m^2 * n^2)

2d prefix sum can give us sum of any sub-matrix in O(1), bringing down above questions complexity 
so now:

Try all m^2 * n^2 submatrices, and check if its sum matches given target.
This will result in O(R^2 * C^2)

## Approach reducing one dimension in either Row or column - Either O(m * n^2) or O(m^2 * n)


### For every row combination i.e (`0< startRow < m`, `startRow <= endRow < m`), we iterate over column widths and calculate submatrices with sum target using [Subarray sum equals to k](../SubArraySumEqualK.md)

There are `R^2` possible `(startRow,endRow)` combinations, for each of which we have column widths ranging from `1 to C`. 

For subarraySumEqualsK, complexity is O(N) where `N` is length of array.

So overall complexity is `O(R^2 * C)`

### TODO write code