

## Get last set bit
gives the last set bit in a number x
```py
x & (-x) # anding with its own 2's complement
```

## number of set bits in a number
```cpp
__builtin_popcount(x) returns popcount of a number — the number of ones in the binary representation of 𝑥. Use __builtin_popcountll(x) for long longs.
```

## number of trailing/leading zeros

There are also `__builtin_clz` and `__builtin_ctz` (and their long long versions) for counting the number of leading or trailing zeros in a positive number

## Clear the rightmost set bit

```py
def turn_off_rightmost_1bit(num: int) -> str:
    rightmost_1bit_turned_off = num & (num - 1)
    return f"Rightmost 1-bit in {bin(num)} is turned off and the result: {bin(rightmost_1bit_turned_off)}"

```

Alternative implementation: isolate right most set bit and substract it from original
```py
def turn_off_rightmost_1bit(num: int) -> str:
    rightmost_1bit_turned_off = num - (num & -num)
    return f"Rightmost 1-bit in {bin(num)} is turned off and the result: {bin(rightmost_1bit_turned_off)}"
```

## Determine if integer is power of 2
```cpp
unsigned int v; // we want to see if v is a power of 2
bool f;         // the result goes here 

f = (v & (v - 1)) == 0;
// Note that 0 is incorrectly considered a power of 2 here. To remedy this, use:
f = v && !(v & (v - 1)); // if clearing the last set bit in v makes it 0, it was a power of 2
```

## Toggle n'th bit

```py
def toggle_nth_bit(num, n: int) -> str:
    toggled_number = num ^ (1 << n)
    return f"{n}th bit of {bin(num)} toggled and the result is {bin(toggled_number)}"
```

## invert all bits after last one bit

```py
k = x | x - 1
```

## Reset all trailing set bits

Reset all trailing set bits at the end of the number

```py
k = x & (x + 1)
# (11) -> (1011) -> (1000)
# (12) -> (1100) -> (1100)
# (13) -> (1101) -> (1100)
# (14) -> (1110) -> (1110)
# (15) -> (1111) -> (0000)
```