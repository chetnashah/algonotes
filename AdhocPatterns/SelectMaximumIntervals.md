
## Also known as interval scheduling problem

Given a list of intervals,
select maximum number of non-conflicting intervals.

## Sort by finish time & select greedily

In contrast with other interval problems, here one needs to sort by finish time, and then greedily select intervals with lowest finish time, and discard any intervals that intersect with it.



