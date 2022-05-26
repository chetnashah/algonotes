

##

Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. **The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.**

You are given a helper function bool `knows(a, b)` that tells you whether A knows B. 
Implement a function int `findCelebrity(n)`. There will be exactly one celebrity if they are at the party.


## Core idea

on each comparision, we can rule out one non-celebrity and other one as possible celebrity.

## Round one: find out a possible celebrity candidate

`celebCandidate` will always be less than or equal to `i`.

```java
int celebCandidate=0;
for(int i=0;i<n;i++) {
    // core idea: on each comparision, we can rule out one non-celebrity and other one as possible celebrity
    if(knows(celebCandidate, i) && !knows(i, celebCandidate)){// better candidate found via conditions
        celebCandidate = i;
    }
}
```

## Round two: verify selected celebrity is actually a candidate

N-1 calls to see if all other nodes know celebrity candidate
N-1 calls to see that celebrity candidate does not know anyone else.

```java
/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    private int numPeople;
    public int findCelebrity(int n) {
        numPeople = n;
        int celebCandidate=0;
        for(int i=0;i<n;i++) {
            // core idea: on each comparision, we can rule out one non-celebrity and other one as possible celebrity
            if(knows(celebCandidate, i) && !knows(i, celebCandidate)){// better candidate found via conditions
                celebCandidate = i;
            }
        }
        if(isCelebrity(celebCandidate)) {
            return celebCandidate;
        }
        return -1;
    }
    
    private boolean isCelebrity(int i) {// verify if celebrity
        for(int j=0;j<numPeople;j++) {
            if(i == j) continue;
            if(knows(i,j) || !knows(j,i)) {
                return false;
            }
        }
        return true;
    }
}
```