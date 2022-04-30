
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

For a dfs discovery from u to v,

### Condition for cut-vertex/articulation point

`if (dfs_low[v] >= dfs_num[u])` then `u` is an articulation vertex
Think LV>=NU

### Condition for cut-edge/bridge
After tree edge recursion, within the if condition for tree edge, check following:
`if (dfs_low[v] > dfs_num[u])` then `u->v` is an bridge/cut-edge.
Think LV>NU 
### Tree edge update logic after visit recursion

Idea: update lowlink after tree edge recursion finishes (we might have found a lower link from a deeper node somewhere)
```py
# do this post recursive call
dfs_low[u] = min(dfs_low[u], dfs_low[v]) # checking low of v & u
```

### Non-trivial back edge update logic

Idea: we found a back edge, which might have a lower num(discoverycounter), so update lowlink to reflect the same
```py
if (dfs_num[v] == EXPLORING and v != p[u]): # non-trivial back-edge seen
    dfs_low[u] = min(dfs_low[u], dfs_num[v]) # note the two different values/arrays in min
```


