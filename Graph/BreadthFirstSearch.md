

Level order traversal

### Queue is important data structure for intermediate nodes to be processed

### Data structures needed

1. one Queue (for ordering things).
2. one visited Array (tracks visited status during exploration phase) / Or use a color enum array for separate states.
3. one distance Array (manages distance from source vertex).
4. (Optional) one parent array to make note of parent from which current vertex was visited/explored
5. Auxillary (parent discovery pointer).

### Initialization and initial vertex s

```py
visited[s] = True
distance[s] = 0
Q.push(s)
```

### Core algorithm

1. start with source node in Queue
2. While Queue has nodes
   1. pop a node from Queue
   2. mark it visited
   3. add its adjacent vertices to the Queue

### Implementation

```java
List<List<Integer>> adj = new ArrayList<>();

int n;// number of nodes
int s; // source start vertex

int[] d = new int[n]; // distnace of each node, index is vertex id
boolean[] seen = new boolean[n]; // whether this vertex was seen/visited/processed
int[] p = new int[n]; // parent discovery vertex for any given vertex

LinkedList<Integer> q = new LinkedList<Integer>();// actual queue
q.add(s);
d[s] = 0;// distance of source is 0
p[s] = -1;// marker for source vertex
seen[s] = true;
seen[s] = true;
while(!q.isEmpty()) {
   int u = q.remove();
   for(int v: adj(u)) { // going from u to v
      if(!seen[v]) {
         seen[v] = true;
         p[v] = u;// record parent
         d[v] = d[u]+1;// record distance
         q.push(v);
      }
   }
}
```

## BFS with level distinction

Two loops:
1. outer one to check queue not empty
2. Inner for loop runs for q level size. (must be extracted to a variable first and then looped).



## Multi source BFS

