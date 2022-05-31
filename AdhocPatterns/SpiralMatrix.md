

## Core idea

Given `n x m` matrix - `n rows`, `m columns`.

Maintain four indexes into corners of the outermost square: 
`maxLeft, maxTop = 0`
and `maxRight, maxBottom = m-1, n-1`

## Outer while loop is while(true), and termenates via `break` on conditions

## Termination conditions

1. `maxLeft == maxRight` = we have to iterat on the final remaining column
2. `maxTop == maxBottom` = we have to iterate on the final remaining row 

## Code

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int maxLeft = 0, maxTop = 0;
        int maxRight = matrix[0].length - 1;
        int maxBottom = matrix.length - 1;
        int cnt = 0;
        int totalItems = matrix.length *matrix[0].length;
        List<Integer> ans = new ArrayList<Integer>();
        
        while(true) {
                        // System.out.println("maxTop = " + maxTop + " maxLeft = " + maxLeft + " maxRight = " + maxRight + " maxBottom = " + maxBottom);

            if(maxLeft>maxRight || maxTop>maxBottom) {
                break;
            }
            if(maxLeft == maxRight){
                // last column
                for(int i=maxTop;i<=maxBottom;i++) {
                    // System.out.println(matrix[i][maxRight]);
                    ans.add(matrix[i][maxRight]);
                }
                break;
            }
            if(maxTop == maxBottom) {
                // last row
                for(int i=maxLeft;i<=maxRight;i++) {
                    // System.out.println(matrix[maxTop][i]);
                    ans.add(matrix[maxTop][i]);
                }
                break;
            }
            if(totalItems == cnt) {
                break;
            }
            // top line
            int c = maxLeft;
            int r = maxTop;
            for(int i=maxLeft; i<maxRight;i++){
                // System.out.println(matrix[maxTop][i]);
                ans.add(matrix[maxTop][i]);
                cnt++;
            }
            // right line
            for(int i=maxTop;i< maxBottom;i++) {
                // System.out.println(matrix[i][maxRight]);
                ans.add(matrix[i][maxRight]);
                cnt++;
            }

            // bottom line
            for(int i=maxRight; i>maxLeft;i--) {
                // System.out.println(matrix[maxBottom][i]);
                ans.add(matrix[maxBottom][i]);
                cnt++;
            }

            // left line
            for(int i=maxBottom;i>maxLeft;i--) {
                // System.out.println(matrix[i][maxTop]);
                ans.add(matrix[i][maxTop]);
                cnt++;
            }

            maxTop++;
            maxBottom--;
            maxLeft++;
            maxRight--;
        }
        
        return ans;
    }
}
```

