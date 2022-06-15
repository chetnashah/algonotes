
##

Given an array where a every element occurs `K` times, except one element which occurs only once.
Find this element which occurs only once

##
E.g.
```
Input: k=3, arr=[23,5,23,4,23,4,5,11,5,4]
Output = 11
```

## Core Idea: cancelling off repeated numbers by taking digit wise sum and then modulo K.

Do a digitwise sum of all elements,
For elements that cancel out, digit sum should be divisible by3, whatever remains is extra in the answer 
Anything that was exact contributed thrice would go away with `%3` modulo.
e.g.

take: `[7,7,7,6], k=3, i.e. all except one elements repeats thrice`

| `7` | 1   |  1  |  1  |
|:---:|:---:|:---:|:---:|
| `7` |  1  |  1  |  1  |
| `7` |  1   |  1  |  1 |
| `6` |  1  |  1  |  0  |
| Ans | 1+1+1 + 1 % 3 = 1 | 1+1+1 +1 %3 = 1 | 1+1+1 %3 = 0|
| Ans | 1   |  1  |  0  |

Similarly this can be generalized to any `k` by taking `%k` per digit level sum.



