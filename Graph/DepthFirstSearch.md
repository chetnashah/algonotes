
Visits all vertexes once

Also known as pre-order traversal ( a pre order traversal on a tree is its DFS)

Nodes can be in one of following states:
1. Exploring
2. Unexplored
3. Explored completed

### General recursive algorithm


### Iterative algorithm with stack

1. put root/source node onto stack
2. loop till stack is empty:
   1. remove node from stack and mark it visited, push it to visited arr.
   2. put its adjacent vertices onto stack from right to left. (pushed vertices are "exploring")

