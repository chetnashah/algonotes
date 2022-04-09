

### Generating permutations via recursion


### Find next permutation


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