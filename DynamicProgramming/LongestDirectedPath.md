
## Longet path in a unweighted directed acyclic graph (DAG)
 
We are not having edge weights only counting number of edges.

Directed path could start from any vertex.

### dp state

`dp[i]` = `longest path of vertex ending in vertex-id i`.

### dp transition

For all incoming degrees to a node, 
pick the path length with max path till now and add 1.

### directionality 

start problem with sorting nodes by indegree.
**sorting vertices by indegree** can help you get the directionality needed for solving dp problems.

This is one more hint on ordering : Directed acyclic graphs means, we can sort by indegree and process from least in-degree node to highest indegree node while choosing paths that give us maximum length.


