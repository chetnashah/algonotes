
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

## Approach 2: Tree Construction on recursive iteration with bounds passed

