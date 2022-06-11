

## Two pointers technique

For each end pointer we can count no. of windows ending in index i, and add them cumulatively

## code

```java
import java.util.Scanner;
import java.util.*;

public class Solution 
{
    public static int kDistinctSubarrays(int arr[], int n, int k) 
	{
        // Write your code here.    
        if(k==0) {
            return 0;
        }
        Map<Integer,Integer> freq = new HashMap<>();
        int distinctCnt = 0; // count of distinct nums in running window
        int windowStart = 0;
        int validWindows = 0;
        for(int windowEnd = 0;windowEnd<arr.length;windowEnd++) {
            freq.put(arr[windowEnd],freq.getOrDefault(arr[windowEnd], 0) + 1);
            if(freq.get(arr[windowEnd]) == 1) {
                distinctCnt++;
            }
            
            while(windowStart <= windowEnd && distinctCnt > k) {// bad window, increment start
                // elsSet.remove(els[windowStart]);
                if(freq.get(arr[windowStart]) == 1) {
                    distinctCnt--;
                }
                freq.put(arr[windowStart], freq.get(arr[windowStart]) - 1);
                windowStart++;
            }
            // count valid windows
            validWindows += windowEnd - windowStart + 1;
        }
        return validWindows;
    }
}

```