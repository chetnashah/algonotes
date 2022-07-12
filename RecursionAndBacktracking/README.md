

## Three parts

1. early return/termination condition
2. work done by the function
3. Remaining work to be done by recursive part

2 & 3 can be done in any order

## Limits for permutation enumeration

For 10 element set, number of permutations is about 10! ~ 3M.
## Limits for subset enumeration

For 20 element set, number of subsets is about 2 ^ 20 which is about ~ 1M.


### next_permutation in cpp

As a part of `<algorithm>` header,
`next_permutaiton` helps get the next permutation of a given array,
assuming we have a comparision order between array elements and can swap them.
the range for permutation elements is given via `[start, end)`.

## State space visualization

Always put the first statement in the recursive function as the print statement that prints the state

## To properly indent call stack try adding padding to each statement

increment `nestCnt` in each recursive call

```java
String padding = String.join("", Collections.nCopies(nestCnt, " "));
```

