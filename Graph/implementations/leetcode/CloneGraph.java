/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Set<Integer> visited = new HashSet<Integer>();
    public HashMap<Integer, Node> graphNodes= new HashMap<Integer, Node>();
    public HashMap<Integer, Integer> parents = new HashMap<Integer, Integer>();
    public Set<Integer> finished = new HashSet<Integer>();
    
    public Node cloneGraph(Node node) {
        if(node == null) {
            return null;
        }
        List<Node> originalNeighbors = node.neighbors;

        Node n = new Node(node.val);
        graphNodes.put(node.val, n);
        
        // System.out.println(" Creating new node for: " + n.val);
        visited.add(n.val);
        if (n.neighbors == null) {
            n.neighbors = new ArrayList<Node>();
        }
        for(int i=0; i< originalNeighbors.size(); i++) {
            Node originalNeighbor = originalNeighbors.get(i);
            // System.out.println("Exploring from " + n.val + " to " + originalNeighbor.val);
            if(visited.contains(originalNeighbor.val) == false) {
                // System.out.println(" found tree edge from " + n.val + " to " + originalNeighbor.val);
                parents.put(originalNeighbor.val, n.val);
                Node newNeighborNode = cloneGraph(originalNeighbor);
                // System.out.println("Adding neighbor for " + newNeighborNode.val + " to " + n.val);
                newNeighborNode.neighbors.add(n);
                // System.out.println("Adding neighbor for " + n.val + " to " + newNeighborNode.val);
                n.neighbors.add(newNeighborNode);
            } else {
                // visited but migh not be in each others list
                // we are going from n.val -> originalNeighbor.val
                // 4 -> 1 // u -> v
                Integer u = n.val;// u = 4
                Integer v = originalNeighbor.val; // v = 1
                
                if(parents.get(u) != v && finished.contains(v) == false) { // non-trivial cycle // parent of 4 is not 1
                    // System.out.println(" non-trivial back edge from " + u + " to " + v);    
                    Node uNode = graphNodes.get(u);
                    Node vNode = graphNodes.get(v);
                    // System.out.println("Adding neighbor for " + uNode.val + " to " + vNode.val);
                    // System.out.println("Adding neighbor for " + vNode.val + " to " + uNode.val);

                    uNode.neighbors.add(vNode);
                    vNode.neighbors.add(uNode);
                }
            }
        }
        finished.add(n.val);
        
        return n;
    }
}