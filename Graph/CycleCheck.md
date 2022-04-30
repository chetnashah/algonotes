
We consider both cycle in both directed & undirected graph.

Can be found via DFS when we encounter -> EXPLORING vertex from a source vertex.

```py
def cycleCheck(u):
    dfs_num[u] = EXPLORING
    for (v in adj[u]):
        if(dfs_num[v] == UNVISITED):
            # dfs tree edge, recurse
            p[v] = u # record parent before recursing
            cycleCheck(v)
        elif (dfs_num[v] == EXPLORING): # back edge
            if(v == p[u]): # immediate parent - trivial cycle
                print("trivial back edge from u to v")
            elif (v != p[u]):
                print("non-trivial back edge from u to v")
```

## Undirected graph

An undirected graph can be considered and represented as a directed graph with trivial cycles. i.e. all normal edges have both directions. 
e.g. for all u,v in G, u->v implies v->u

When we say we want to check a cycle in undirected graph, we usually mean a non-trivial cycle.


## Directed Graph

Core idea: In DFS, we must check back edges i.e. EXPLORING->EXPOLORING on edge discovery.

### Back edge to immediate parent

Trivial cycle
can be checked via:
```py
if (dfs_num[v] == EXPLORING): # back edge
    if(v == p[u]): # back edge from immediate parent that we came from
        print("trivial cycle")
```

### Back edge to non-immediate ancestor

This is a case of a non-trivial cycle
```py
if (dfs_num[v] == EXPLORING):
    if(v != p[u]):
        print("non-trivial cycle")
```

### Kahn's algorithm (directed graph)

Indegree of nodes based algorithm.

keep pulling out vertices with indegree 0 and remove their edges,
if you ever hit a case where you cannot remove any nodes as all nodes have non-zero indegree, you have hit a cycle