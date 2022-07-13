

### Division algorithm

Simultaneously defines quotient and remainder.

For any m,n in natural numbers, (there exists a way to break one number in terms of another)
`m = q.n + r`
`m = q.n + m mod n`
`m = floor(m/n).n + m mod n`

Here quotent `q = floor(m/n)`
and remainder `r = m mod n`

E.g. m = 2, n = 3
`3` = 1.`2` + 1
and
`2` = 1.`3` + (-1)

### mod vs % operator

`a = b (mod m)` means `m divides a-b`.

`(mod m)` means a universe/group where the remainder is same when divided by `m`.
e.g. `7 = 1 (mod 6)`: means `7` and `1` give same remainder when divided by `6`.
`% m` means remainder on dividing with `m`.


### Modulo of negative numbers

https://stackoverflow.com/questions/4412179/best-way-to-make-javas-modulus-behave-like-it-should-with-negative-numbers/4412200#4412200

### Divides relation

Forms a partial order over integers.

Notation for a divides b is `a | b`.
if `a divides b` then `b mod a = 0` 

### GCD definition

Also known as largest common factor.

Let a,b be non-zero integers.
GCD is unique natural number d such that,
1. `d | a` and `d | b`.
2. If there is a `c | a` and `c | b` , then `c | d` - a smaller common factor `c` between a and b

### GCD algorithm

```java
int gcd (int a, int b) { // if a < b, then first call will swap a and b.
    if (b == 0) { // b will reach 0 first
        return a; // a will be larger than b in all calls
    } else {
        return gcd (b, a % b);// recursively pass smaller part and the remainder (which is even smaller)
    }
}
```

### Multiplicative Modular inverse

The modular inverse of a number a, is a number x such that `ax = 1 (mod m)`.

We deonte `x` as `a^-1 (mod m)`, hence the name modular inverse

`Note`: the modular inverse exists if and only if `a` and `m`  are relatively prime, or in another words `gcd(a,m) = 1`.
Proof: TODO

## Euler's totient function (phi function)

`phi(n) = number of integers between 1 to n inclusive, that are coprime to n`

**1 is considered to be coprime to any number**
**n is not considered coprime to itself because gcd(n,n) = n**

| n       |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |
|:---:    |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---: |
| phi(n)  |  1  |  1  |  2  |  2  |  4  |  2  |  6  |  4  |  6  |  4   |


if `p` is prime, `phi(p) = p-1`, since all `p-1` integers are coprime to `p`.


## Extended Euclidean's algorithm (get `p`, `q` and `gcd(a,b)`, given a and b)

https://brilliant.org/wiki/extended-euclidean-algorithm/

https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

For any two integers `a` and `b`, 

extended eucliedean algorithm finds the `gcd(a,b)` as well as `p`,`q`, such that`gcd(a,b) = ab + pq`.

**Core Idea**: By reversing the steps in the Euclidean algorithm, it is possible to find these integers xx and yy. The whole idea is to start with the GCD and recursively work our way backwards.



## Check if number is perfect square

take `(int)floor(sqrt(x))`, and try multiplying it with itself to see if we get original number.

```java
boolean isPerfectSquare(int x) {
    if(x>=0) {
        int sqrt = (int)Math.sqrt(x);

        return (sqrt*sqrt == x);
    }
    return false;
}
```