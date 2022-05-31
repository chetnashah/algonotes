
### How many array items are present between index i & j, both elements inclusive i.e. |[i..j]|?

Ans: `j - i + 1`, assuming `j > i`

e.g.
0 1 2 3 4 5 - indexes
1 1 1 1 1 1 - values

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

### `mid = (hi - lo)/2`, where `hi = 0` and `lo = lst.length - 1` are index of first and last element

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
