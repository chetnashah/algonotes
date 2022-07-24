
##

https://leetcode.com/problems/search-a-2d-matrix-ii/

##

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.


Example 1:

![image](images/searchgrid2.jpeg)
```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```
Example 2:

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 ```

Constraints:
```
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
```

## Simple approach: row by row binary search - O(N lg N)

## Improved approach: divide and conquer - O(N lg N)

### We can partition a sorted two-dimensional matrix into **four sorted submatrices**, two of which might contain target and two of which definitely do not.

### A element can be in a submatrix if it is greater than top-left item, and smaller than bottom-right item

## Even better approach - State space reduction - O(m + n)

### Start with bottom left corner  - let's call it visit cell

We can also start from top right corner, but traversal shown below must be adjusted.

### Go up, if visit cell is larger than target

By leaving the visit cell to the bottom, we prune all possibilities greater.

Proof: every cell to the right and bottom of visit cell will be greater than visit and hence target, so this space has to be ignored

### Go right, if visit cell is smaller than target

visit cell is greatest in current column (in trivial case this is true, because it starts from bottom left), and it is still smaller than target, so there is no possibility of finding target in the current column, and we must leave it to the left.

### Code

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        // start with bottom left
        int row = matrix.length-1;
        int col = 0;
        
        while(row>=0 && col<= matrix[0].length-1) {
            int cellValue = matrix[row][col];
            if(cellValue == target){
                return true;
            }
            
            // cellvalue is greater than target, must go up
            if(cellValue > target) {
                row--;
            } else {
                col++;
            }
        }
        return false;
    }
}
```


## Variation: first integer of a row is greater than last element in previous row

https://leetcode.com/problems/search-a-2d-matrix/

