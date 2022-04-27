

## Description

Longest Common Subsequence problem, also known as LCS, the goal is for given two strings `S[1..n]` and `T[1..m]`, to find the length of their longest common subsequence. This is a classical problem which can be solved efficiently using dynamic programming approach. 

The idea is to compute `f[i][j]`, which is the length of the longest common subsequence of `S[1..i]` and `T[1..j]`. 

The value of `f[i][j]` can be computed in this problem knowing the values of `f[i-1][j]`, `f[i-1][j-1]` and `f[i][j-1]`. 

Then the final answer is the value of `f[n][m]`. In this approach, an entry in  table is called a state, and since the table is 2-dimensional, this dynamic programming solution is 2-dimensional

