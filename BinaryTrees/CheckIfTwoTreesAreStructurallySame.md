
##

https://leetcode.com/problems/same-tree/

## Code

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return isSameHelper(p, q);
    }
    
    boolean isSameHelper(TreeNode p, TreeNode q) {
        if(p == null && q == null) {
            return true;
        }
        if((p != null && q == null) || (p == null && q != null)) {
            return false;
        }
        if(p.val != q.val) {
            return false;
        }
        // both root are same, recursively check both sides
        return isSameHelper(p.left,q.left) && isSameHelper(p.right, q.right);
    }
}
```