
## On unweighted graphs

Just use BFS.

## Weighted graphs SSP <-> Djikstra's algorithm O(E log V)

Assumption: Non-negative edge weights.


## Lazy implementation

### Data structures needed

* A `dist` array, indexed by vertex-id, holding distances to every other vertex from the source vertex.
* A `nextMinDistNodePQ` priority queue that holds `pair<dist, nodeidx>`, telling us which node to visit next, **Note** - if you are using a custom pair/struct, you must specify your own comparator that picks basis dist. 

### Initialisation

* A `dist` array, indexed by vertex-id, holding distances to every other vertex from the source vertex.

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

