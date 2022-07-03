
##

https://leetcode.com/problems/longest-string-chain/

##

Same logic as Longest increasing subsequence,
special logic to determine increasing.

Minor optimization: only look at one length smaller strings to see if increasing.


## Code

```java
class Solution {
    public int longestStrChain(String[] words) {
        if(words.length == 1) {
            return 1;
        }
        
        // sort by length of words
        Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));
        
        // System.out.println(Arrays.toString(words));
        // only look at one length smaller words to form chain
        int[] ans = new int[words.length];
        Arrays.fill(ans, 1);
        // a method to check if predecessor
        for(int i=1;i<words.length;i++) {
            for(int j=i-1;j>=0 && words[j].length() >= words[i].length()-1;j--) {
                if(words[j].length() == words[i].length()) {
                    continue;
                }
                if(words[j].length() == words[i].length() - 1) {
                    if(singleDiffShorter(words[j], words[i])) {
                        ans[i] = Math.max(ans[i], ans[j] + 1);
                    } else {
                        // System.out.println("not ok: "+words[j] +" " + words[i]);
                    }
                }
            }
        }
        
        // System.out.println(Arrays.toString(ans));
        int ansMax = 1;
        for(int i=0;i<ans.length;i++) {
            ansMax = Math.max(ansMax, ans[i]);
        }
        
        return ansMax;
    }
    
    public boolean singleDiffShorter(String s, String l) {
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) != l.charAt(i)) {
                return s.substring(i).equals(l.substring(i+1));
            }
        }
        return true;
    }
}
```