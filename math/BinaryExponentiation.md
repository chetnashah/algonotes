
Exponentiation in logarithmic time

### How many exact digits are present in a binary representation of a number n?

It has exactly `floor(log2 n) + 1` digits.
Proof: Take 16 for example it has 5 digits, `log2 16` = 4, `log2 16 + 1` = 5 digits
Anything between 16 and 8 will have 4 digits, and `log2 15<->9` = 3.xx, so num of digits from 9-15 is `floor(3.xx) + 1` i.e 4 digits

### calculate a ^ n in O(log n) steps

Naive approach = a.a.a.a... n times
takes O(n).

## Core idea: Any number can be represented as sum of power of two

Also known as binary representation,
any number can be represented as sums of power of 2.

If a number is n, it will have lg N digits in its binary representation.

## Compute only a^2, a^4, a^8, ... 

then n can be represented as a liner combination of powers of 2 (1, 2, 4, 8, ...)

e.g.
```
a^13 = 1.a^8 + 1.a^4 + 0.a^2 + 1.a^1
a^7 = 1.a^4 + 1.a^2 + 1.a^1
```

### Recursive formulation

* if n is odd, do a * binpow(a, b/2) * binpow(a, b/2)
* if n is even, do binpow(a, b/2) * binpow(a, b/2)

```py
def binPow(a, n):
    if(n == 0):
        return 1
    if(n == 1):
        return a
    result = binPow(a, math.floor(n/2)) # floor is necessary, otherwise float will never hit base case
    if (n % 2 == 1):
        return a * result * result
    else:
        return result * result
```

### bit scanning approach (no recursion overhead)

```py
def binPowBitScan(a, n): 
    result = 1 # we will pick some exponents (corresponding to set bits) and keep multiplying to this
    weight = a # number corresponding to each position in digit representation, has to be squared each loop
    while(n > 0):
        if(n & 1): # include the exponentiation, if bin representation has 1
            result = result * weight # pick and mult with existing result
        weight = weight * weight # exponentiation weight for each position
        n >>= 1 # shift bitwise right and update
    return result
```

#### start with result = 1 and weight = a

#### in all loops, do weight = weight * weight

#### for cases where bit is set in n, pick ans in result via multiplication

#### `weight = weight * weight` and bit shifting via `n >>= 1` happens in the end of loop 

### Applications

1. `modulo exponentiation`
   Same as bitscanning exponentiation,
   just during multiplications, include modulo as well 

e.g.
```py
def binPowBitScanModulo(a, n, m): 
    result = 1
    weight = a % m
    while(n > 0):
        if(n & 1): # include the exponentiation, if bin representation has 1
            result = result * weight % m # pick and mult with existing result
        weight = weight * weight % m # exponentiation for each shift
        n >>= 1 # divide by 2 or shift bits
    return result
```