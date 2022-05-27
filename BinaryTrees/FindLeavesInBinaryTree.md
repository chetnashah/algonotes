##

Return a list of leaves from the leaf level.

## Induction

Induction on height,
first add all nodes with 0 height, then 1 height, .. etc

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
    public List<List<Integer>> findLeaves(TreeNode root) {
        Map<Integer, List<Integer>> heightMap = new TreeMap<>();
        dfsHelper(root, heightMap);
        List<List<Integer>> ans = new ArrayList<>();
        for(List<Integer> list: heightMap.values()) {
            ans.add(list);
        }
        return ans;
    }
    
    public int dfsHelper(TreeNode root, Map<Integer, List<Integer>> heightMap) {
        if(root == null) {
            return 0;
        }
        int leftHeight = dfsHelper(root.left, heightMap);
        int rightHeight = dfsHelper(root.right, heightMap);
        int rootHeight = Math.max(leftHeight, rightHeight) + 1;
        List<Integer> heightValues = heightMap.get(rootHeight);
        if(heightValues == null) {
            heightValues = new ArrayList<Integer>();
        }
        heightValues.add(root.val);
        heightMap.put(rootHeight, heightValues);
        return rootHeight;
    }
}
```