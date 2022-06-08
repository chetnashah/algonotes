
## Bidirectional DP approach: Create two arrays maxLeftSeen and maxRightSeen

### To create maxLeftSeen iterate from left to right and record MaxSeen till index in array

### To create maxRightSeen iterate from right to left and record maxSeen from indext till the end

## Iterate array and you can get water trapped per block by querying maxLeftSeen and maxRightSeen

### Code


```java
class Solution {
    public int trap(int[] height) {
        int[] maxLeftSeen = new int[height.length];
        int[] maxRightSeen = new int[height.length];
        
        // fill the maxLeftSeen
        int maxSeen = height[0];
        for(int i=0;i<height.length;i++) {
            if(height[i] > maxSeen) {
                maxSeen = height[i];
            }
            maxLeftSeen[i] = maxSeen;
        }
        
        // fill the maxRightSeen
        maxSeen = height[height.length-1];
        for(int i=height.length-1;i>=0;i--) {
            if(height[i] > maxSeen) {
                maxSeen = height[i];
            }
            maxRightSeen[i] = maxSeen;
        }

        // calculate rain water trapped per column
        int trappedRainWater = 0;
        for(int i = 1; i< height.length-1;i++) { // no need to calculate for first or last block
            trappedRainWater = trappedRainWater + Math.min(maxLeftSeen[i], maxRightSeen[i]) - height[i];
        }
        return trappedRainWater;
    }
}
```


## Two pointers

## Using stacks
