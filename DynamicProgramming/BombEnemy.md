

## Idea create 4 grids, one saves leftToRightSoldiersSeen, next saves RightToLeftSoldiersSeen, third saves TopToBottomSoldiersSeen and last one saves BottomToTopSoldiersSeen



## Code

```java
class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int[][] upToDownGrid = new int[grid.length][grid[0].length];
        int[][] downToUpGrid = new int[grid.length][grid[0].length];
        int[][] leftToRightGrid = new int[grid.length][grid[0].length];
        int[][] rightToLeftGrid = new int[grid.length][grid[0].length];

        int numRows = grid.length;
        int numColumns = grid[0].length;
        
        // fill left to right grid
        for(int i=0;i<numRows;i++) {
            int soldiersSeen = 0;
            for(int j=0;j<numColumns;j++) {
                if(grid[i][j] == 'E') {
                    soldiersSeen++;
                }
                leftToRightGrid[i][j] = soldiersSeen;
                if(grid[i][j] == 'W') {
                    soldiersSeen = 0;
                }
            }
        }
        
        // printGrid(leftToRightGrid);
        
        // fill right to left grid
        for(int i=0;i<numRows;i++) {
            int soldiersSeen = 0;
            for(int j=numColumns-1;j>=0;j--) {
                if(grid[i][j] == 'E') {
                    soldiersSeen++;
                }
                rightToLeftGrid[i][j] = soldiersSeen;
                if(grid[i][j] == 'W') {
                    soldiersSeen = 0;
                }
            }
        }
        
        // printGrid(rightToLeftGrid);

        // fill top to bottom
        for(int i=0;i<numColumns;i++) {
            int soldiersSeen = 0;
            for(int j=0;j<numRows;j++) {
                if(grid[j][i] == 'E') {
                    soldiersSeen++;
                }
                upToDownGrid[j][i] = soldiersSeen;
                if(grid[j][i] == 'W') {
                    soldiersSeen = 0;
                }
            }
        }
        
        // printGrid(upToDownGrid);
        
        // fill bottom to up
        for(int i=0;i<numColumns;i++) {
            int soldiersSeen = 0;
            for(int j=numRows-1;j>=0;j--) {
                if(grid[j][i] == 'E') {
                    soldiersSeen++;
                }
                downToUpGrid[j][i] = soldiersSeen;
                if(grid[j][i] == 'W') {
                    soldiersSeen = 0;
                }
            }
        }
        
        // printGrid(downToUpGrid);
        
        int maxKilled = 0;
        // find max enemies killed by bomb
        for(int i =0;i<numRows;i++) {
            for(int j=0;j<numColumns;j++) {
                if(grid[i][j] != '0') {
                    continue;
                } else {
                    maxKilled = Math.max(maxKilled, 
                                            leftToRightGrid[i][j] + rightToLeftGrid[i][j]
                                            +upToDownGrid[i][j] + downToUpGrid[i][j]);
                }
            }
        }
        
        return maxKilled;
        
    }
    
    public void printGrid(int[][] grid) {
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("-----");
    }
}
```