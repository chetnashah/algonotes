
##

##

##

Let `n` be the length of the board and `m` be the length of input moves.

## Minor optimization - check if each players moves are >= n (greater than or equal to n)

if both players moves are less than `n`, the game is still pending and winner cannot be decided

## Brute force - try all rows, columns, diagonals and check

This is good, but wasteful if board is too large. 

## Improved approach (linear in the number of moves)



