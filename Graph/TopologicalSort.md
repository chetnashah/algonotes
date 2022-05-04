

## Resources

https://www.youtube.com/watch?v=9Wbej7Fy5Lw

##

A linear ordering of vertices in a DAG so that vertex u comes before vertexv, if directed edge `u -> v` exists in the DAG.

Applications:
A topo sort of vertices can help you do DP on graphs, going from vertices with least indegree to most indegree.

## Requirement: Directed acyclic graph

## DFS based

In finish step of a vertex visit in DFS, 
push vertices to a vector.

Finding a back-edge, you can report that no Topo order exists.

**Reverse of finish order is considered topo order**

## Kahn's algorithm

Need an auxillary data structure i.e. vector/array that holds indegree of 
all the vertices.

Start with nodes with zero indegree,
remove it (you can mark its indegree as -1)
find its edges and decrement their indegree.
Repeat the process till all nodes are removed, i.e. -1.

If this algorithm hits a cycle, then it would find no nodes with indegree 0.

## Variant 1: Count number of different topological orderings

## Variant 2: list all different topological orderings