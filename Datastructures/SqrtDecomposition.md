
## Resources

https://www.youtube.com/watch?v=SbipYwqzBXk

https://www.youtube.com/watch?v=K54R2D9bilQ

https://www.youtube.com/watch?v=BJhzd_VG61k

https://www.youtube.com/watch?v=g5g1UqSjOIQ

https://cp-algorithms.com/data_structures/sqrt_decomposition.html

## Goal


Given array `a[0 .. n-1]`, implement a data structure that allows
to find a **range sum** `a[l ... r]` for arbitrary l and r in `O(sqrt(N))`

* Divide array `a[]` into blocks of length approximately `sqrt(N)`.
* For each block `i`, pre calculate sum of elements in `b[i]`

`Number of blocks` = `size of blocks` = `s` = `ceil(sqrt(N))`

Blocks numbered from `i = 0` to `i = s - 1`