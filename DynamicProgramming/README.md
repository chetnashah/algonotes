

It's a tradeoff for sacrificing some space to get some time.

A technique for efficiently implement a recursive algorithm by storing partial results. Trick is to seeing whether naive recursive algorithm computes same subproblems over and over.

each decision may influence future decisions

Once we have a correct recursive algorithm, then we worry about speeding it up by using a results matrix.

**Note** - DP is right method for optimization problems on combinatorial objects that have an inherent left to right order e.g.
1. charachter strings.
2. rooted trees.
3. polygons.
4. Integer sequences.


## Try to come up with state

Maybe 1d or 2d.


## Try to come up with recurrence i.e. brute force recurrence

recurrence will help to transition between states.

## Notice repeated solving of sub problems

## Memoize solved problems

