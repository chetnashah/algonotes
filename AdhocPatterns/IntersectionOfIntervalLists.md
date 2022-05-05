
## Give two lists of intervals, find intersection intervals of these two lists

Two variants of this problem: sorted (by their start times) & un-sorted. In unsorted case, just sort them first, if allowed complexity is O(N lg N).
**Implementation is really tricky, if you do not follow the six cases like mentioned below**

## Two pointers technique can be used

We will use pointer `i` for 1st list intervals iteration
and use pointer `j` for 2nd list intervals iteration

### Conditions for incrementing pointers is done on case by case basis

### No overlap cases first

1. `i.start > j.end` - j ends before i starts, no need to consider j, so j++
2. `j.start > i.end` - i ends before j starts, no need to consider i, so i++

### total overlap cases next

1. `i.start >= j.start and i.end <= j.end` - i is completely inside j, so i++ 
2. `j.start >= i.start and j.end <= i.end` - j is completely inside i, so j++ 

### Partial overlap cases finally

If none of the cases above have matched, there is a partial overlap possibility
1. `i.start < j.end and i.start > j.start` - i's start overlaps within j, not the end. we are going j -> i, so j++
2. `i.end > j.start and i.end < j.end` - i's end overlaps within j, not the start. we are going i -> j, so i++

## Mistakes I made

* Put else-if for exclusivity of all cases.
* Did not follow these 6 cases mentioned like above which led to 2 hrs of debugging.


