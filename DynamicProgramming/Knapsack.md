

## Given capacity N and a set K, maximize or count number of ways to fill N.

There are 𝑁 items. The 𝑖-th item has weight 𝑤𝑖 and value 𝑣𝑖. 
Find a set 𝑆 such that ∑𝑖∈𝑆 (𝑤𝑖≤𝐶) and ∑𝑖∈𝑆(𝑣𝑖) is maximized

## 0-1 knapsack

you can either pick or ignore an item completely. No fractional stuff allowed.

## Unbounded knapsack

Repitition of picking of items is allowed

There are 𝑁 items. The 𝑖-th item has weight 𝑤𝑖 and value 𝑣𝑖. 
Find a multiset 𝑆 such that ∑𝑖∈𝑆 (𝑤𝑖≤𝐶) and ∑𝑖∈𝑆(𝑣𝑖) is maximized.

### Integer partition problem (Same as coin change ways)

Count no. of partitions e.g.
no. partitions of 5 = 7
1 + 1 + 1 + 1 + 1
1 + 1 + 1 + 2
1 + 1 + 3
1 + 4
1 + 2 + 2
2 + 3
5 + 0

A variation on unbounded knapsack. a 2-d dp on all targets vs items/coins.
We are looking for all multiset S such that sum of elements in multi set equals Target C.


## Subset sum

There are 𝑁 items. The 𝑖-th item has weight 𝑤𝑖. 
Find a set 𝑆 such that ∑𝑖∈𝑆(𝑤𝑖=𝐶)

It is variant of knapsack where we are looking for subset that sums exact weight C.
Another variant: count such subsets which add up to weight C.
Another variant: canSum -> returning true/false if a subset exists that can sum to weight C.