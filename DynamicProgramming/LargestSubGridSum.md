
## Resources

https://www.youtube.com/watch?v=-FgseNO-6Gk

## Pre requisite

You must know max-subarray-sum or kadane's algorithm which can be found here: [kadanes algorithm](MaxSubarraySum.md)

## Where I got stuck

The kadane's in two dimension would consider adjacent top and adjacent left for sub sums, but they may be of arbitrary shapes.
Moreover kadanes default algorithm just tracks the sum and not the indices.

## Extra data structures needed

An array that holds running row sums per row
we will have a `for each row r, runningRowSums[r] = sum(cells[r][L..R])`, `0 <= r <= rows.size()`.

### Track 5 different max variables

1. maxRectangleSum
2. maxLeft
3. maxRight
4. maxTop
5. maxBottom

## Algorithm

1. Two pointers: L,R will move from 0 to cols.size(), `0 < L < cols.size(), L < R < cols.size()`

2. for each L,R combination , we will have a `runningRowSums[r] = sum[r][L..R]`, `0 <= r <= rows.size()`

3. We apply kadane's algorithm to find best sum in `runningRowSums`, which will give us our top and bottom.

