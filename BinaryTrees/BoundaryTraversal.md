
Also known as exterior of a binary tree

## Boundary traversal definition

1. root to leftmost leaf
2. leaves in left to right order
3. rightmost leaf to root.

In essence this is **anticlockwise traversal** of the exterior nodes.

## Approach 1:

## Problem and code

https://leetcode.com/problems/boundary-of-binary-tree/

### My solution

```java
class Solution {
    static boolean mainLeftEmpty = false;
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> leftAndLeaves = new ArrayList<Integer>();
        List<Integer> rightBoundary = new ArrayList<Integer>();
        if(root == null) { // no root case
            return leftAndLeaves;
        }
        if(root.left == null && root.right == null) { // root itself is leaf
            leftAndLeaves.add(root.val);
            return leftAndLeaves;
        }

        // root has 1 or more children
        mainLeftEmpty = root.left == null;// If the root does not have a left child, then the left boundary is empty
        if(mainLeftEmpty) {// if left boundary not possible add root to leftAndLeaves
            leftAndLeaves.add(root.val);
        }
        getLeftBoundaryAndLeaves(root, leftAndLeaves, true);// we must pass root to get to all leaves
        // System.out.println(leftAndLeaves);
        
        if(root.right != null) {// root is already considred in leftAndLeaves, so only traverse right for right boundary
            getRightBoundary(root.right, rightBoundary, true);
        }
        // System.out.println(rightBoundary);
        
        for(int i=rightBoundary.size()-1; i>=0 ; i--) {
            leftAndLeaves.add(rightBoundary.get(i));
        }
        return leftAndLeaves;
    }
    
    public void getLeftBoundaryAndLeaves(TreeNode root, List<Integer> leftAndLeaves, boolean isInLeftBoundary) {
        if(root == null) {
            return;
        }
        if(root.left == null && root.right == null) {// found a leaf
            // System.out.println(" adding leaf: " + root.val);
            leftAndLeaves.add(root.val);
            return;
        }
        // non-leaf node
        if(isInLeftBoundary && !mainLeftEmpty) {// checking if leftboundary possible or not
            // System.out.println("adding non leaf: " + root.val);
            leftAndLeaves.add(root.val);
        }
        getLeftBoundaryAndLeaves(root.left, leftAndLeaves, isInLeftBoundary);
        getLeftBoundaryAndLeaves(root.right, leftAndLeaves, isInLeftBoundary && root.left == null);
    }
    
    public void getRightBoundary(TreeNode root, List<Integer> rightBoundary, boolean isInRightBoundary) {
        if(root == null) return; // nothing to check
        if(root.left == null && root.right == null) {// leaves already considered, nothing to recurse over
            return;
        }
        // non-leaf node
        if(isInRightBoundary) {
            rightBoundary.add(root.val);
        }
        getRightBoundary(root.right, rightBoundary, isInRightBoundary);
        getRightBoundary(root.left, rightBoundary, isInRightBoundary && root.right == null);
    }
}
```

## Approach 2: pre-order traversal

https://leetcode.com/problems/boundary-of-binary-tree/solution/