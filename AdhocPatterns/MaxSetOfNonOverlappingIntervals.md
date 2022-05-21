
## Description

Also known as `activity selection problem`.

Given N activities with their start time and end time. The task is to find the solution set having a maximum number of non-conflicting activities that can be executed within the given time, assuming only a single activity can be performed at a given time

## Examples

Input: start[] = [10, 12, 20}]         
          end[] =  [20, 25, 30]
Output: [0, 2]
Explanation: A maximum of two activities can be performed, i.e. Activity 0 and Activity 2[0-based indexing]. 

Input:  start[]  =  [1, 3, 0, 5, 8, 5]
finish[] =  [2, 4, 6, 7, 9, 9]
Output: [0, 1, 3, 4]
Explanation: A maximum of four activities can be performed, i.e. Activity 0, Activity 1, Activity 3, and Activity 4[0-based indexing]. 

## Technique

### Sort by end times

### Pick acitivity intervals with min end time greedily and discard the ones that conflict with it

## Code

```java
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0) {
            return 0;
        }
        Arrays.sort(points, (a,b) -> Integer.compare(a[1], b[1]));
        int lastIntervalStart = points[0][0];
        int lastIntervalEnd = points[0][1];
        int cnt = 1;
        for(int i=1;i<points.length;i++) {
            int[] currentInterval = points[i];
            if(currentInterval[0] > lastIntervalEnd) { // pick interval if exclusive with prev one
                cnt++;
                lastIntervalStart = currentInterval[0];
                lastIntervalEnd = currentInterval[1];
            }
        }
        return cnt;
    }
```
