
## Resources

https://cp-algorithms.com/string/string-hashing.html

## Goal

Map a string s to a number n, `H(s) =  n` such that:
```
s1 == s2 <=> H(s1) == H(s2)
s1 != s2 <=> H(s1) != H(s2) // best effort with high probability, can have collisions
```
`H(s)` should be O(1) or O(lgN).
`H(s)` can be long long to have lesser collisions (bcoz bigger range).


## Polynomial Rolling hash technique

Given a string `S = s0s1s2...sN-1`
```
H(S) = Sum_i_From_0_to_N-1(si * (p ^ i)) % MOD
```
or in other words
```
H(S) = ((s[0] * 1) + (s[1] * p) + (s[2] * p^2) + ... + (s[n-1] * p^(n-1))) % MOD 
```
`p` = should be prime number greater than alphabet size. Why?
`MOD` to be used when you dont want H(S) to overflow int for e.g. 10^9 + 7 -> Probability of two random strings colliding ~ 1/MOD.

## Charachter encoding

* Why not start with `a -> 0` ? Then all strings `a`, `aa`, `aaa`, ... will evaluate to same hash 0.

So use following encoding

```
a -> 1
b -> 2
...
z -> 26
```

## Precomputing power array `P[i]`



### Rolling charechteristic (adding removing charachters from either ends)

If we know hash of a string `H(s)`,
we can easily calculate `H(s+c)` or `H(c+s)` where `c` is a single charachter in O(1) (how?)

### Hash-Prefix array

Calculating hash of every prefix is O(N)
We can have an array that stores hash of prefixes: `HP[i] = hash of prefix of all charachters upto i`.

## Get hash of given substring `H(s[i..j])`, i,j inclusive

