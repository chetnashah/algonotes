
### Starting values of lo, hi 

```py
lo = 0, hi = n-1
```

### Termination condition

```py
    while lo < hi:
        // algorithm
```
This ensures, that after algorithm finishes, lo = hi = somevalue, which is our target index.

### Deciding the mid

Typically use 
```java
mid = lo + Math.floor((hi - lo)/2)
```
This helps prevent overflow that can occur with `hi+lo/2`.

### where should hi & lo be after predicate test

`lo = mid + 1` in case predicate(i) is false
`hi = mid` in case predicate(i) is true

### Case: a bunch of falses followed by bunch of true, find the first index with true

**Algorithm Returns first index with p(index) is true**
Have tried/tested this with all the following possibilites(with pen and paper):
`FFFFFFFFF` -> Edge case: after finish `lo` will be `n-1`, so check `p(lo) == false`(which means invariant failed) 
`FFFFFFFFT`
`FFFFFFFTT`
`FFFFFFTTT`
`FFFFFTTTT`
`FFFFTTTTT`
`FFFTTTTTT`
`FFTTTTTTT`
`FTTTTTTTT`
`TTTTTTTTT` - works fine, 0 is returned as answer which is correct

```py
binary_search(lo, hi, p):
    while lo < hi:
        mid = lo + (hi - lo) / 2
        if p(mid) == true:
            hi = mid
        else :
            lo = mid + 1
    if p(lo) == false:
        complain // p(x) is false for all x in S!

    return lo // lo is the least x for which p(x) is true
```

#### Case all true
above algorithm correctly returns 0 index

#### Case all false
Covered by checking `p(lo) == false` after algorithm ends.








### Case: find exact index 