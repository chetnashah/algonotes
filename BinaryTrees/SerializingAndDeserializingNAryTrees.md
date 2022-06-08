
https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/solution/

## Choosing serialization format

## Nested bracket format

Tree can be encoded as nested brackets
`[1 [3[5 6] 2 4]]`

## Approach 1: Finish markers with DFS

### Encode step

Where I got stuck, introduce comma separation between different digits e.g. in following encoding:
`12X36X71114XXXX4812XXX5913XX10XXX`: it is impossible to know if 3 or 36 was the intended nodes

### Decode step

`static rootIdx` pick technique must be used to pick elements from the traversal

### Code

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        if(root == null) {
            return "";
        }
        List<String> traversalData = new ArrayList<>();
        dfs(root,traversalData);
        String finalString = String.join(",", traversalData);
        // System.out.println(finalString);
        return finalString;
    }
    
    public void dfs(Node root, List<String> traversalData) {
        if(root == null) {
            return;
        }
        traversalData.add(""+root.val);
        for(int i=0;i<root.children.size();i++) {
            dfs(root.children.get(i), traversalData);
        }
        traversalData.add("X");
    }
    
    
	static int rootIdx = 0;
    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if(data == "") {
            return null;
        }
        // 12X36X71114XXXX4812XXX5913XX10XXX
        rootIdx = 0;
        List<String> traversalData = Arrays.asList(data.split(","));
        Node ans = treeBuildHelper(traversalData);
        return ans;
    }
    
    public Node treeBuildHelper(List<String> traversalData) {
        if(rootIdx >= traversalData.size()) {
            return null;
        }
        String rootVal = traversalData.get(rootIdx);
        rootIdx++; // rootIdx picking technique
        if(rootVal.equals("X")) {
            return null;
        }
        
        List<Node> childrenNodes = new ArrayList<>();
        Node childNode;
        while((childNode = treeBuildHelper(traversalData)) != null) {
            childrenNodes.add(childNode);
        }
        Node newRoot = new Node(Integer.parseInt(""+rootVal), childrenNodes);
        return newRoot;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```


## Approach 2: DFS with children sizes

## Approach 3: Parent child relationships

## Approach 4: Level order traversal

