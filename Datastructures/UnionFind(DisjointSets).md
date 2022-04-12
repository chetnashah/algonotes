
## Resources

https://cp-algorithms.com/data_structures/disjoint_set_union.html
https://algs4.cs.princeton.edu/15uf/
https://www.youtube.com/watch?v=ibjEGG7ylHk
https://www.youtube.com/watch?v=ID00PMy0-vE
https://www.youtube.com/watch?v=eTaWFhPXPz4
https://www.youtube.com/watch?v=pnkqqb-WaRg
https://www.youtube.com/watch?v=VHRhJWacxis

## Background

## ADT

1. makeSet - `makeSet(int i)` - Create a set with single element i. 
2. unionSets - `union(int u, int v)` - union/merge sets represented by v1 and v2
3. findSet - `find(int k)` - find set representation of k.

## Input representation

Given: an array of edges/relationships i.e. `u` and `v` are realted/union'ed asking us to union the sets represented by these identifiers.

## What is rank?



## Start

one set each for each element.
typically integers used for problem.
**Initial rank for all elements/sets is 0.**

## Tree/DS Representation

Array size - all integers or Range inclusive of all u,v given in input.

1. Parent array (`P[i]` or `id[i]`): a Array of parent pointers `P[i]` is enough for storing the tree for each vertex, represents set/root identifier in the array currently known.
2. Rank array (`R[i]` or `sz[]` - size array): 

root Parent represents the set-id for any given rooted tree.


### Alternative representation (reference based)

```java
class Node {
    int rank;
    int data;
    Node parent;
}
```

## Why do path compression?
There is no point in keeping tree depth long.
Shorter/flatter tree will find set-id i.e. parent of a given index lot faster

## Without rank compression

```cpp
int parent[1000];

makeSet(int x) {
    parent[x] = x;
}

// mutative method, does path compression while finding the root
int find(int x){
    int parX = (parent[x] == x ? x : find(parent[x]));// note the recursion
    parent[x] = parX;// update by path compression, happens by assignment when returning from recursion
    return parent[x];
}

// Union depends on find to operate
void Union(int p, int q){ 
    parent[find(p)] = find(q); // make root of p as a parent of root of q
}
```

## Time complexity

Amortized logarithmic/constant time?

## Application

1. kruskal's algorithm
2. Cycle detection (in undirected graph)
3. Undirected graph connected components
4. LCA in trees
5. Unification (https://en.wikipedia.org/wiki/Unification_(computer_science))