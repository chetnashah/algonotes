

## Sort by start time

## Iterate and check for overlap between current and previous


## Code

```java
    public boolean canAttendMeetings(int[][] intervals) {
        if(intervals.length == 0) {
            return true;
        }
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        
        int lastStart = intervals[0][0];
        int lastEnd = intervals[0][1];
        
        for(int i=1;i<intervals.length;i++) {
            int[] currentInterval = intervals[i];
            if(currentInterval[0] < lastEnd) {
                return false;
            }
            lastStart = currentInterval[0];
            lastEnd = currentInterval[1];
        }
        return true;
    }
```