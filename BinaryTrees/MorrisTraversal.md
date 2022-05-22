
Tree traversal algorithm that does not use recursion/stack i.e. in O(1) space.

## Links are created as successors

## Base cases

### Leaf node: visit self, finish

### No left subtree: Visit and tail-recurse (iteration) on right side

Idea, no need to come back up from right side, because there is no need to process anything.

## Key idea

memorize the current node before going left (create link). 
And the moment we notice that such a connection has already been created, delete it and visit the node.


## Animation

![animation](images/morristraversalanimation.gif)