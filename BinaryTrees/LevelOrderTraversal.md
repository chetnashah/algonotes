
##

https://leetcode.com/problems/binary-tree-level-order-traversal/

## Gotchas

Two loops:
1. outer one to check queue not empty
2. Inner for loop runs for q level size. (must be extracted to a variable first and then looped).

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ansList = new ArrayList<>();
        
        if(root == null) {
            return ansList;
        }
        if(root.left == null && root.right == null) {
            List<Integer> ans = new ArrayList<>();
            ans.add(root.val);
            ansList.add(ans);
            return ansList;
        }
        
        // more than one node
        Queue<TreeNode> q = new LinkedList<>();
        
        q.add(root);
        while(!q.isEmpty()) {
            List<Integer> ans = new ArrayList<>();
            int qLength = q.size();// extracting this to a variable is necessary, otherwise it will not work
            for(int i=0;i<qLength;i++) {
                TreeNode poppedNode = q.remove();
                ans.add(poppedNode.val);
                if(poppedNode.left != null) {
                    q.add(poppedNode.left);
                }
                if(poppedNode.right != null) {
                    q.add(poppedNode.right);
                }
            }
            ansList.add(ans);
        }
        return ansList;
    }
}
```