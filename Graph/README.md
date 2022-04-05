

## representations

Note in each representation, getting a vertex adj list is constant time.
i.e. indexing into a given vertex info is constant time.
iterating through the edges of a given vertex-id is linear in the number of edges.


### 2-d array Representation

* VxV 2d array (static in java/c++)
* numerical ids for vertices
Good for highly connected graph (V * V is max possible edges)
```js
[ // connections are 1, nno connections are 0
    0: [0,1,1,0,0,0],
    1: [0,0,0,1,0,0],
    2: [0,0,0,0,1,0],
    3: [0,0,0,0,0,0],
    4: [0,1,0,0,0,0],
    5: [0,0,0,1,0,0]
]
```

### Adjacency list representation (vertex are index of array)

* Numerical ids for vertices
* Array of lists/arrays(dynamic).e.g. array of arraylists in java and array of vectors in c++.
* each index of array holds a reference to a adjancency list of that vertex
e.g.
```js
[
    0: [1,2],
    1: [3],
    2: [4],
    3: [],
    4: [1],
    5: [3]
]
```

### Adjancency list: vertex are hashmap keys, values are list of adjacent vertices (most common along with list of lists shown above)

```js
{
    a: ['b', 'c'],
    b: ['d']
    c: ['e']
    d: []
    e: ['b'],
    f: ['d']
}
```
In c++, java it can be a Map where keys can be either int or string vertex-ids, and values would be a (dynamic)list of adjacent vertex-ids.