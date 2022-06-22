
## Resources

https://www.youtube.com/watch?v=AO8Sav4SmSU - Hoare partition
https://www.youtube.com/watch?v=QvgYAQzg1z8 - Lomuto partition
https://csanim.com/tutorials/hoares-quicksort-algorithm-python-animated-visualization-code - Hoare partition
https://algs4.cs.princeton.edu/23quicksort/

## Partition techniques

At the end of partition, one of the element(pivot) needs to be in its right place,
and the smaller elements to the left of it, larger elements to the right of it.

## Lomuto partitioning

Aim of partitioning:
find a index `m`, where the pivot should land (swapping elements in process). 
Also swapping elements in the process, 
so that elements to left of idx `m` are less than it, 
and elements to the right are greater than it.

### Two indexes to function l, u for lower-bound, upper-bound

### Selecting pivot

select first element: `arr[l]`

### loop variable and indexes
l, r are start indexes.
m is an interesting index we want to calculate,
i is the looper starting from `l+1` to `r` -> Start after the pivot till end, assuming pivot is at `arr[l]`

### Swap condition

element value less than pivot -> increase m index and swap
`a[i] < a[l]` -> `m = m+1; swap(m,i);` -> note increment of m happens before swap

### final swap pivot into final position

`m` now points to the index where the pivot element should go, 
Techinically this will be an element smaller than pivot because post swapping,
it would stay to the left.

### return value: by convention, we should return the index of element that got fixed in its final place

By convention, we should return the index of element that got fixed in its final place.

### code

```py
def partition(l, r, arr):
    if (l >= r):
        return l
    # start with m = l, the pivot
    m = l
    for i in range(l+1, r+1): # start iterating starting after the pivot
        if arr[i] < arr[l]: # middle pointer should increase in case -> item is less than pivot
            m = m + 1 
            # at this point, m may point to an element greater than arr[l]
            if(m != i): # simple optimization, no need to swap if same idx
                swapAtIdx(m, i, arr) # 
            # at this point, m points to arr element less than l (which came from idx i)
    swapAtIdx(l,m, arr) # bring pivot element i.e l into its final place in sorted arr
    return m

def swapAtIdx(m, n, arr):
    print("swapping at: m = ", m, " n = ", n)
    temp = arr[m]
    arr[m] = arr[n]
    arr[n] = temp
```

## Randomized lomuto partitioning

In the above lomuto partitioning, we always considered `low` or `l` as the pivot, 
and iterated frm `l+1` to `r` for arrangement.

A slight modification to this step.
* Before starting the partitioning, swap `arr[l]` with a random Idx `arr[randIdx]`.
* Now continue the partitioning scheme as usual without any changes
  
For details on random numbers, refer [Random numbers](../Arrays/RandomNumbers.md)

```java
int randPartition(l, r, arr){
    if(l >= r) {
        return l;
    }

    // pick a random index and swap with arr[l]
    int randIdx = l+(int)(Math.random() * (r-l+1));
    swap(arr, randIdx, l);

    // continue wth original partition scheme
    return partition(arr, l, r);
}
```


## Hoare partitioning (basically a type of two pointer technique with some swaps involved)

The indices `𝑖` and `𝑗` run towards each other until they cross, 
which always happens at `𝑥` (by correctness of Hoare's partitioning algorithm!). 
This effectively divides the array into two parts: 
1. A left part which is scanned by `𝑖` and 
2. a right part scanned by `𝑗`.

### pivot choosing:

simple: use first element. i.e. `A[l]`.

### pointers to start with

`i = l + 1` - i starts at `l + 1`
`j = r` - j starts at last index

Two nested loops:
1. outer while loop runs forever: `while True`
2. Two separate inner while loops, one on `i`, second on `j`

### increment condition for i and j

increment i till `A[i] < A[l]` (pauses after that - when paused `i` points to element larger than or equal to `A[l]`)
increment j till `A[j] > A[l]` (pauses after that - when paused `j` points to element lower than or equal to `A[l]`)

### Termination condition
```py
if i >= j: 
    return
```

Note: termination condition occurs after two  while loops of i and j.

### i,j paused

(not crossed) : if `i < j`, then `swap(A, i, j)`, so that it can unpause the pointers.

### After outer-loop termination

After loop termination `j` points to a place where pivot should go.
Thus swapping `swap(A, l, j)` should conclude the partition

### Implementation

```py
def swapAtIdx(m, n, arr):
    print("swapping at: m = ", m, " n = ", n)
    temp = arr[m]
    arr[m] = arr[n]
    arr[n] = temp

def hoarePartition(l, r, arr):
    i = l+1
    j = r
    while True: # termination till crossed over
        while(arr[i] <= arr[l]):
            i = i+1
            if i >= r: # without this it will run past right bound
                break
        while(arr[j] >= arr[l]):
            j = j-1
            if j <= l: # without this, it will run past left bound
                break
        
        if(i >= j): # termination condition
            swapAtIdx(l, j, arr) # final swap pivot with j
            return j # return position where we placed the pivot
        
        swapAtIdx(i,j,arr) # unstuck pointers
```

## quicksort procedure

```py
def hoareQuickSort(arr, l, r):
    print("Quicksort called with indexes: [", l, ", ", r, "]")
    if (r <= l):
        return
    j = hoarePartition(l, r, arr)
    print("pivot placed in position: ", j)
    hoareQuickSort(arr, 0, j-1)
    hoareQuickSort(arr, j+1, r)
```

### recursive version with lower & upper bound index

Termination condition: `l >= u`
```py

```