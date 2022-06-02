

## Requirement rotate a image by 90 degree right in constant space

| 1 | 2 | 3 | 4 |
| --- | --- | --- | --- |
| 5 | 6 | 7 | 8 |
| 9 | 10 | 11 | 12 |
| 13 | 14 | 15 | 16 |

and the final ans is:

| 13 | 9 | 5 | 1 |
| --- | --- | --- | --- |
| 14 | 10 | 6 | 2 |
| 15 | 11 | 7 | 3 |
| 16 | 12 | 8 | 4 |


## Core idea = 4 way swap starting from corners to next cell.

Initial state:
| 1 | 2 | 3 | 4 |
| --- | --- | --- | --- |
| 5 | 6 | 7 | 8 |
| 9 | 10 | 11 | 12 |
| 13 | 14 | 15 | 16 |

After 4-way swap of corners we get: `1, 4, 16, 13`

| 13 | 2 | 3 | 1 |
| --- | --- | --- | --- |
| 5 | 6 | 7 | 8 |
| 9 | 10 | 11 | 12 |
| 16 | 14 | 15 | 4 |

Do 4-way swap of next set of elements: `2, 8, 15, 9`

| 13 | 9 | 3 | 1 |
| --- | --- | --- | --- |
| 5 | 6 | 7 | 2 |
| 15 | 10 | 11 | 12 |
| 16 | 14 | 8 | 4 |

Do one more 4-way swap of next set of elements: `3, 12, 14, 5`
| 13 | 9 | 5 | 1 |
| --- | --- | --- | --- |
| 14 | 6 | 7 | 2 |
| 15 | 10 | 11 | 3 |
| 16 | 12 | 8 | 4 |

now repeat the process for inner rectangle

## Each inner rectangle is independent, so you can go from outer rectangle to inner rectangle

Repeat the same procedure mentioned above but for inner rectangles.