
## BFS, last node on every level

### Where I got stuck

Even though BFS is simple,
knowing the last node of a level is not straight forward.

### Two nested loops

The outer loop is a while loop, goes on till queue becomes empty
The inner loop records level length as queue size.

**Basically this is a variant of BFS** that cares about exact level processing before next levels get a chance.

### Extra variable: levelLength

Needed for inner for loop uses this length to process exactly complete level, the last of the level nodes is added 
to ans.

### Invariant: inner for loop processes whole level in one shot, and enqueues nodes of next level

### Code

```java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        bfsHelper(root, ans);
        return ans;
    }
    
    public void bfsHelper(TreeNode root, List<Integer> ans) {
        Deque<TreeNode> queue = new ArrayDeque<TreeNode>();
        if(root == null) {
            return;
        }
        queue.addLast(root);
        while(!queue.isEmpty()) { // invariant here: a complete level waiting to be processed, nothing above or below a given level
            int levelLength = queue.size();// level length, everytime we reach here, we have a fresh level to process and no nodes from previous level
            // note the inner loop is a for loop
            for(int i=0; i<levelLength; i++) { // process the whole level in one shot, queueing children for next level
                TreeNode node = queue.removeFirst();
                if(node.left!= null) {
                    queue.addLast(node.left);// queued for next level
                }
                if(node.right != null) {
                    queue.addLast(node.right);// queued for next level
                }
                if(i == levelLength - 1) {
                    ans.add(node.val); // we are last node of level
                }
            }
        }
    }
}
```

### One more code submission

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
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null) {
            return new ArrayList<>();
        }
        List<Integer> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        
        q.add(root);
        while(!q.isEmpty()) {// we have a new level to process
            int levelLength = q.size();
            // inner loop processes whole level in oneshot
            for(int i=0;i<levelLength;i++) {
                TreeNode node = q.remove();
                if(i == levelLength-1) {// last node in this level, put it in ans
                    ans.add(node.val);
                }
                if(node.left != null) {
                    q.add(node.left);
                }
                if(node.right != null) {
                    q.add(node.right);
                }
            }
        }
        
        return ans;
    }
}
```


## Recursive DFS approach (right recursion, pick best per level and store it, ignore the rest on that level)

### We visit right side first 

Since we are interested in right tree, right children get first preference.

### Check level num with answer size

since we pick right side first, the rightest node gets first preference in the newest level number (and record it in ansower), 
other nodes on the same level are ignored due to this level check.

### Code

```java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        dfsHelper(root, ans, 0);
        return ans;
    }
    
    public void dfsHelper(TreeNode root, List<Integer> ans, int level) {
        if(root == null) {
            return;
        }
        if(level == ans.size()) {// this check passes only once per level, ans.size() is next level to be found
            ans.add(root.val);// level found, the size will increment by 1.
        }
        dfsHelper(root.right, ans, level+1); // right node gets first preference
        dfsHelper(root.left, ans, level+1);
    }
}
```