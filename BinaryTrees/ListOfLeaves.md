

## In many cases we need a list of leaves from left to right order

## Idea is simple pre-order-recursion  and add leaves to a list when encountered

Since preorder that visits left children first, it is good enough

```java
public static List<BinaryTreeNode<Integer>> createListOfLeaves(BinaryTreeNode<Integer> tree) {
    List<BinaryTreeNode<Integer>> answer = new ArrayList<>();
    createListOfLeavesHelper(tree, answer);
    return answer;
}

public static void createListOfLeavesHelper(BinaryTreeNode<Integer> tree, List<BinaryTreeNode<Integer>> ans) {
    if(tree == null) {// base case nothing to add
      return;
    }
    if(tree.left == null && tree.right == null) {// found something worth adding to the list
      ans.add(tree);
    } else {
      createListOfLeavesHelper(tree.left, ans);// left leaves will be added first
      createListOfLeavesHelper(tree.right, ans);// right leaves will be added later
    }
}
```
