

## Initial approach (clone graph)

Treat binary tree like a graph,
and make a set of all edge list, and serialize it.

**But this approach does not work because orientation matters, i.e. left child and right child are equivalent in graph, but not in a binary tree.**

## Preorder traversal with null markers is good enough

### Serialization part

Do a preorder traversal, and in process step, append to array including markers
We will serialize array to string using `String.join(",", list)`



### Deserialization

step 1: Deserialize string -> Array using `String.split(",")`
step 2: maintain a static `rootIdx`, which picks up all nodes on visit, recursively call twice, will consider all nodes in dfs fashion. this is a trick for reverse dfs from array.

### Code

```java
public class Codec {

    static Integer rootIdx = 0; // needed for deserialization traversal
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        ArrayList<String> all = new ArrayList<>();
        serializeHelper(root, all);
        String listString = all.stream().map(Object::toString).collect(Collectors.joining(","));
        return listString;
    }
    
    public void serializeHelper(TreeNode root, ArrayList<String> all) {
        // similar to preorder traversal
        if(root == null) {
            all.add("null");
            return;
        }
        all.add(String.valueOf(root.val));
        serializeHelper(root.left, sb, all);
        serializeHelper(root.right, sb, all);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        ArrayList<String> parts = new ArrayList<>(Arrays.asList(data.split(",")));
        rootIdx = 0;
        return deserializeHelper(parts);
    }
    
    public TreeNode deserializeHelper(ArrayList<String> all) {// reverse dfs/preorder
        // System.out.println(" idx = "+rootIdx);
        String nodeData = all.get(rootIdx);
        // System.out.println("data = "+nodeData);
        
        ++rootIdx;// consider root as picked up
        if(nodeData.equals("null") || nodeData.equals(null)) {
            return null;
        }
        TreeNode leftTree = deserializeHelper(all);
        TreeNode rightTree = deserializeHelper(all);
        
        // System.out.println("making tree of nodedata: " + nodeData);
        TreeNode root = new TreeNode(Integer.valueOf(nodeData));
        root.left = leftTree;
        root.right = rightTree;
        return root;
    }
}
```



## BFS/level order traversal based

```py
class Codec:
    '''       O(n) time and O(n) space, BFS traversal
    e.g., 1
         / \
        2   5
       / \
      3   4  , level order traversal, serialize will be '1,2,5,3,4,None,None,None,None,None,None,'; deserialize 
      with queue as well, convert back. Time and Space O(n).
    '''
    def serialize(self, root):
        if not root:
            return ''
        queue = collections.deque()
        queue.append(root)
        res = ''
        while queue:
            node = queue.popleft()
            if not node:
                res += 'None,'
                continue
            res += str(node.val) + ','
            queue.append(node.left)
            queue.append(node.right)
        return res
            
    def deserialize(self, data):
        if not data:
            return None
        ls = data.split(',')
        root = TreeNode(int(ls[0]))
        queue = collections.deque()
        queue.append(root)
        i = 1
        while queue and i < len(ls):
            node = queue.popleft()
            if ls[i] != 'None':
                left = TreeNode(int(ls[i]))
                node.left = left
                queue.append(left)
            i += 1
            if ls[i] != 'None':
                right = TreeNode(int(ls[i]))
                node.right = right
                queue.append(right)
            i += 1
        return root
```