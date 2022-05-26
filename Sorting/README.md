

### Swapping variables using XOR

Do xor betwe `X` and `Y` three times
in the order of `X,Y,X`
```py
X = 2
Y = 3
X = X ^ Y
Y = X ^ Y
X = X ^ Y
print(X)
print(Y)
```

### Swapping variables with addition and substraction
one addition and two substraction between X and Y
in the order of `X, Y, X`
```py
def swapWithAddSub(X, Y):
    X = X + Y
    Y = X - Y
    X = X - Y
    print(X)
    print(Y)
```

## Java Collections.sort

Uses a modified merge sort so `Collections.sort` is a stable sort.

## Arrays.sort

Arrays.sort is stable if you are sorting objects.

`public static void sort(Object[] a)`:
Sorts the specified array of objects into ascending order, according to the natural ordering of its elements. All elements in the array must implement the Comparable interface. Furthermore, all elements in the array must be mutually comparable (that is, e1.compareTo(e2) must not throw a ClassCastException for any elements e1 and e2 in the array).
This sort is guaranteed to be stable: equal elements will not be reordered as a result of the sort.

Implementation note: This implementation is a stable, adaptive, iterative mergesort that requires far fewer than n lg(n) comparisons when the input array is partially sorted, while offering the performance of a traditional mergesort when the input array is randomly ordered. If the input array is nearly sorted, the implementation requires approximately n comparisons. Temporary storage requirements vary from a small constant for nearly sorted input arrays to n/2 object references for randomly ordered input arrays.

