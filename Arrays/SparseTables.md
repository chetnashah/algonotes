
### Resources

1. https://www.youtube.com/watch?v=uUatD9AudXo
2. https://www.youtube.com/watch?v=EKcQt-74bNw
3. https://www.youtube.com/watch?v=0jWeUdxrGm4
4. https://www.youtube.com/watch?v=c5O7E_PDO4U
5. https://cp-algorithms.com/data_structures/sparse-table.html
6. https://github.com/raywenderlich/swift-algorithm-club/tree/master/Sparse%20Table
7. 
### For Efficient range queries on static queries

Static array i.e. array data does not change

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

Known fact: Any positive integer can be represented as sum of powers of two

New fact:
Any interval [l, r] can be broken down by breaking down `r - l` in powers of two
`17 - 5 = 12 = 2^3 + 2^2`
e.g.
`[5,17] = [5, 5+2^3) + [5+2^3, 5+ 2^3 + 2^2) + [5 + 2^3 + 2^2 + 2^0, 5 + 2^3 + 2^2 + 2^0)`
`[5,17] = [5, 13) + [13, 17) + [17, 18)`

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

2-d array table size :
`N columns(numbered 0 to N-1), P+1 rows(numbered 0 to P)` ~ N x lgN 2-d array table
1. fill first row with input values (all N original values)
2. `cell[i,j] = [j, j+2^i) in original array`, where `i` is row index < P+1, and `j` is column index < N, note the end part is exclusive index -
3. meaning of a value at `cell[i,j]` is summary/aggregate(E.g. min/max/sum) of all 2^i entries starting at index j. 

cells with invalid intervals can be ignored
e,g cells where `j+2^i` overflows, those cells can be marked as invalid

### Satisfying Queries

