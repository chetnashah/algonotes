

##

A derangement - Permutation such that no element appears in its original position

## Formula

`F(n) = (n - 1) * [ F(n - 1) + F(n - 2) ]`

## Proof

TODO



## Variation: de-arrange to maximize dearrangements

E.g.
for `[1,2,2,2,3]`

###  only count derangements - IDea: sort by freq dec, and rotate the whole array by maxFreq

Basically if you rotate by max freq, rest of elements are not goint to collide i.e. result in arrangement.

E.g.
for `[1,2,2,2,3]`
sorted by decreasing freq = `[2,2,2,1,3]` -> max freq = 3.
rotating original array by 3, we have
`[1,2,2,2,3]`
`[2,2,3,1,2]` -> here we see `4 derangements`, only one `2` goes to `2`.

### Building the final derangement (which is maximally deranged from original array)

1. add index at denominator
2. sort by inc freq. and capture max freq
3. shift by max freq
4. place numerator to denom index before shift. -> This is the answer ( why are we doing this step, because sorted and shifted arr have maximum derangements)

e.g.`[1,2,3,2,2]`

Saving them with their index:
`[1/0,2/1,3/2,2/3,2/4]`
Sorting by inc or dec freq:
`[1/0],[3/2],[2/1],[2/3],[2/4]`
shifted by max freq we have:
`[2/1], [2/3], [2/4], [1/0], [3/2]`

try to place numerator at `arr[denominator of prevstep]` (i.e before rotation)
e.g. 2 -> 0
2 -> 2
2 -> 1
1 -> 3
3 -> 4
i.e.          `[2,2,2,1,3]`
compared with `[1,2,3,2,2]` is 4 derangements

####
Another example: 
`[1,4,2,6,4,2]`
keeping index as denominator
`[1/0,4/1,2/2,6/3,4/4,2/5]`
Sorting by freq:
`[1/0,6/3,2/2,2/5,4/1,4/4]`
Rotate by maxFreq = 2:
`[4/1,4/5,1/0,6/4,2/2,2/6]`

We must place
4 -> 0
4 -> 3
1 -> 2
6 -> 5
2 -> 1
2 -> 4
i.e.
ans  = `[4,2,1,4,2,6]`
orig = `[1,4,2,6,4,2]` -> comparing we see 6 derangements


