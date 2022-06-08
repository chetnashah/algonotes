

###

https://leetcode.com/problems/employee-free-time/

### TODO 

make use of info that all given schedules are already sorted and use a priority queue.

### 

```java
/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        // sorted by start time
        Comparator<Interval> sortOnStart = new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                int compareFirst = Integer.compare(i1.start, i2.start);
                if(compareFirst == 0) {
                    return Integer.compare(i1.end, i2.end);
                }
                return compareFirst;
            }
        };

        TreeSet<Interval> intervalSet = new TreeSet<Interval>(sortOnStart);// we can put everything in one set and process in order
        
        for(int i=0;i<schedule.size();i++) {
            List<Interval> ithEmpSchedule = schedule.get(i);
            for(int j = 0; j<ithEmpSchedule.size();j++) {
                intervalSet.add(ithEmpSchedule.get(j));
            }
        }
        
        List<Interval> ans = new ArrayList<>();
        List<Interval> list = new ArrayList<>(intervalSet);
        int start = list.get(0).start;
        int end = list.get(0).end;
        for(int i=0;i<list.size();i++){
            // System.out.println("[ " + list.get(i).start+ ", "+list.get(i).end+" ]");
            Interval i1 = list.get(i);
            if(i1.start > end) { // we found a gap between last seen end and new interval start, so record it
                ans.add(new Interval(end, i1.start));
                start = i1.start;
                end = i1.end;
            } else { // intersecting
                end = Math.max(i1.end,end);// greedily update the end seen so far
            }
        }
        
        return ans;
    }
}
```