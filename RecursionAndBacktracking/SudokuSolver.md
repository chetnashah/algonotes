



## State modeling:

```java
  int [][] rows = new int[N][N + 1];// first index is the row number, second index tells cnt of that digit we have placed in the row associated with first index
  int [][] columns = new int[N][N + 1];
  int [][] boxes = new int[N][N + 1];

  char[][] board;
```

For e.g. we have placed two `5`s in row `0`, then `rows[0][5] = 2`.

## Choice and Un-choice functions based on state above

```java
  public void placeNumber(int d, int row, int col) {
    /*
    Place a number d in (row, col) cell
    */
    int idx = (row / n ) * n + col / n;

    rows[row][d]++;
    columns[col][d]++;
    boxes[idx][d]++;
    board[row][col] = (char)(d + '0');
  }

  public void removeNumber(int d, int row, int col) {
    /*
    Remove a number which didn't lead to a solution
    */
    int idx = (row / n ) * n + col / n;
    rows[row][d]--;
    columns[col][d]--;
    boxes[idx][d]--;
    board[row][col] = '.';
  }

```

## Observation: (r/3,c/3) can uniquely represent each 3x3 box

## Code

```java
import java.io.*;
import java.util.*;

class Solution {

  static boolean sudokuSolve(char[][] board) {
    // base cases
    // there is no "." on the board
    for(int i=0;i<board.length;i++) {
      for(int j=0;j<board[0].length;j++) {
        // check full satisfies
        
      }
    }
    
    boolean ans = true;
    // recursive case, there is some "." that needs to be filled
    // we must make some choice
    for(int i=0;i<board.length;i++) {
      for(int j=0;j<board[0].length;j++) {
        if(board[i][j] == '.') { // make some choices
          // check this row and  this column and this block before making a choice
          for(int k = 1;k<10;i++) {
            // check k does not occur in row already
            
            // check k does not occur in column already
            // check k does not occur in this block already
            if(!checkRowHasN(i,k, board) && !checkColumnHasN(j, k, board) && !checkBlockHasN(i,j,k,board)) {
              board[i][j] = k;
              ans = ans && sudokuSolve(board);
            }
          }
        }
      }
    }
    
   
  }
  
  // check if n occurs in row r
  boolean checkRowHasN(int r, int n, char[][] board) {
    for(int j=0;j<9;j++) {
      if((board[r][j] - '0') == n) {
        return true;
      }
    }
    return false;
  }
  
  // check if n occurs in column c
  boolean checkColumnHasN(int c, int n, char[][] board) {
     for(int j=0;j<9;j++) {
      if(board[j][c] - '0' == n) {
        return true;
      }
    }
    return false;
  }
  
  // check if n occurs in same block as board[r][c]
  boolean checkBlockHasN(int r, int c, int n, char[][] board) {
    // r/3 = 0, r/3 = 1, r/3 =2 , 0<r<9
    
    int rowStart = Math.floor(r/3) * 3;
    int colStart = Math.floor(c/3) * 3;
    
    for(int i=rowStart;i<rowStart+3;i++) {
      for(int j=colStart;j<colStart+3;j++) {
        if(board[i][j] - '0' == n) {
          return true;
        }
      }
    }
    
    return false;
  }
  
  // you are not audible!
  // so I'll continue by writing down, 
// you can add your comments at end of hte file, since I am not able to hear you
  boolean checkIfSatisfies(char[][] board) {
    boolean satisfies = true;
    int[] numsSeen = new int[10]; // 1-indexed count of how many of them we have seen
    // check all rows
    for(int i=0;i<board.length;i++) {
      // check row i
      for(int j =0;j<board[0].length;j++) {
        numsSeen[board[i][j]]++;
      }
      for(int i=1;i<numsSeen.length;i++) {
        if(numsSeen[i] != 1) {
          satisfies = satisfies && false;
        }
      }
    }
    
    // check all columns    
    // check all 3x3 blocks
  }

  public static void main(String[] args) {
    
  }

}
```