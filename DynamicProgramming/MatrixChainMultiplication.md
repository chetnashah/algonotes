
## Goal

Minimize no. of multiplications needed for multiplying a chain of matrices
e.g. A x B x C x D x E

## Cost of multiplying two matrices A and B

if A is of dimension `i x j`, and B is of dimension `j x k`,
then cost of multiplying A x B is `i x j x k`.

Proof: The size of final matrix is `i x k`. To calculate each value of final matrix, we need to do `j` multiplications (This is by matrix multiplication property).

## Multiplication order matters

Depending on the order of which matrix multiplication happens first, we would have more or less no of multiplications:
e.g. 
Let:
A: `4 x 2`
B: `2 x 3`
C: `3 x 1`
D: `1 x 3`

For ((AxB)xC)xD: 4x2x3 + 4x3x1 + 4x1x3 = 48

For (Ax(BxC))xD: 2x3x1 + 4x2x1 + 4x1x3 = 26

## Dp state

If you N matrices to multiply,
create a `dp[N][N]` table.

subproblem: If I have a answer for a smaller matrix chain e.g. i..j, 
i.e. `dp[i][j] = min mults needed to multiply all matrices from ith matrix to jth matrix, i <= j`

