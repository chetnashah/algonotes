

## Get last set bit
gives the last set bit in a number x
```py
x & (-x) # anding with its own 2's complement
```

Another way to get it is:
```py
x & (~(x-1))
```

## 2^n represntation has n+1 bits, first is 1 followed by n zeros

Similarly `2^n - 1` has n bits, all set to 1.

## ith bit means ith bit from right 

`1 << n` => 1 shifted by n places, also means $2^n$
e.g. `1 << 2` => 1 shifted by 2 places i.e. `100` = 4 = $2^2$

## Right shift (divide by 2 and floor)

$$ x >> y = \left\lfloor \frac{x}{2^y} \right\rfloor $$

## Left shift (multiply by 2)

$$ x << y = x * 2^y $$

## Setting nth bit

`x | (1 << n)`

## clear nth bit

`x & ~(1 << n)`

## flip the nth bit

`x ^ (1 << n)`

xoring 1 with existing bit helps in flipping it.

## Left shifting longs (working with more than 32 bits)

```
1L << 40
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

## Toggle n'th bit (from the end)

`1 << n` represents $2^n$

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

## Java `Integer` utilities

### Lowest set bit

`public static int lowestOneBit(int i)`
Returns an int value with at most a single one-bit, in the position of the lowest-order ("rightmost") one-bit in the specified int value. Returns zero if the specified value has no one-bits in its two's complement binary representation, that is, if it is equal to zero.


### number of leading zeros

### Number of trailing zeros

### bitcount/popcount

`public static int bitCount(int i)`
Returns the number of one-bits in the two's complement binary representation of the specified int value. This function is sometimes referred to as the population count.

## XOR operator

Xor is just asking if the bits are different? then 1,
if the bits are same, then 0.

You can think of XOR as add but no carry allowed anywhere.

### Given a xor of two different numbers (that appear only once in a list) how to get those individual numbers, given a list of numbers?

For numbers which repeat, will be cancelled out via XOR, remaining you will have two numbers whose xor you have X.
pick any bit set in the X, now check if that bit was set in given list of numbers, 
XOR all of them, even ones will cancel out, remaining one will be one of your two numbers that appear only once.
you have your number, other numbers


### XOR for numbers from 1 to n

You have to notice the pattern by writing numbers down and seeing their cumulative XOR, it repeats with a periodicity of 4.

The cumulative xor upto `n` follows this: `n, 1, n+1, 0` periodically when remainder is `0, 1, 2,3` respectively. 
E.g. see this table

| num  |      |     |     |     | xor including previous elements |
|:---: | :---:|:---:|:---:|:---:|:---:                            |
| 0    |  0   |  0  |  0  |   0 |        0 `n`                    |
| 1    |  0   |  0  |  0  |  1  |        1                        |
| 2    |  0   |  0  |  1  |  0  |        11 = 3 `n+1`             |
| 3    |  0   |  0  |  1  |  1  |        00 = 0                   |
| 4    |  0   |  1  |  0  |  0  |        100 = 4 `n`              |
| 5    |  0   |  1  |  0  |  1  |        001 = 1                  |
| 6    |  0   |  1  |  1  |  0  |        111 = 7 `n+1`            |
| 7    |  0   |  1  |  1  |  1  |        000 = 0                  |
| 8    |  1   |  0  |  0  |  0  |       1000 = 8 `n`              |
| 9    |  1   |  0  |  0  |  1  |       0001 = 1                  |
| 10   |  1   |  0  |  1  |  0  |       1011 = 11 `n+1`           |
| 11   |  1   |  0  |  1  |  1  |       0000 = 0                  |
| 12   |  1   |  1  |  0  |  0  |       1100 = 12 `n`             |

Ans is:
```java
int getAns(n) {
    switch(n%4) {
        case 0: return n;
        case 1: 1;
        case 2: return n+1;
        case 3: return 0;
    }
}
```

This can also be used to calculate XOR of intermediate ranges e.g. `[L..R]` if necessary. e.g. Xoring `F(1..R) ^ F(1..L)`
will give you `XOR(L..R)`, because first L elements willg get cancelled.

## Operator precedence

negation/tiled operators take precedence over shift operators `>>`, `<<`, take precedence over other and,or operators (`|`, `&`).

## tilde operator (gives ones complement)

The Tilde (`~`) performs a bitwise complement of a numerical value in Java.

only used with integer values
inverts the bits ie a 0-bit becomes 1-bit and vice versa
in all cases `~x` equals `(-x)-1`

## Relation between twos complement and one compelement


`~x` = `(-x) - 1` (subtracting 1 from twos complement gives us ones complement)
or
`-x = ~x + 1` (Adding one to ones complement gives us twos complement)

Another useful identity = `~(x-1) = -x` or
in other words:
`~(x-1) = ~x + 1 = -x`

## Bitset class

https://docs.oracle.com/javase/7/docs/api/java/util/BitSet.html

## a&b is given, a|b is given, what is a+b?

`a + b` = `a & b` + `a | b`

## Properties of or and anding

`a | b >= max(a,b)`, all ones are accumulated
`a & b <= max(a,b)`, only common ones survive.

## Masking idea

Representing set with an integer.
Each ith bit on integer signifies if ith item is in set or not.

`&` these ints, gives you intersection of representive sets

`|` these ints, gives you union of representative sets.

`^` these ints, it gives you the `union - intersection` of these sets.

### Checking ith item set membership

`((1 << i) & x) != 0` if ith bit is in set -> be careful with brackets

Alternative way to do this is:
`((x >> i) & 1) == 1` , we shift x by i bits, bringing it to end by right shifting and check if it is set or not.

## Hamming distance

The hamming distance between two bit strings of length `a` and `b` is the number of bits in where they differ

e.g. `hamming(4,5) = hamming(100, 101) = 1`

straightforward way to calculate:
```java
public int hamming(String a, String b) {
    int d = 0;
    for(int i=0;i<a.length();i++) {
        if(a.charAt(i) != b.charAt(i)) {
            d++;
        }
    }
    return d;
}
```

Faster way to calculate if `a` and `b` are represented as int.

```java
public int hamming(int a, int b) {
    return Integer.bitCount(a ^ b);
}
```

## Tricky questions

### find the minimum xor of pair of elements in an array

Sort the array in increasing order.
Min xor will be xor of `arr[i] ^ arr[i+1]`

Proof: interesting, higher numbers have 1 bit set in higher positions.


### find total number of set bits for all integers from 0 to n

observation based idea
