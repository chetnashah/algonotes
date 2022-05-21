
## Given single list of intervals, merge overlapping intervals

## interval cases

Given two intervals `a` and `b`, 
there are six possible cases:

1. no overlap: `a` first, `b` second
2. no overlap: `b` first, `a` second
3. `a` completely inside `b`
4. `b` completely inside `a`
5. `a` and `b` overlap: `a` finishes before `b`
6. `a` and `b` overlap: `b` finishes before `a`

## Interval class representation

```java
class Interval {
  int start;
  int end;

  public Interval(int start, int end) {
    this.start = start;
    this.end = end;
  }
};
```

## Sorting intervals

In Java:
Use `Collections.Sort`:
```java
Collections.sort(intervalsList, a, b -> Integer.compare(a.start, b.start))
```

In Python:
Use `sorted` function or `lst.sort`:
```python
intervals = [[1,2],[1,3],[3,5],[6,9],[4,5]]
print(sorted(intervals, key=lambda interval: interval[0]))

# in our case
intervals.sort(key=lambda x: x.start)
```

In C++ (Note the third argument is a c++ lambda):
```cpp
#include<algorithm>
sort(intervals.begin(), intervals.end(),
         [](const Interval &x, const Interval &y) { return x.start < y.start; });
```

In JS:
```js
intervals.sort((a,b) => a.start - b.start)
```

## Iterating on intervals (slightly tricky)

since every next interval has to be merged with a previous overlapping interval, we must maintain some extra information.

Keeping a separate array/vector for mergedIntervals is fine and helps in clarity.

`Iteration` based looping is **not recommended** here
e.g. `for interval in intervals:`, because you will not have access to next or previous intervals that way,
instead do index based iteration on the original list

Preprocess step befoe while loop:
```py
  # pre process first one
  intervals.sort(key=lambda x: x.start)
  
  # pre process for first interval needed.
  start = intervals[0].start
  end = intervals[0].end
```

And then checking remaining intervals:
```py
  for i in range(1, len(intervals)):
```

### when to push to `mergedIntervals` array?

Only push to mergedIntervals array only when you see the newest interval start greater than past intervals end combined.

### Edge cases

1. Maintian two extra variables `start` and `end` at the start which are used to compare against previous start/end insde the loop

2. At the end of the loop, don't forget to append the last interval processed

If iteration gets tricky, possibly try a `while` loop instead of a `for` loop where you can clearly reason about.

## Code

```py
def merge(intervals):
  merged = []
  # pre process first one

  intervals.sort(key=lambda x: x.start)
  
  # pre process for first interval needed.
  start = intervals[0].start
  end = intervals[0].end

  # check remaining intervals
  for i in range(1, len(intervals)):
    if(intervals[i].start > end):
      merged.append(Interval(start,end))
      # reset start,end
      start = intervals[i].start
      end = intervals[i].end
    else:
      start = min(start, intervals[i].start)
      end = max(end, intervals[i].end)

  # don't forget to append last interval accumulated
  merged.append(Interval(start,end))
  return merged

```

## Problem variant - find if two intervals overlap