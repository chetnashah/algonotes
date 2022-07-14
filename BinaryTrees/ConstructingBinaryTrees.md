

## Construction of Binary trees

Needs both pre-order and inorder traversal.

**In order traversal gives hint on left to right structuring of the tree where as pre-order gives top to bottom structuring of the tree.**

**Note** - Preorder or inorder traversal alone is not enough to create Binary Tree.

**preorder and inorder consist of unique values.**


### Core idea 1: first element in preorder is always a root. In preorder array, root and cnt of el in tree is important

Preorder:
| `3` | 9   | 20  | 15  | 7   |
|:---:|:---:|:---:|:---:|:---:|


### Core idea 2: Induction on sizes via inorder traversal (gives left and right tree sizes on root finding)

| 9   | `3` | 15  | 20  | 7   |
|:---:|:---:|:---:|:---:|:---:|

### My code 

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0 || inorder.length == 0) {
            return null;
        }
        TreeNode ans = buildHelper(0, preorder.length, 0, inorder.length - 1, preorder, inorder);
        return ans;
    }
    
    // build a tree starting at index treeStart that contains cnt number of nodes
    // for preorder tree, treeStart and 
    public TreeNode buildHelper(int treeStart, int cnt, int inorderstart, int inorderend, int[] preorder, int[] inorder){
        
        // System.out.println(" treeStart = " + treeStart + " cnt = " + cnt + " inorderstart = " + inorderstart + " inorderend = " + inorderend);

        // make root from preorder start
        TreeNode root = new TreeNode(preorder[treeStart]);
        
        if(cnt == 1 || inorderstart == inorderend) {
            return root;
        }
        
        int idxInorder = 0;
        // finding root in inorder helps us tell the left and right tree sizes
        for(int i=inorderstart;i<=inorderend;i++) {
            if(inorder[i] == root.val) {
                idxInorder = i;
                break;
            }
        }
        
        // induction recursion based on size of subtrees
        int leftTreeSize = idxInorder - inorderstart;
        int rightTreeSize = cnt - leftTreeSize - 1;
        // System.out.println(" leftTreeSize = " + leftTreeSize + " rightTreeSize = " + rightTreeSize);
        TreeNode left = null;
        TreeNode right = null;
        // left tree size
        if(leftTreeSize > 0) {
            left = buildHelper(treeStart+1, leftTreeSize, inorderstart, idxInorder-1, preorder, inorder);
        }
        if(rightTreeSize > 0) {
            right = buildHelper(treeStart + leftTreeSize+1, rightTreeSize, idxInorder+1, inorderend, preorder, inorder);
        }
        
        root.left = left;
        root.right = right;
        return root;
    }
}
```

### TODO: Analyze time complexity

