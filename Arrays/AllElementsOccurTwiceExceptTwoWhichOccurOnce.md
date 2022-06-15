
##

Given an array where every element occurs twice, except two elements which occur only once,
find both the elements which occur only once

##

```
Input: [23,23,11,3,5,3,15,15] 
Output: 11, 5
```

##

let's say elements that occur only once are `a` and `b`.

XOR of all elements = `a` ^ `b`.

Now any bit set in `a^b` is exclusively set in either `a` or `b`.

