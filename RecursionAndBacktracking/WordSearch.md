
Search word in grid:

https://leetcode.com/problems/word-search/


## MySolution

```java
class Coordinate {
    int row;
    int col;
    
    Coordinate(int r, int c) {
        this.row = r;
        this.col = c;
    }
}

class Solution {
    boolean [][] visited;
    boolean ans = false;
    public boolean exist(char[][] board, String word) {
        if(word == null || word.length() == 0) {
            return true;
        }
        
        int rows = board.length;
        int cols = board[0].length;
        visited = new boolean[rows][cols];
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(board[i][j] == word.charAt(0)) {
                    // reset visit grid
                    for(int p=0;p<rows;p++) {
                        for(int q=0;q<cols;q++) {
                            visited[p][q] = false;
                        }
                    }
                    // start backtracking
                    backtrackHelper(""+board[i][j], 0, new Coordinate(i,j), word, board);
                    if(ans) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
    
    public boolean withinBounds(Coordinate coordinate, char[][] board) {
        if(coordinate.row >=0 && coordinate.row < board.length && coordinate.col >= 0 && coordinate.col< board[0].length) {
            return true;
        }
        return false;
    }
    
    // cnt is the index of current charachter being considered for traversing
    void backtrackHelper(String curr, int cnt, Coordinate cell, String word, char[][] board) {
        if(ans == true) {
            // System.out.println("ans true returning early");
            return;
        }
        visited[cell.row][cell.col] = true;
        
        // curr is smaller than word length
        if(curr.charAt(cnt) != word.charAt(cnt)) {
            // System.out.println("non matching during recursion, return early: "+ curr);
            visited[cell.row][cell.col] = false;// unvisit
            return;
        }

        // termination
        if(curr.length() == word.length()) {
            if(curr.equals(word)) {
                // System.out.println("found word");
                ans = true;
            } else {
                // System.out.println("not found : curr = " + curr);
            }
            return;
        }
        
        
        int[][] dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        // recurse with options
        for(int i=0; i<dirs.length; i++) {
            Coordinate nextCoordinate = new Coordinate(cell.row+dirs[i][0], cell.col+dirs[i][1]);
            if(withinBounds(nextCoordinate, board) && !visited[nextCoordinate.row][nextCoordinate.col]) {   
                backtrackHelper(curr+board[nextCoordinate.row][nextCoordinate.col], cnt+1, nextCoordinate, word, board);
                visited[nextCoordinate.row][nextCoordinate.col] = false;// necessary for backtracking continue
            }
        }
    }
}
```