
https://sedgewick.io/wp-content/themes/sedgewick/talks/2002PermGeneration.pdf

https://academic.oup.com/comjnl/article/6/3/293/360213?login=false

### Generating permutations via recursion


### Find next permutation

https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

Main idea: Just like when we count up using numbers, we try to modify the rightmost elements and leave the left side unchanged.

Consider permutation: `1 2 5 4 3`

#### Core Idea 1: find longest decreasing suffix i.e non-increasing i.e. same elements allowed

This suffix is already the largest permutation so no point modifying it internally, we have to modify something to the left of it, we try to go minimum to the left

In above example it is **1 2 `5 4 3`**

| 1   | 2    | `5`   | `4`     | `3`   |
|:---:|:---: |:---:  |:---:    |:---:|


#### Core idea 2: nearest left element (to the decreasing suffix) is the pivot
element immediately to the left of the suffix (in the example it’s `2`) and call it the pivot.
Note that pivot will always be less than head of suffix.

| 1   | 2    | `5`   | `4`     | `3`   |
|:---:|:---: |:---:  |:---:    |:---:|
|     | pivot|  suffix start     |         | suffix end    |

If there is no such element – i.e. the entire sequence is non-increasing – then this is already the last permutation.
Meaning everything is decreasing, there is no way to go to next permutation, if there is no pivot.

#### Core idea 3: Find element in suffix that is greater than the pivot, and swap with it

In our case `3` is in smallest elemnt in the suffix larger than pivot

| 1   | 2    | `5`   | `4`     | `3`   |
|:---:|:---: |:---:  |:---:    |:---:|
|     | pivot|       |         | smallest element in suffix larger than pivot     |

after swap

| 1   | 3    | `5`   | `4`     | `2`   |
|:---:|:---: |:---:  |:---:    |:---:|

#### Core Idea 4: sort the suffix in non-decreasing (i.e. weakly increasing) order

because we increased the prefix, so we want to make the new suffix as low as possible. In fact, we can avoid sorting and simply reverse the suffix, because the replaced element respects the weakly decreasing order

| 1   | 3    | `5`   | `4`     | `2`   |
|:---:|:---: |:---:  |:---:    |:---:|
|     |      | reverse start|  | reverse end|

Our answer:

| 1   |  3   |  2   |   4   |   5  |
|:---:|:---:|:---:|:---:|:---:|


### Kth permutation of a array

https://www.youtube.com/watch?v=wT7gcXLYoao

Core Idea:
if you fix first digit, there will be remaining (n-1)! numbers in that group.
the group can be skipped or picked depending on value of k, according to lexicographic order

e.g. 
n = 4 => 24 permutations
k = 16th permutation.

In sorted/lexicographic order:
1,[2,3,4]! = 6 perms
2,[3,1,4]! = 6 perms
3,[1,2,4]! => pick here because between 12th to 18th permutations 
4,[1,2,3]! => 6 perms