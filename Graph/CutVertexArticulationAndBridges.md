
## Resources

https://www.youtube.com/watch?v=iYJqgMKYsdI&list=PL1gVuOYe08PT54itbrJmJbmLrk1W1DXxu&index=22

https://cp-algorithms.com/graph/bridge-searching.html
https://cp-algorithms.com/graph/cutpoints.html

## Terminologies

### Articulation Point (Cut-Vertex)
A vertex in graph G, whose removal(including removing all edges it has), disconnects G.

### Bridge (Cut-Edge)

An edge in (undirected?) graph G whose removal (keeping all vertices as it is), removal of this edge disconnects G.

* An edge is a bridge if and only if it is not contained in any cycle.
* In a tree, every edge is a bridge because a tree has no cycles.


## Brute force approaches

### For cut-vertex/Articulation point
Remove every vertex, and try DFS.
Complexity - O(V * (V+E))


### For cut-edge/bridge
Remove every edge, try DFS.
Complexity - O(E * (V + E))


## Main algorithm


### Tree edge update logic after visit recursion

```py
# do this post recursive call
dfs_low[u] = min(dfs_low[u], dfs_low[v])
```

### Non-trivial back edge update logic

```py
if (dfs_num[v] == EXPLORING and v != p[u]): # non-trivial backedge seen
    dfs_low[u] = min(dfs_low[u], dfs_num[v])
```


