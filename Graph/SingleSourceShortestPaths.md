
## Resources

https://www.youtube.com/watch?v=NzgFUwOaoIw

## On unweighted graphs (can have cycles)

Just use BFS.

## positive Weighted graphs SSP <-> Djikstra's algorithm O(E log V)

Assumption: Non-negative edge weights.
If you want negative & non-negative edge weights, refer Bellman ford algorithm.

## Lazy implementation

### Data structures needed

* A `dist` array, indexed by vertex-id, holding distances to every other vertex from the source vertex.
* A `nextMinDistNodePQ` priority queue that holds `pair<dist, nodeidx>`, telling us which node to visit next, **Note** - if you are using a custom pair/struct, you must specify your own comparator that picks basis dist. 

### Initialisation

* A `dist` array, indexed by vertex-id, holding distances to every other vertex from the source vertex, INF initially since other nodes are unreachable at the start.

```cpp
std::vector<int> dist;
dist.assign(N, INF);// initially all nodes are unreachable
dist[src-vertex-id] = 0;
```

### Core algorithm

While PQ is non-empty:
1. Pop node from PQ
2. Add node to selected vertices Set
3. Get neighboring edges, if neighboring edge to already selected vertex continue, otherwise relax the edges neighbouring to selected vertex, and add them PQ.

## Eager implementation


## Balanced BST/set version


## Problem variant : Single source shortest paths on a DAG

Possible in linear time: O(V+E)
Nodes can be ordered via TopoSOrt.
Then process nodes from left to right and keep relaxing edges for each vertex.



