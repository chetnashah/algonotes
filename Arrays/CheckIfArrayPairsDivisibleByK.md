

##

https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

## Variations

Count instead of possibility: https://leetcode.com/problems/count-array-pairs-divisible-by-k/


## Core Idea
we can group all numbers into (modulo k buckets) -> remainders will be 0 to k-1.

Gotchas -> negative numbers (https://stackoverflow.com/questions/4412179/best-way-to-make-javas-modulus-behave-like-it-should-with-negative-numbers/4412200#4412200)

Gotchas -> sum total can overflow

e.g. 
```
1 -> 1 (mod 5)
2 -> 2 (mod 5)
3 -> 3 (mod 5)
4 -> 4 (mod 5)
5 -> 0 (mod 5)
10 -> 0 (mod 5)
6 -> 1 (mod 5)
7 -> 2 (mod 5)
8 -> 3 (mod 5)
9 -> 4 (mod 5)

After grouping
[1, 6] -> 1 (mod 5)
[2, 7] -> 2 (mod 5)
[3, 8] -> 3 (mod 5)
[4, 9] -> 4 (mod 5)
[5, 10] -> 0 (mod 5)
```
Here we must verify that
the number of elements in `j (mod N)` bucket is same as `(N-j) (mod N)` bucket, so that they can form pairs.

## COde

```java
class Solution {
    public boolean canArrange(int[] arr, int k) {
        
        // odd number of items, cannot be divided in pairs
        if(arr.length % 2 != 0) {
            return false;
        }
        
        // check if totalsum is divisible by k
        int total = 0;
        for(int i=0;i<arr.length;i++) {
            total += arr[i] % k; // total can overflow
        }
        
        // sum total is not multiple of k, then not possible
        if(total % k != 0) {
            return false;
        }
        
        // count bucket items by putting item in  item (mod k) bucket 
        // elements in bucket i and k-i can sum up to be divisible by k
        int[] buckets = new int[k];
        for(int i=0;i<arr.length;i++) {
            int bucket = ((arr[i] % k) + k ) %k;// to take care of negative numbers
            buckets[bucket]++;
        }
        
        // System.out.println("buckets[0] = " + buckets[0]);
        
        // we should have even number of items that exactly divide k
        if(buckets[0] % 2 != 0) {
            return false;           
        } 
        
        boolean ans = true;
        // check if complements for (mod k) have the same count
        for(int i=1;i<=k/2;i++) {
            ans = ans && buckets[i] == buckets[k-i];
        }
        
        return ans;
    }
}
```