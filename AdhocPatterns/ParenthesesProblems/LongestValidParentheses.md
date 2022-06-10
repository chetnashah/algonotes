

##

https://leetcode.com/problems/longest-valid-parentheses/

##

Understanding the bracket counter/depth idea from parentheses,
the main condition for valid parentheses, is to never go below starting depth in a window start bracket.

use a sliding window and greedily pick elements till the depth count is greater than or equal to start.

Update start pointer when you go below the start count of parentheses.

## Code

TODO
