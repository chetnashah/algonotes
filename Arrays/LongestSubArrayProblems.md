
Can also try this approach for longest substring problems

An example problem, longest subarray with max k zeros.

## For each possible start index, try to see if we can do the binary search on end pointer

For a given start index, if it is possible to have a bunch of T followed by bunch of Fs for end pointer predicate,
we can try to do binary search (the end pointer for every start pointer).

## When can we do two pointers (dynamic sliding window)?

Let origianl window be `[L..R]`,
and next possible valid window be `[L'..R']`,
and if `L<L'` => `R<=R'`, then we can use two pointers.

### Pointer update conditions

* Move right/end pointer as far as possible till window is valid, this is a window size maximization step, so we like to do it as much as possible.
* Once window is invalid, move left/start pointer only enough (i.e. minimally) to make window valid again. (Sometimes this is complete window reset e.g. L = R+1, or sometimes this is condition based). This is a window size minimization step, so we like to do this as less as possible.




