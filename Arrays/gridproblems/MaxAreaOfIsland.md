
##

https://leetcode.com/problems/max-area-of-island/

## Core idea: Each DFS can report size/are of the island captured in the DFS, keep track of max size/area

## Code

```java
class Solution {
    boolean[][] visited;
    public int maxAreaOfIsland(int[][] grid) {
        visited = new boolean[grid.length][grid[0].length];
        int maxSize = 0;
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                if(grid[i][j] != 0 && !visited[i][j]) {
                    maxSize = Math.max(maxSize, dfsSize(i, j, grid));
                }
            }
        }
        
        return maxSize;
    }
    
    public int dfsSize(int i, int j, int[][] grid) {
        int[][] dirs = new int[][] {{0,1}, {1,0},{0,-1},{-1, 0}};
        visited[i][j] = true;
        int size = 1;
        
        for(int d=0;d<dirs.length;d++) {
            int nextRow = i+dirs[d][0];
            int nextColumn = j+dirs[d][1];
            
            if(nextRow < grid.length && nextRow >=0 && nextColumn < grid[0].length && nextColumn >= 0) {
                if(grid[nextRow][nextColumn] == 1 && !visited[nextRow][nextColumn]) {
                    size += dfsSize(nextRow, nextColumn, grid);
                }
            }
        }
        
        return size;
    }
}
```