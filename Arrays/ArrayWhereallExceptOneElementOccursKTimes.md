
##

Given an array where aevery element occurs K times, except one element which occurs only once.
Find this element which occurs only once

##
E.g.
```
Input: [23,5,23,4,23,4,5,3,5,4] => 3
Output = 3
```

## Core Idea

Do a digitwise sum of all elements,
For elements that cancel out, digit sum should be divisible by3, whatever remains is extra in the answer e.g.

take: `[7,7,7,6]`

| `7` | 1   |  1  |  1  |
|:---:|:---:|:---:|:---:|
| `7` |  1  |  1  |  1  |
| `7` |  1   |  1  |  1 |
| `6` |  1  |  1  |  0  |
| Ans | 1+1+1 + 1 % 3 = 1 | 1+1+1 +1 %3 = 1 | 1+1+1 %3 = 0|
| Ans | 1   |  1  |  0  |


