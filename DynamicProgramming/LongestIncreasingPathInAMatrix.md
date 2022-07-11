
##
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

## Core Idea

### DFS on each cell to get max path

### Memoize the answers for dp

## Code

```java
class Solution {
    int[][] lip;
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix.length == 1 && matrix[0].length == 1) {
            return 1;
        } 
        
        lip = new int[matrix.length][matrix[0].length];
        
        // observation: smalllest numbers or largest nums might or might not be on the longest path
        // so no point starting from the smallest/largest numbers
        
        int maxAns = 1;
        // try DFS for each cell with memoization
        for(int i=0;i<matrix.length;i++) {
            for(int j=0;j<matrix[0].length;j++) {
                // reset visit before new dfs
                maxAns = Math.max(maxAns, dfsLongestIncPath(i,j, matrix)); 
            }
        }
        
        return maxAns;
    }
    
    // try recursive first then memoize
    // ith row, jth column
    int dfsLongestIncPath(int i, int j, int[][] matrix) {
        if(lip[i][j] != 0) {
            return lip[i][j];
        }
        
        // no need of visited state check because if we visit an increasing edge, we never go back that edge anyways.
        
        int[][] dirs = new int[][]{{0,1}, {1,0}, {-1, 0}, {0, -1}};
        // visited[i][j] = 1;
        int maxPathLen = 1;
        
        for(int d=0;d<dirs.length;d++) {
            int nextCellRow = i + dirs[d][0];
            int nextCellColumn = j + dirs[d][1];
            if(nextCellRow >=0 && nextCellRow < matrix.length
                && nextCellColumn >=0 && nextCellColumn < matrix[0].length
              ) {
                if(matrix[nextCellRow][nextCellColumn] > matrix[i][j]) {
                    maxPathLen = Math.max(maxPathLen, 1 + dfsLongestIncPath(nextCellRow, nextCellColumn, matrix));
                }
            }
        }
        
        lip[i][j] = maxPathLen;
        return maxPathLen;
    }
}
```