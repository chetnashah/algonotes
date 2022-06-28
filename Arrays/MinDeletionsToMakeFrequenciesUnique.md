

##

https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

## Approach 1: Count frequencies, keep a set of seen frequencies and keep decrementing till you have an unseen frequency.

## TODO Time complexity

### Code

```java
class Solution {
    public int minDeletions(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for(int i=0;i<s.length();i++) {
            Character c = s.charAt(i);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        
        Set<Integer> seenFrequencies = new HashSet<>();
        int deleteCnt = 0;
        for(Integer fCount: freq.values()) {
            if(!seenFrequencies.contains(fCount)) {
                seenFrequencies.add(fCount);
            } else {
                while(fCount>=0) {// 1 0, 1 0
                    if(!seenFrequencies.contains(fCount)) { //  
                        seenFrequencies.add(fCount); // 1 4 0
                        break;
                    } else if (fCount == 0 && seenFrequencies.contains(0)) {// dont count 0 multiple times
                        break;
                    }
                    deleteCnt++;// 2
                    fCount--; // 0, 0
                }
            }
        }
        System.out.println(seenFrequencies);
        return deleteCnt;
    }
}
```

## Priority queue approach

### Observation 1: if multiple characters have the same frequency, then only one character can keep all of its instances. 

if multiple characters have the same frequency, then only one character can keep all of its instances.
All other characters must have one or more of their instances deleted.

### TODO check logic and code from

https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/solution/



## Sorting based approach (sort by decreasing frequencies), and update delete count by deleting from maxallowed frequencies

### Collect all frequencies in an array

### Sort by decreasing frequency

e.g. "ceabaacb"
`a -> 3`
`b->2`
`c->2`
`e -> 1`

Array becomes -> | 3 | 2 | 2 | 1 |

### Max allowable frequency should be one less than previous

At each point max allowable frequency is one less than previous one
so. max allowable frequencies would be: | 3 | 2 | 1 | 0 |

### get the difference between actual frequency and allowable frequencies to get the delete count

### Code

```java
class Solution {
    public int minDeletions(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for(int i=0;i<s.length();i++) {
            Character c = s.charAt(i);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        // System.out.println(freq);
        
        int deleteCnt = 0;
        List<Integer> freqList = new ArrayList<>();
        freqList.addAll(freq.values());
        // sort in decreasing order of frequency
        freqList.sort(Collections.reverseOrder());
        // System.out.println(freqList);
        
        int maxAllowableFrequency = freqList.get(0)-1;
        for(int i=1;i<freqList.size();i++) {
            // System.out.println(" i = " + i +" maxAllowableFreq = " + maxAllowableFrequency);
            // if current frequency exceeds, max allowable frequency, delete by necessary amount
            if(freqList.get(i) > maxAllowableFrequency) {
                deleteCnt += freqList.get(i) - maxAllowableFrequency;// capture delete count as difference from max allowed frequency
                freqList.set(i, maxAllowableFrequency); // set max allowed frequency
            }
            // update maxAllowable frequency for next iteration
            maxAllowableFrequency = (freqList.get(i)-1) >= 0 ? (freqList.get(i)-1) : 0;
        }
        
        return deleteCnt;
    }
}
```

