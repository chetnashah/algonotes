


##

https://leetcode.com/problems/paint-house/

## Code

```java
class Solution {
    int[][] ans;
    public int minCost(int[][] costs) {
    
        ans = new int[costs.length][3];
        for(int i=0;i<ans.length;i++) {
            for(int j=0;j<3;j++) {
                ans[i][j] = -1;
            }
        }
        
        int finalAnsRed = getMinCostTillIthHouse(costs.length -1, 0, costs);
        int finalAnsBlue = getMinCostTillIthHouse(costs.length -1, 1, costs);
        int finalAnsGreen = getMinCostTillIthHouse(costs.length -1, 2, costs);
        
        return Math.min(finalAnsRed, Math.min(finalAnsBlue, finalAnsGreen));
    }
    
    // get best cost for painting ith house with given color
    int getMinCostTillIthHouse(int i, int color, int[][] costs) {
        if(i == 0) {
            return costs[0][color];
        }
        
        if(ans[i][color] != -1) {
            return ans[i][color];
        }
        
        // try smaller sub-problem with different colors
        int bestCurrentChoice = costs[i][color] + Math.min(
            getMinCostTillIthHouse(i-1, (color+1)%3, costs),
            getMinCostTillIthHouse(i-1, (color+2)%3, costs)
        );
        
        ans[i][color] = bestCurrentChoice;
        return ans[i][color];
    }
}
```

## Variant: K colors instead of 3 colors

```java
class Solution {
    int [][] ans;
    public int minCostII(int[][] costs) {
     
        // k colors
        int k = costs[0].length;
        int minFinalHouse = Integer.MAX_VALUE;
        
        ans = new int[costs.length][k];
        for(int i=0;i<costs.length;i++) {
            for(int j=0;j<k;j++) {
                ans[i][j] = -1;
            }
        }
        
        for(int i=0;i<k;i++) {
            // try k colors to paint the last house and recursively solve the rest
            int currentFinalCost = getMinCostTillIthHouse(costs.length-1, i, costs, k);
            // keep track of the best
            if(currentFinalCost < minFinalHouse) {
                minFinalHouse = currentFinalCost;
            }
        }
        
        return minFinalHouse;
    }
    
    int getMinCostTillIthHouse(int i, int color, int[][] costs, int k) {
        if(i == 0) {
            return costs[0][color];
        }
        
        if(ans[i][color] != -1) {
            return ans[i][color];
        }
        
        int minPrevHouse = Integer.MAX_VALUE;
        for(int j=1;j<k;j++){
            int costPrevHouse = getMinCostTillIthHouse(i-1, (color+j)%k, costs, k);
            if(costPrevHouse < minPrevHouse) {
                minPrevHouse = costPrevHouse;
            }
        }
        
        // try smaller sub-problem with different colors
        int bestCurrentChoice = costs[i][color] + minPrevHouse;
        
        ans[i][color] = bestCurrentChoice;
        return ans[i][color];
    }

}
```