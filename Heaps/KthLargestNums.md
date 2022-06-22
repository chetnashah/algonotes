
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

## Randomized quickselect approach

Refer [Randomized quicksort](../sorting/../Sorting/QuickSelect.md) for randomized partitioning.

### code

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {

        int elFixed = randPartition(0,nums.length-1, nums);
        int finalPos = nums.length-k;
        
        while(elFixed != finalPos) {
            if(elFixed < finalPos) {
                elFixed = randPartition(elFixed+1, nums.length-1, nums);
            } else {
                elFixed = randPartition(0, elFixed-1, nums);
            }
        }
        return nums[elFixed];
    }
    
    public static int partition(int l, int r, int[] arr) {
        if(l >= r) {
            return l;
        }
        
        // lowest is pivot
        int m = l;
        for(int i=m+1;i<=r;i++) {
            if(arr[i] < arr[l]) {
                m++;
                // System.out.println("m = "+m);
                swap(arr, m, i);
            }
        }
        // System.out.println("m = "+m+" l = "+l);
        swap(arr, m, l);
        return m;
    }
    
    public static int randPartition(int l, int r, int[] arr){
        // System.out.println("l = " + l +" r = " + r);
        if(l >= r) {
            return l;
        }

        // pick a random index and swap with arr[l]
        int randIdx = l+(int)(Math.random() * (r-l+1));
        // System.out.println("randIdx = " + randIdx);
        swap(arr, randIdx, l);

        // continue wth original partition scheme
        return partition(l, r, arr);
    }
    
    public static void swap(int[] arr, int p, int q) {
        int temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
    }

}
```