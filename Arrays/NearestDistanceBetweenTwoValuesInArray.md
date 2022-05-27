
## given two values in an array (can be multiple repitions of that values), return shortest distance between those two values (a query)

https://leetcode.com/problems/shortest-word-distance-ii/

## Common solution (hashmap to record positions, compare on query)

record hashmap to capture positions for each array item entry
`v1 -> [i1, i2, ...]`
and 
`v2 -> [j1, j2, ...]`

When asked for shortest distance between `v1` and `v2`:
Compare lists p1 and p2 which hold positions for v1 and v2 within array.
`Return min abs diff between p1[i] and p2[j], for all values of i,j`.

Here query is very expensive: O(N^2)
space for hashmap would be O(N)


## Two pointers

hashmap but store positions in a TreeSet i.e sorted position list. (Actually there is no need for TreeSet since we are iterating original array from left to right, the inserted positions will always be increasing.)

To find nearest two values in two different sorted lists, we used two pointers.

Start both pointers to initial element
`Conditions for pointer increment`:
increment the pointer of smaller element (out of the two pointers), so that it has a chance to be same or reduce absolute difference from other value in other list.

At each step record minSeenTillNow.

This has O(N) for query since both arrays are traversed atmost once.

## Code

```java
class WordDistance {
    Map<String, Set<Integer>> posMap = new HashMap<>();
    
    public WordDistance(String[] wordsDict) {
        for(int i=0;i<wordsDict.length; i++) {
            String word = wordsDict[i];
            Set<Integer> positions = posMap.getOrDefault(word, new TreeSet<>());
            positions.add(i);
            posMap.put(word, positions);
        }
    }
    
    public int shortest(String word1, String word2) {
        if(word1.equals(word2)) {
            return 0;
        }
        int minDiffInPos = Integer.MAX_VALUE;
        List<Integer> word1Positions = new ArrayList<Integer>(posMap.get(word1));
        List<Integer> word2Positions = new ArrayList<Integer>(posMap.get(word2));
        Integer p1 = 0;
        Integer p2 = 0;
        
        while(p1 != word1Positions.size() && p2 != word2Positions.size()) {
            int diffInPos = Math.abs(word1Positions.get(p1) - word2Positions.get(p2));
            if(diffInPos < minDiffInPos) {
                minDiffInPos = diffInPos;
            }
            if(word1Positions.get(p1) < word2Positions.get(p2)) {
                p1++; // p1 get chances to be closer to p2
                //p1.next();
            } else {
                p2++; // p2 gets chances to be closer to p1
                //p2.next();
            }
        }
        // 
        if(p1 == word1Positions.size() && p2 != word2Positions.size()) {
            while (p2 != word2Positions.size()) {
                int diffInPos = Math.abs(word1Positions.get(p1-1) - word2Positions.get(p2));
                if(diffInPos < minDiffInPos) {
                    minDiffInPos = diffInPos;
                }
                p2++;
            }
        } else if (p2 == word2Positions.size() && p1!= word1Positions.size()) {
            while (p1 != word1Positions.size()) {
                int diffInPos = Math.abs(word2Positions.get(p2-1) - word1Positions.get(p1));
                if(diffInPos < minDiffInPos) {
                    minDiffInPos = diffInPos;
                }
                p1++;
            }
        }
        
        return minDiffInPos;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(wordsDict);
 * int param_1 = obj.shortest(word1,word2);
 */
```

