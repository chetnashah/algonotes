
## Resources

https://www.youtube.com/watch?v=RyAGEb4VWo0
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/solution/

## Traversal info needed

**Inorder traversal is not enough**

Proof: Proof by contradiction: we can have multiple BSTs that give same 

```
All these have same in-order traversal: 1,2,3

1      ,    2   ,       3
 \         / \         /
  2       1   3       2
   \                 /
    3               1
```
**Preorder traversal** is enough.

`2,1,3` - means `2` is the root, then 1 is left child to left of `2`, and `3` is right child to right of `2`. 

## Approach 1: simply insert according to BST rules - O(N^2) worst case

Inserting according to BST rules,
we get the final BST
e.g. of `2,1,3`
we get

```
Insert 2:
2

Insert 1:
  2
 /
1

Insert 3:
  2
 / \
1   3
```

In the worst case in a completely skewed tree, we can have every node compared to all nodes on insertion,leading to O(N^2)

## Another O(N^2) approach

after picking root, make two arrays/vectors: smaller, greater which contain values smaller and greater than root in the remaining array.
Pass these arrays recursively to get tree nodes from them and attach and return.

e.g. for `[8,5,1,7,10,12]`

The root 8,
smaller array = `[5,1,7]`,
greater array = `[10,12]`.

Apply this recursively to the two arrays: `[5,1,7]`, and `[10,12]`
Base case, single node, i.e. single item array, return itself.


## Approach 2: Tree Construction on recursive iteration with bounds passed



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
    static int rootIdx;
    public TreeNode bstFromPreorder(int[] preorder) {
        rootIdx = 0;
        return treeNodeCreateHelper(preorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    // build subtree rooted at rootIdx with given bounds
    public TreeNode treeNodeCreateHelper(int[] preorder, int lower_bound, int upper_bound) {
        System.out.println("rootIdx = " + rootIdx + " left_bound = " + lower_bound + " upper_bound = " + upper_bound);
        if(rootIdx == preorder.length) {
            return null;
        }
        int root = preorder[rootIdx];// capture root node for current index, points to current item to be considered
        
        if(root < lower_bound || root > upper_bound) { // early return on bounds, no point looking to insert in this interval
            return null;
        }
        
        // note this sequence is important
        // we can place node, since bounds are fine, so increment and consider as done
        ++rootIdx; // shared ref, we increment to next item before left/right tree creation
        
        // we create children before create root, attach them
        // we give rootIdx to be correctly be placed in both lower, greater intervals,
        // if they will be within bounds, they will be picked up or else return null
        // we try placing in left child first because that is how preorder traversal is created.
        TreeNode leftTree = treeNodeCreateHelper(preorder, lower_bound, root);
        // if left tree could not place it, placement chance is given to right tree with bounds
        TreeNode rightTree = treeNodeCreateHelper(preorder, root, upper_bound);
        
        return new TreeNode(root, leftTree, rightTree);
    }
}
```

## O(N) approach but with stack

