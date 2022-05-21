

## Description

Caching.
* Cache with capacity to store `k items`.
* Sequence of `m item requests d1, d2, …, dm`.
* Cache hit: item already in cache when requested.
* Cache miss: item not already in cache when requested: must bring
requested item into cache, and evict some existing item, if full.

**Goal**: Eviction schedule that minimizes number of cache misses