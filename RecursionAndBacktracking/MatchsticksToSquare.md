

##

https://leetcode.com/problems/matchsticks-to-square/

##

Same as [Partition to K subsets with equal sum = sideLenth](PartitionToKSubsetsWithEqualSum.md)

## Todo understand other solutions

https://leetcode.com/problems/matchsticks-to-square/solution/

## Code

```java
class Solution {

    Map<String, Boolean> memo;
    public boolean makesquare(int[] matchsticks) {
        
        int totalLen = 0;
        Arrays.sort(matchsticks);
        for(int i=0;i<matchsticks.length;i++) {
            totalLen += matchsticks[i];
        }
        
        if(totalLen % 4 != 0) {
            return false;
        }
        // System.out.println("totalLen = " + totalLen);
        
        int sideLen = totalLen/4;        
        // System.out.println("sideLen = "+sideLen);
        
        for(int i=0;i<matchsticks.length;i++) {
            if(matchsticks[i] > sideLen) {
                return false;
            }
        }
        
        memo = new HashMap<>();
        Collections.sort(Arrays.asList(matchsticks), Collections.reverseOrder());
        
        // initially no matchsticks are taken
        char[] taken = new char[matchsticks.length];
        for(int i=0;i<matchsticks.length;i++) {
            taken[i] = '0';
        }
        
        // find 4 subsests with equal sum
        return backtrackHelper(matchsticks, 0, 0, 0, sideLen, 4, taken);
    }
    
    boolean backtrackHelper(int[] matchsticks, int count, int idx, int currSum, int targetSumPerSubset, int k, char[] taken) {
        if(count == k-1){
            return true;
        }
        
        if(currSum > targetSumPerSubset) {
            return false;
        }
        
        // memo on taken state
        if(memo.containsKey(new String(taken))) {
            return memo.get(new String(taken));
        }
        
        if(currSum == targetSumPerSubset) {
            boolean ans = backtrackHelper(matchsticks, count+1, 0, 0, targetSumPerSubset, k, taken);
            memo.put(new String(taken), ans);
            return ans;
        }
        
        for(int j= idx;j<matchsticks.length;j++) {
            if(taken[j] == '0') {// pick first unpicked matchstick
                taken[j] = '1';
                // choice of next matchsticks leading to answer?
                if(backtrackHelper(matchsticks, count, idx+1, currSum+matchsticks[j], targetSumPerSubset, k, taken)) {
                    memo.put(new String(taken), true);
                    return true;
                }
                //backtrack
                taken[j] = '0';
            }
        }
        
        memo.put(new String(taken), false);
        return false;
        
    }
}
```