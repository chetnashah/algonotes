

##

https://leetcode.com/problems/remove-k-digits/

##

Given a number in the form of a string, 
and an integer `k`,

Remove `k` digits from string to make it as small as possible

## Examples

1. `20`, `k = 1` => ans = `0`
2. `1313562`, `k = 2` => ans = `11352`


## Solution

### Iterate elements and try putting them in stack, moving from left to right

### While trying to add element to stack, inspect top of stack to remove larger numbers, till K allows.

Proof: When moving from left to right, ignoring large elements helps us lexicographically have a small number.

Think of a number with peaks:
`15151` -> two peaks of `5`, remove the one on the left gives us min ans -> `1151`.

### If we have some k remaining after processing all elements, mostly larger numbers will be there at the end of stack, remove them till K allows

e.g. `12357`, k=2, 
Processing stack will remove nothin,
and k=2 remains, so remove 2 chars from the end answer -> `123` 




