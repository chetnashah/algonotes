
##

https://leetcode.com/problems/moving-average-from-data-stream/

##

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

`MovingAverage(int size)`: Initializes the object with the size of the window size.
`double next(int val)`: Returns the moving average of the last size values of the stream.


Example 1:
```
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
 ```

Constraints:
```
1 <= size <= 1000
-105 <= val <= 105
At most 104 calls will be made to next.
```


## Code

```java
class MovingAverage {

    int runningSum = 0;
    double runningAvg = 0.0;
    int numsSeen = 0;
    int windowSize;
    
    Queue<Integer> q;
    
    public MovingAverage(int size) {
        runningSum = 0;
        runningAvg = 0.0;
        numsSeen = 0;
        windowSize = size;
        q = new ArrayDeque<>();
    }
    
    public double next(int val) {
        numsSeen += 1;
        if(numsSeen <= windowSize) {
            q.add(val);
            runningSum += val;
            runningAvg = runningSum * 1.0 / numsSeen;

        } else {// window has moved
            runningSum -= q.remove();// remove the outgoing element
            runningSum += val;       // add incoming element in window
            q.add(val);
            runningAvg = runningSum * 1.0 / windowSize;
        }
        return runningAvg;
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```