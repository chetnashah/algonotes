
### Resources

1. https://www.youtube.com/watch?v=uUatD9AudXo
2. https://www.youtube.com/watch?v=EKcQt-74bNw
3. https://www.youtube.com/watch?v=0jWeUdxrGm4
4. https://www.youtube.com/watch?v=c5O7E_PDO4U
5. https://cp-algorithms.com/data_structures/sparse-table.html
6. https://github.com/raywenderlich/swift-algorithm-club/tree/master/Sparse%20Table
7. 
### For Efficient range queries on **static queries** (preferred for min/max)

Static array i.e. array data does not change, for dynamic usecases prefer Segment tree.
preferred for range min/max queries. One should prefer BIT/fenwick in case of range sum queries.

sparse table can be applied to answer the range queries of any idempotent functions – that is, functions that can be applied multiple times without changing the result beyond the initial application.


Examples of idempotent function:
`minimum`, `maximum`, `GCD`, and `LCM` functions.
floor, ceiling, absolute.

**If any element in the array changes, the complete data structure has to be recomputed**

### Range Min query comparision

| Approach | Preprocessing Time/memory | Query time |
| --- | --- | --- |
| Brute force | O(1) | O(N) |
| Dynamic programming | O(N^2) | O(1) |
| Segment Tree | O(N) | O(log N) |
| Sparse Table | O(N log N) | O (1) |
| Lowest Common Ancestor | O(N) | O(1) |

### types of queries

1. min
2. max
3. gcd
4. sum

### Core idea : breaking intervals via powers of two

precompute all answers for range queries with power of two length. 

Afterwards a different range query can be answered by splitting the range into ranges with power of two lengths, looking up the precomputed answers, and combining them to receive a complete answer.



### Range combination function has to be associative -> Queries in log N

A function f(x,y) is associative if,
`f(a, f(b, c)) = f(f(a,b), c)`

e.g mult, add, min, max

### Range combination function is associative and overlap friendly/agnostic -> Queries in O(1)

Definition of overlap friendly/agnostic function:
A function `f(a,b)` is overal agnostic if:
`f(f(a,b), f(b,c)) = f(a, f(b, c)) for all valid a, b, c`

Overlap friendly functions: `min, max`.
Not overlap friendly functions : `sum, mult` - double counting happens for overlapping parts, so not overlap friendly

### Table construction

Let `N` be size of input array.
Biggest power of two possible, `P = floor(lg N)`

2-d array table size : `N columns(numbered 0 to N-1), P+1 rows(numbered 0 to P)` ~ N x lgN 2-d array table

1. fill first row with input values (all N original values)
2. `cell[i,j] = fn[j, j+2^i - 1] inclusive in original array`, where `i` is row index < P+1, and `j` is column index < N.
3. meaning of a value at `cell[i,j]` is summary/aggregate(E.g. min/max/sum) of all 2^i entries starting at index j. 

cells with invalid intervals can be ignored
e,g cells where `j+2^i` overflows, those cells can be marked as invalid

### Satisfying Queries


`min[a,b] = min(min[a, a+k-1], min[b-k+1, b])`
where k = largest power of 2 that does not exceed `b-a+1`, i.e largest power of two less then range length.

e.g.
| 1 | 3 | 4 | 8 | 6 | 1 | 4 | 2 |
|---|---|---|---|---|---|---|---|
` min[1,6] = min(min[1, 1+4-1], min[6-4+1, 6])`
=`min(min[1,4], min[3,6])` // these should be available in the table.