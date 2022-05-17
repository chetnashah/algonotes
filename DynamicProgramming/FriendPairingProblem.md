
## Description

Given n friends, each one can remain single or can be paired up with some other friend.
Each friend can be paired only once. 
 
Find out the total number of ways in which friends can remain single or can be paired up.

## Recurrence

Each new friend entering has two options:
1. stay single ( no of ways to have remaining friends paired = f(n-1))
2. pair up with any one of the n-1 friends, this leaves n-2 friends to be paired up so (n-1 * f(n-2)) (by product counting principle)

Since these two events are exclusive and count total ways to pair n friends(by addition principle):
```
f(n) = f(n-1) + n-1 * (f(n-2))
```

