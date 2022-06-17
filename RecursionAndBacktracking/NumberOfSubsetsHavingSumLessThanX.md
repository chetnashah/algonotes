
## Problem

Count the number of subsets having sum less than X.

## Brute force approach (best we can do is N=20)

### Generate each subset and count the valid ones

## Meet in the middle approach (can work for N=40)

### Split the set in two halves

They will be of either the same size, or a difference of 1.
Lets say `S1` and `S2`

* Caclculate power set of each half: i.e. `P1` and `P2`, P1, P2 containing sums of each subset in power set.
* slow - WE could try a cartesian product of P1 and P2, and you have all possible sums. (but that will again be 2^N)
* Fast - iterate on first half, and try to do binary search for K-X on the other half

