
## Idea 1: calculate depth levels before/after each charachter

depth level = no of open brackets seen till now, +1 if open brancket seen, -1 if close bracket seen.

e.g.
| ( | ( | ) | ) |

0   1   2   1   0

## Approach 1 (does not work): for any substring, see counter before first char, and counter after char, they should match

This approach is fine, but breaks down in an edge case:

Edge case:

| ( | ( | ) | ( | ( | ) | ) | ) |

0   1   2   1   2   3   2   1   0

        ^       ^               

If you see above substring, the counter is same, but string inside it is ")(", even though counts around string is same = 2.


