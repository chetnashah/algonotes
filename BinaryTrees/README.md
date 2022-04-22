
## Resources

## (EPI) depth of node

number of nodes from root to node, not including itself. (might be also counted as edges from root to node)

depth of a leaf rooted at itself would be 0.

## (EPI) height of node

Height is Maximum node depth (as per above definition).

Height of a leaf rooted at itself would be 0.
Height of a null tree would be -1.

## Balanced tree

A tree where hieght difference between left and right children  is atmost one.

A balanced binary tree does not have to be perfect or complete (definitions given below).

## cpp structure (struct based)

```cpp
template <typename T>
struct BinaryTreeNode {
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
}
```

## Perfect binary tree.

All  leaves are at the same depth and all parent have two children

## Complete binary tree

Every level except possibly the last is filled (the last level is filled starting from left to right).


## Common questions

1. check if binary tree is balanced - (each recursive call needs to return a pair: isBalanced, height) in order to need to check both subtrees balanced as well as their hieght-diff is less than 1. Useful optimizations - can short circuit recursion if you find left subtree itself is not balanced.
2. mirror binary tree
3. check if symmetric
4. calculate height of tree
5. calculate min in tree
