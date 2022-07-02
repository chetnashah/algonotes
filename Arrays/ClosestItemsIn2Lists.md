

We are given 2 lists (sorted).

We have to find nearest items in these two lists.

## Two pointers approach

keep increasing pointers in both lists to so that we can make them as near as possible,
keep track of min diff

## Algorithm code

```java
int findClosestDistanceInTwoLists(List<Integer> l1, List<Integer> l2){
    int p1 = 0;
    int p2 = 0;
    int minDiff = wordsDict.length;
    
    // two pointers, increment pointers to make values near to each other
    while(p1<l1.size() && p2<l2.size()) {
        if(Math.abs(l1.get(p1) - l2.get(p2)) < minDiff) {
            minDiff = Math.abs(l1.get(p1) - l2.get(p2));
        }
        
        if(l1.get(p1) < l2.get(p2)) {
            p1++;
        }else {
            p2++;    
        }
    }
    
    return minDiff;
}
```

## Variation: K lists instead of 2



## Application problems

This can be used to calculate closest distance between given two values `a`,`b` in a single list:

Idea is following:
1. capture positions of `a` in list `l1`.
2. Capture positions of `b` in list `l2`.
3. Run above algorithm to find `minDiff(l1, l2)` to find shortest/closest word distance between given two words.

https://leetcode.com/problems/shortest-word-distance/
https://leetcode.com/problems/shortest-word-distance-ii/



