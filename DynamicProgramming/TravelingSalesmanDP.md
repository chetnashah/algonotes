
Also known as Held-karp DP algorithm

## Resources

https://www.youtube.com/watch?v=cY4HiiFHO1o

https://www.youtube.com/watch?v=-JjA4BLQyqE

https://www.youtube.com/watch?v=D8aHqaFa8GE

## Goal

Given `n` cities, complete graph, it is possible to go from every city to every city. ( in case some edges are missing, put a really large weight like infinity so they never get picked)

Given pairwise distances in form of symmetric `n x n matrix of distances` (complete undirected weighted graph matrix)

`Compute minimum cost of making a tour (hamiltonian tour)` i.e. visit each vertex exactly once and return to starting vertex

You can start with any city `s`.

Goes through all `n-1` other cities exactly once.

Finally returns to starting vertex `s`.

In essence - find min cost hamiltonion cycle path in a complete undirected weighted graph where you can start at any vertex.

## complete search approach

We can pick to start with any of n vertex as starting vertex.
For each vertex chosen, any of the other n-1, n-2, ... vertex can be chosen.
Resuling in `O(n!)` complexity.

Note - all permutations of TSP tour have different answers.
Note - asymmetric nature -> cost of going from 1 to 2 might not be the same as cost of going from 2 to 1.

1-5-2-3-4-1 tour is same as 5-2-3-4-1-5 -> (n-1)! solutions due to symmetry related duplicated counting.

## DP algorithm O(n^2 * 2^n)

With n = 23, 
O(n^2 * 2^n) = 529 * 8388608
4,437,573,632 ~ 4 billion ops

### Core idea

Reuse info from smaller/shorter paths already taken

Pick node `S` randomly , `0 <= S < N`, it does not matter about picking start vertex because we are computing a cycle anyway, and in any case that node would have ended up in the cycle with same neighbours

No subtours allowed - do not do sub-cycles.

### visited nodes as bit field

best way to represent set of visited nodes is single 32-bit integer.
