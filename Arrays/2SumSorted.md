
## Brute force O(N^2) - try all pairs

## Better O(N lg N) - binary search the complement

For every start index in the array, binary search for `target-arr[startIdx]` i.e. the complement value.

This would be a O(N lg N) algorithm.

## Best two pointers - start and end of the array

Pick first and last index in array.

### Pointer update conditions

1. If sum of first and last idx is less than desired sum/target, we increase the startIdx to increase the sum.
2. If sum of first and last idx is greater than desired sum/target, we decrease the endIdx to decrease the sum.

### Proof

The lowest sum would be the first two indices in sorted array i.e. `arr[0] + arr[1]`
The highest sum would be the last two indices in sorted array i.e. `arr[n-2] + arr[n-1]`

All other sums are in between the highest sum and lowest sum.
by managing two pointers we are ignoring all sums that cannot meaningfully contribute to the sum.

### Code

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length - 1;
        
        while(numbers[start] + numbers[end] != target) {
            if(target > numbers[start] + numbers[end]) {
                start++;
            } else {
                end--;
            }
        }
        
        return new int[]{start + 1, end + 1};
    }
}
```