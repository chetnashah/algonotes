
## 

https://ocw.tudelft.nl/wp-content/uploads/Algoritmiek_Interval_partitioning.pdf

https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pearson/04GreedyAlgorithms-2x2.pdf

##

Given a list of possibly overlapping intervals,
find minimum number of partitions/rooms/servers needed to schedule all intervals.

## Insight: depth of intervals list

`depth`: max no of intervals intersecting at  a given time.

## no. of partitions needed >= depth

## Sort intervals by start time

## Greedy Algorithm

```
Sort intervals by starting time so that s1 ≤ s2 ≤ ... ≤ sn.
d ← 0

for j = 1 to n {
 if (lecture j is compatible with some classroom k)
    schedule lecture j in classroom k
 else
    allocate a new classroom d + 1
    schedule lecture j in classroom d + 1
    d ← d + 1
}
```

## Implementation details

* For each classroom `k`, maintain finish time of last job added.
* Put all `<finishtimes, roomId>`, in a min priority queue, ordered by earliest finishtime (which is seen as a best fit).

## Proof

* Let d = number of classrooms that the greedy algorithm allocates.
* Classroom `d` is opened because we needed to schedule a job, say `j`,
that is incompatible with all `d-1` other classrooms.

* These d jobs each end after `s[j]`.

* Since we sorted by start time, all these incompatibilities are caused
by lectures that start no later than `s[j]`.

* Thus, we have d lectures overlapping at time `s[j] + ε`.
* Key observation ⇒ all schedules use ≥ d classrooms.

## Code

```java
class FinishTimeRoomPair {
    public int finishTime;
    public int roomNo;
    
    FinishTimeRoomPair(int f, int r) {
        finishTime = f;
        roomNo = r;
    }
}

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        if(intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0]));
        int rooms = 1;
        PriorityQueue<FinishTimeRoomPair> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.finishTime, b.finishTime));
        
        pq.add(new FinishTimeRoomPair(intervals[0][1],1));
        for(int i=1;i<intervals.length;i++){
            int[] currentInterval = intervals[i];
            FinishTimeRoomPair ftpr = pq.peek();
            if(currentInterval[0] < ftpr.finishTime) { // current one starts before earliest known finish time
                rooms++;// new room needs to be added due to missing compatibility
                pq.add(new FinishTimeRoomPair(currentInterval[1], rooms));
            } else {
                pq.poll();// remove the best fit, we will update the same.by adding to pq again
                int bestknownroomId = ftpr.roomNo;
                pq.add(new FinishTimeRoomPair(currentInterval[1], ftpr.roomNo));
            }
        }
        return rooms;
    }
}
```