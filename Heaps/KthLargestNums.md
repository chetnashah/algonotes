
## Put everything in an opposite priority queue 

### Min priority queue for K largest

### Max priority queue for K smallest

### Where I got stuck

Edge case: `nums = [1]`, `k = 1`.
I got index out of bounds exception, answer should be 1.
Mistake: wrong index while adding to priority queue

One more failing test case:
`nums = [-1,2,0]`, k = 1, answer should be 2, 
My output was 0.
Mistake: wrong starting index for rest of the elements, should have started with i=k instead of i=k+1 for adding rest of elements.


### Code

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // java pq is min pq by default
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        // add first k elements
        for(int i=0;i<k;i++) {
            pq.add(nums[i]);
        }
        
        // add remaining elements, replacing from priority queue if we have better candidate
        for(int i=k;i<nums.length;i++) {
            if(nums[i]>pq.peek()) {
                pq.poll();
                pq.add(nums[i]);
            }
        }
        
        return pq.peek();
    }
}
```