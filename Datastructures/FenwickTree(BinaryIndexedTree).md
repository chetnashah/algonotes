
## REsources

https://www.youtube.com/watch?v=CWDQJGaN1gY
https://www.youtube.com/watch?v=kPaJfAUwViY
https://www.youtube.com/watch?v=4SNzC4uNmTA
https://cp-algorithms.com/data_structures/fenwick.html (0-indexed and later 1-indexed also explained)
https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
competitive programmer's handbook


## Use case

* `log N` range sum queries (generalized to function `f` in `[l,r]` if `f` is reversible)
* `log N` point updates
* `O(N)` memory

For sake of simplicity and understanding, assume `f` is sum function, i.e. we will look at range sum queries.

## ADT

1. `getSum(l, r)` :get sum in the range `[l,r]` inclusive
2. `update(i, v)`: update value at index `i` with value `v`. 

## Prefix sum does not work for dynamic data

Prefxi sum can work for static data, but lot of re-computation needs to happen for point updates.


## cp-algorithms Representation

`Array` based representation. (1-indexed simpler to understand and common, there are 0-indexed also)

A Fenwick tree is just an array `T[]`, where each of its elements is equal to the sum of elements of `A[]` in some range `[g(i),i]` :
where `g` is some function that satisfies `0 <= g(i) < i`. 


`g(i) = i - (i & -i)` 1-based indexing -> cleared last set bit. 
each `T[i]` is responsible for the range `(g(i), i]` -> `[g(i) + 1, i]` both sides index inclusive.

**you can notice odd numbers are responsible for themselves only, and as a number has more powers of two as a factor, they get to be responsible for larger number of items in the original array**

case `i=1`: `T[1]` is responsible for `(g(1), 1]` = `(0,1]` i.e. `[1,1]`
case `i=2`: `T[2]` is responsible for `(g(2), 2]` = `(0,2]` i.e. `[1,2]`
case `i=3`: `T[3]` is responsible for `(g(3), 3]` = `(2,3]` i.e. `[3,3]`
case `i=4`: `T[4]` is responsible fro `(g(4), 4]` = `(0,4]` i.e. `[1,4]`
case `i=5`: `T[5]` is responsible for `(g(5), 5]` = `(4,5]` i.e. `[5,5]`
case `i=6`: `T[6]` is responsible for `(g(6), 6)` = `(4,6]` i.e. `[5,6]`
case `i=7`: `T[7]` is responsible for `(g(7), 7]` = `(6,7]` i.e. `[7,7]`
case `i=8`: `T[8]` is responsible for `(g(8), 8]` = `(0,8]` i.e. `[1,8]`
case `i=9`: `T[9]` is responsible for `(g(9), 9]` = `(8,9]` i.e. `[9,9]`
case `i=10`: `T[10]` is responsible for `(g(10), 10]` = `(8,10]` i.e. `[9,10]`
case `i=11`: `T[11]` is responsible for `(g(11), 11]` = `(10,11]` i.e. `[11,11]`
case `i=12`: `T[12]` is responsible for `(g(12), 12]` = `(8,12]` i.e. `[9,12]`
case `i=13`: `T[13]` is responsible for `(g(13), 13]` = `(12,13]` i.e. `[13,13]`


## cp handbook representation (1-indexed)

Let `p(k)` denote the largest power of two less than k.
`T[k] = sum(k - p(k) + 1, k)`

case 1: k = 1, p(k) = 0, T[1] = sum(1 - 0 + 1, 1) = sum(2,1)
case 2: k = 2, p(k) = 1, T[2] = sum(2 - 2 + 1, 2) = sum(1,2)
case 3: k = 3, p(k) = 1, T[3] = sum(3 - 1 + 1, 3) = sum(3,3)
case 4: k = 4, p(k) = 2, T[4] = sum(4 - 2 + 1, 4) = sum(3,4)
case 5: k = 5, p(k) = 2, T[5] = sum(5 - 2 + 1, 5) = sum(4,5)
case 6: k = 6, p(k) = 1, T[6] = sum(6 - 1 + 1, 6) = sum(6,6)


`odd` indexed numbers are responsible for themselves. `T[i] = A[i]` for all `odd i`.


## Defining g(i)


## Construction

O(n log n) construction

## Updates

## parent child representation

Parent of (x) = value after clearing last bit in x.



