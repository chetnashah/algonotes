
### No of elements from start of array to index i

`0..i` = `i+1` elements

### index of elements of first k elements of array

`0..k-1`

### How many array items are present between index i & j, both elements inclusive i.e. |[i..j]|?

Ans: `j - i + 1`, assuming `j >= i`

e.g.
| 0 | 1 | 2 | 3 | 4 | 5 |
| --- | --- | --- | --- | --- | --- |
|     |     | `i` |     | `j` |     |

If we take window of `Arr[2,4] inclusive`,
it has three elements because `4-2+1`.

## Array halving techniques

### `mid` = len/2, picks the larger median index (in case of even sized array)

#### Array size 3:
`mid = 3/2 = 1`

odd sized Array:
| 0 | `1` | 2 |
|--- | --- | --- |
| | mid | |

### Array size 4:
`mid = 4/2 = 2`

even sized array:
| 0 | 1 | `2` | 3 |
| --- | --- | --- | --- |
| | | mid | |

### `mid = (hi - lo)/2`, where `lo = 0` and `hi = lst.length - 1` are index of first and last element

`mid = (hi - lo)/2`: **It picks the lower median index** 

#### Array size 3:
`mid = (2-0)/2 = 1`

odd sized Array:
| 0 | `1` | 2 |
|--- | --- | --- |
| | `mid` | |

### Array size 4:
`mid = (3-0)/2 = 1`

even sized array:
| 0 | `1` | 2 | 3 |
| --- | --- | --- | --- |
| | `mid` | | |

## Number of subarrays starting at index i

The starting index is `i`, and last possible index is `n-1`.
Total no of elements between inclusive of both `i` and `n-1` is `(n-1) - i +1` = `n-i`
Each one of these elements can serve as end index, so there are `n-i` subarrays starting at index i.

## Number of subarrays ending at index i

There are `i - 0 + 1` elements between 0 to ith element, each of which can serve as starting array index.
So there are `i+1` sub arrays ending at index i.


## Allocating a grid same size of other grid

```java
int[][] updownGrid = new int[grid.length][grid[0].length];// first index is number of rows, second index is number of columns.
```

## How many times total i.e. frequency of `i`th element occurs in all sub arrays of `[0..(n-1)]`

Ans = `(i+1) * (n-i)`

There `i+1` ways to select the first index of sub array where ith element would appear.
There would be `(n-1)-i+1` ways to select end index of sub array -> Refer number of elements between two indices above.
By product rule of counting answer is `(i+1) * (n-i)`.

## Common powers of 2 compared with powers of 10:

`2^10 ~ 10^3` and `2^20 ~ 10^6`

## Reverse elements of array from inx start to end inclusive

```java
void reverseWord(int start, int end, char[] s) {        
    for(int i=0;i<=(end-start)/2;i++) { // note the less than or equal to
        char c = s[start+i];
        char c2 = s[end-i];
        s[start+i] = c2;
        s[end-i] = c;
    }
}
```

## Visiting a grid via 4-paths -> up,down,left,righ

```java
int[][] dirs = new int[][]{{0,1}, {1,0}, {-1, 0}, {0, -1}};

for(int d=0;d<dirs.length;d++) {
    int nextCellRow = i + dirs[d][0];
    int nextCellColumn = j + dirs[d][1];
    if(nextCellRow >=0 && nextCellRow < matrix.length
        && nextCellColumn >=0 && nextCellColumn < matrix[0].length
        ) {
            // do something with matrix[nextRow][nextColumn]
    }
}
```

## Number of submatrices of a given matrix (m rows x n columns)

An `m` x `n` matrix can be thought of as `m+1` horizontal lines and `n+1` vertical lines.

For any horizontal lines, two lines can be choosed in $m+1 \choose 2$ ways and any vertical lines, two lines can be chosen in $n+1 \choose 2$ ways (which are independent so product rule can be applied).

So total number of submatrices is: ${m+1 \choose 2} * {n+1 \choose 2}$ or $\frac{m(m+1)n(n+1)}{4}$


### Number of submatrices of fixed-size (a rows x b columns)


## Computing 1D prefix sum

`p[i] = p[i-1] + a[i], i>0`, and `p[0]=a[0]`.

## Computing 2D prefix sum

```py
for i in 1 to rows:
    for j in 1 to cols:
        P[i][j] =   P[i-1][j]     # sum all elements of row above 
                    + P[i][j-1]   # sum of all elements of column before
                    - P[i-1][j-1] # remove duplicate sum
                    + A[i]        # consider element itself
```