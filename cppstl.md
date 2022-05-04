

##  lower_bound

To use with sets, maps: Use `set.lower_bound()` and `map.lower_bound()` versions instead of the `algorithm.h` version (which is O(N))

`lower_bound`: find iterator to element greater than or equal to given element e.g.

Pre-requisite: elements have to be sorted

### Element present

**auto it = s.lower_bound(5)**: first pointer gt than or equal to 5.
`4 5 5 7 8 25`
   ^         

To get the index in array you can do `lower_bound(5) - v.begin()` = 1

### Element not present

**auto it = s.lower_bound(6)**: first pointer gt than or equal to 6.
`4 5 5 7 8 25`
       ^      

### No lower bound (all elements are smaller than given value)

returns `s.end()`

## set upper_bound

Return pointer to the element strictly greater than given val

### Element present & element not present give same answer

**auto it = s.upper_bound(5)**
`4 5 5 7 8 25`
       ^

**auto it = s.upper_bound(6)**
`4 5 5 7 8 25`
       ^






