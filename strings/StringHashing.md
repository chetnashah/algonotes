
## Resources

https://cp-algorithms.com/string/string-hashing.html
https://codeforces.com/blog/entry/60445

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
`gcd(p,MOD) = 1` - why?

## Charachter encoding

* Why not start with `a -> 0` ? Then all strings `a`, `aa`, `aaa`, ... will evaluate to same hash 0.

So use following encoding

```
a -> 1
b -> 2
...
z -> 26

For any char c,
c -> (c - 'a' + 1) 
```


## Precomputing power array `P[i]`

This can be calculated using this recurrence:
```
P[0] = 1
P[k] = P[k-1] * p % MOD
```

In cpp:
```cpp
vector<long long> p_pow(max(S, T)); 
p_pow[0] = 1; 
for (int i = 1; i < (int)p_pow.size(); i++) 
    p_pow[i] = (p_pow[i-1] * p) % m;
```

### Rolling charechteristic (adding removing charachters from either ends)

If we know hash of a string `H(s)`,
we can easily calculate `H(s+c)` or `H(c+s)` where `c` is a single charachter in O(1) (how?)

### Hash-Prefix array

Calculating hash of every prefix is O(N)
We can have an array that stores hash of prefixes: `HP[i] = hash of prefix of all charachters upto and including i`.

Hash prefix array can be calculated by following recurrence:
```
HP[0] => 0 + p[0] * s[0] % MOD => 0 + 1 * s[0] % MOD => s[0]
HP[k] = (HP[k-1] + p[k-1] * s[k-1]) % MOD, where k = 1 to N-1
```

```cpp
vector<long long> hp(T, 0); 
for (int i = 0; i < T; i++) {
    if(i != 0) {
        hp[i] = hp[i-1];
    }
    hp[i] = (hp[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
}
```

## Get hash of given substring `H(s[L..R])`, L,R inclusive

```cpp
int hash_fast(int L, int R) {// H(s[L..R]) , L, R inclusive
    if (L == 0) return hp[R]; // H(s[0..R])
    int ans = 0;
    ans = ((h[R] - h[L-1]) % MOD + MOD) % MOD;
    ans = ((ll) ans * modInverse(P[L], MOD)) % MOD;
    return ans; 
}
```

## Directly calculate hash of a string : O(n)

Applicatio of the formula
```cpp
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) { // for every char in s
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
```

## modInverse implementation


