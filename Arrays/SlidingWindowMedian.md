
##

https://leetcode.com/problems/sliding-window-median/

## Two heaps approach (Max heap holds first half of elements, min heap holds larger half of elements):

// either both the heaps will have equal number of elements or max-heap will have one 
// more element than the min-heap


## Gotchas/Learnings

Gotchas: **how do we remove elements from heap**?
We have to do a linear search in the heap which is O(K).
PriorityQueue provides a method to remove by ref object in O(N):
https://docs.oracle.com/javase/7/docs/api/java/util/PriorityQueue.html#remove(java.lang.Object)

Tricky test case:
```
[-2147483648,-2147483648,2147483647,-2147483648,-2147483648,-2147483648,2147483647,2147483647,2147483647,2147483647,-2147483648,2147483647,-2147483648]
3
```
Note -> **do not use comparator: `(a,b) -> b-a` to avoid this error.**

## Code

```java
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        // Note: the median of window is middle number in sorted order (of window)
        // max heap has first half elements of sorted order, 
        // min heap has second half elements of sorted order.
        PriorityQueue minHeap = new PriorityQueue<Integer>();
        PriorityQueue maxHeap = new PriorityQueue<Integer>(Collections.reverseOrder());// reverse order
        
        double[] ans = new double[nums.length-k+1];// there are n-k+1 windows
        
        int j = 0;
        for(int i=0;i<nums.length;i++) {
            // which heap should the element go
            if(maxHeap.size() == 0 || nums[i] <= (int)maxHeap.peek()) {// it should go in first half
                maxHeap.add(nums[i]);
            } else {
                minHeap.add(nums[i]);
            }
            // rebalance steps
            if(maxHeap.size() > minHeap.size() +1) {
                minHeap.add(maxHeap.remove());
            } else if (minHeap.size() >= maxHeap.size() + 1) {// invarant we want to keep: max has more elements
                maxHeap.add(minHeap.remove()); 
            }
            if(i >= k-1) {// first window reached, time to start calculating stuff
                ans[j++] = getMedianFromHeaps(minHeap, maxHeap);
                
                // remove outgoing element
                boolean removedFromFirst = maxHeap.remove(nums[i-k+1]);
                if(!removedFromFirst) {
                    minHeap.remove(nums[i-k+1]);
                }
            }
        }
        return ans;
    }
    
    double getMedianFromHeaps(PriorityQueue<Integer> min, PriorityQueue<Integer> max) {
        double ans;
        // System.out.println("minHeap = "+min);
        // System.out.println("maxHeap = "+max);
        if(min.size() == max.size()) {
            return (min.peek()/2.0) + (max.peek()/2.0);
        }
        ans = max.peek();
        // System.out.println("returning ans = "+ans);
        return ans;
    }
}
```