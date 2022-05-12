

## Variant 1 : Count BSTs with N nodes

## Variant 2 : Construct/count all parantheses combninations
https://leetcode.com/problems/generate-parentheses/

## Recurrence

```
C(n+1) = C(0) * C(n) + C(1) * C(n-1) + ... + C(n) * C(0)
```
Where
`C(0) = 1,C(1) = 1`

