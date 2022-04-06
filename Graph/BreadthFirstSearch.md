

Level order traversal

### Queue is important data structure for intermediate nodes to be processed

### Data structures needed

1. one Queue (for ordering things).
2. one visited Array (tracks visited status during exploration phase) / Or use a color enum array for separate states.
3. one distance Array (manages distance from source vertex).
4. Auxillary (parent discovery pointer).

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

```py

```