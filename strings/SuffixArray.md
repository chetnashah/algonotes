
Reference : https://www.youtube.com/watch?v=Lu5sByCfPvE

Actually it should be named `sorted suffix array`, and it contains `integer starting indexes of suffixes after sorting`.

Let `s` be a string of length `n`.

A suffix array will contain integers that represent the starting indexes of the all the suffixes of a given string, after the aforementioned suffixes are sorted.

### What is the suffix array of "abaab" ?

Listing down all the suffixes:
* `0: abaab`
* `1: baab`
* `2: aab`
* `3: ab`
* `4: b`


Sorted order of suffixes:
* `2: aab`
* `3: ab`
* `0: abaab`
* `4: b`
* `1: baab`

So the following is called the `suffix (sorted) array` is `SA = [2, 3, 0, 4, 1]`,
`SA[i]` is `ith` lexicographically sorted suffix i.e. `s[SA[i]..[n-1]]` appears in ith position in all suffixes when sorted. 

### Create RANK array from suffix sorted array

For all i = 0 to n-1, `RANK[SA[i]] = i` 

For the above example RANK array will be
`i = 0, SA[0] = 2, RANK[2] = 0`
`i = 1, SA[1] = 3, RANK[3] = 1`
`i = 2, SA[2] = 0, RANK[0] = 2`
`i = 3, SA[3] = 4, RANK[4] = 3`
`i = 4, SA[4] = 1, RANK[1] = 4`

So `RANK = [2,4,0,1,3]`

### Suffix array construction brute force O(n^2 log n)

Its `N log N * N (cost of comparision of any two strings)`


### Suffix Array construction in O(n log n)

#### Adding dollar symbol (Smallest)

it is enough to append an arbitrary character to the end of the string which is smaller than any character from the string. 
It is common to use the symbol `$`

### LCP array

`LCP[0] = undefined`.
`LCP[i] = LCP(SA[i], SA[i-1])` i.e. longest common prefix between `s[SA[i]..n-1]` and `s[SA[i-1]..n-1]`

Gives longest common prefix between any two suffixes

#### LCP(i,j) = LCP between SA[i] and SA[j]

`LCP(i,j) = min(LCP(i+1), LCP(i+2), ... LCP(j))`
This means - checking all pairs of lcp in between and taking their minimum

