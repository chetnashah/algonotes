

### Resources

https://cp-algorithms.com/graph/finding-cycle.html
CLRS
cp-book

### 
Visits all vertexes once

Also known as pre-order traversal ( a pre order traversal on a tree is its DFS)

### Generates a traversal tree (of exploration done) as an end result

### States of vertices
Nodes can be in one of following states:
1. Exploring
2. Unexplored
3. Explored completed

### Data structures needed

1. visited array (tracks visited status) / Or use a color enum array for separate states
2. Auxillary array discovery start time
3. Auxillary array discovery finish time
4. Auxillary array parent pointers vertex id

### Managing directed vs undirected graphs

### visited is equivalent to gray color marking of node


### Simple General recursive algorithm

* visit/explore marking happens before looping over adjacent
* black/post process marking happens after loop is finished

**Early return version**
`s` is start vertex:
```py
dfs(s):
    if(visited[s]): # node already fully explored
        return
    visited[s] = True # node exploring, usually print statements and other first processing stuff goes here
    for (v in graph[s]):
        dfs(v) # unconditionally recurse, the edge cases will be checked via early return
    # node fully explored (including descendants)
```

**Same version without early return**:
```cpp
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]){ // conditional recursion prevents base case early return at start of function
            dfs(v);
        }
    }
}
```

### CLRS DFS version

**Note** -
1. does not do early return in recursion, instead relies on conditional recursion at the recursion call site
2. Parent relationship captured just before recursing down the adjacent vertex
   
Calculates
* start/finish times arrays - `s[vertex-id]`, `f[vertex-id]`, 
* parent pointers in order discovery - `p[vertex-id]`

```py
dfs(s):
    time = 0
    p[s] = -1 # source vertex has no parent
    dfs-visit(s)

dfs-visit(u): # named u by convention because we will be discovering edges from u to v i.e. u -> v
    time = time+1 # first step is time increase
    s[u] = time # start time of exploring u
    visited[u] = GRAY # exploration phase starts when coming into dfs-visit procedure
    for (v in graph[u]): # for all adjacent vertices of u, iterating over all edges from u
        if (visited[v] == WHITE): # conditional recursion to unexplored vertices, since we don't have early return
            p[v] = u # p was discovered due to exploration from u to v, done before recursing
            dfs-visit(v) # recurse
    time = time + 1 # time also incremented when going back otherwise it will have same time as entring/exploring
    f[u] = time
    visited[u] = BLACK # all exploration complete from u
```

### Iterative algorithm with stack

1. put root/source node onto stack
2. loop till stack is empty:
   1. remove node from stack and mark it visited, push it to visited arr.
   2. put its adjacent vertices onto stack from right to left. (pushed vertices are "exploring")

### Edge classification

`u->v` exploration cases:

Cases when `v` is not visited:
* `Tree edge` - primary discovery edge going from `EXPLORING -> UNEXPLORED` i.e. `GRAY -> WHITE`. These edges form a DFS tree and hence the name tree edges.

Cases when `v` is already visted:
* `Back edge`: `EXPLORING -> EXPLORING`, contribute to cycles, points to ancestor that is already in EXPLORING state
* `Forward edge`: `EXPLORING -> EXPLORED` and `entry[u] < entry[v]`
* `Cross Edge`: `EXPLORIMG -> EXPLORED` and `entry[u] > entry[v]`

### Cycle finding in undirected graph (special case)

**Undirected graph has bi-directional edge for every undirected edge in a graph**
So we must take care and ignore parent to child edge when checking adjacent edges from a vertex.

```cpp
bool dfs(int u, int par) { // passing vertex and its parent vertex
    visited[u] = true;
    for (int v : adj[u]) {
        if(v == par) continue; // skipping edge to parent vertex
        if (visited[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        parent[v] = u;
        if (dfs(v, parent[u]))// recurse, and if any level down you find a cycle, whole graph has a cycle
            return true;
    }
    return false;
}
```

### Applications

1. Connectivity - a connected graph will mark all vertices as visited ina single pass of DFS, does not need to start DFS on a separate vertex
2. Find any path in the graph from source vertex  to all vertices
3. Topological sorting
4. Cycle finding in a directed graph - 
5. Cycle finding in undirected graph - does it make sense?
6. Classification of edges of a graph


