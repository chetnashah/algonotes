
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

### My code

```py
def merge(intervals_a, intervals_b):
    result = []
    # TODO: Write your code here
    i = 0 # start inside first list
    j = 0 # start inside second list

    while(i < len(intervals_a) and j < len(intervals_b)): ## process both pointers till something can be in common
        # cases where no overlap
        if (intervals_a[i][0] >= intervals_b[j][1]): # i starts after j ends
            j = j + 1
      
        elif (intervals_b[j][0] >= intervals_a[i][1]): # j starts after i ends
            i = i + 1

        # Complete overlap cases
        # i completely in j
        elif (intervals_a[i][0] >= intervals_b[j][0] and intervals_a[i][1] <= intervals_b[j][1]):
            result.append([intervals_a[i][0], intervals_a[i][1]])
            i = i + 1
        elif (intervals_b[j][0] >= intervals_a[i][0] and intervals_b[j][1] <= intervals_a[j][1]):
            result.append([intervals_b[j][0], intervals_b[j][1]])
            j = j + 1

        # partial overlap cases remaining
        # i's ending is overlas with j, start does not
        elif (intervals_a[i][1] > intervals_b[j][0] and intervals_a[i][1] < intervals_b[j][1]): # i -> j
            result.append([intervals_b[j][0], intervals_a[i][1]])
            i = i + 1
        # i's starting overlaps with j, end does not
        elif (intervals_a[i][0] > intervals_b[j][0] and intervals_a[i][0] < intervals_b[j][1]): # j -> i
            result.append([intervals_a[i][0], intervals_b[j][1]])
            j = j + 1

    # print("i = ", i, " j = ", j)
        # intervals remaining in i or j can be safely ignored since they would not intersect with anything

    return result
```

## TODO check how following code works

```java
class Solution {
  public int[][] intervalIntersection(int[][] A, int[][] B) {
    List<int[]> ans = new ArrayList();
    int i = 0, j = 0;// start pointers in both lists

    while (i < A.length && j < B.length) {  // till something can be in common
      // Let's check if A[i] intersects B[j].
      // lo - the startpoint of the intersection
      // hi - the endpoint of the intersection
      int lo = Math.max(A[i][0], B[j][0]);// max of start points
      int hi = Math.min(A[i][1], B[j][1]);// min of end points
      if (lo <= hi) {
        ans.add(new int[]{lo, hi});
      }

      // Remove the interval with the smallest endpoint
      if (A[i][1] < B[j][1])
        i++;
      else
        j++;
    }

    return ans.toArray(new int[ans.size()][]);
  }
}
```
