
## Resources

https://austinrochford.com/posts/2013-10-28-median-of-medians.html

https://www.youtube.com/watch?v=zYM8AqIOVi0

https://www.youtube.com/watch?v=fcf56RTbkHc

https://www.youtube.com/watch?v=sNtu2oGDRvU

http://people.csail.mit.edu/rivest/pubs/BFPRT73.pdf

## Meaning of median

Median - n/2th element in a sorted sequence.

## Core Idea

Choosing pivots that appears around center is very useful (based on recurrence analysis)

1. Find approximate median of an array in O(N).
2. When approximate median is used as a pivot, the worst case of quicksort/quickselect reduces to O(N).

## Main Steps

1. If we have 5 or less than 5 elements in the input array, we simply take its first element as the pivot. If not then we divide the input array into subarrays of five elements (for simplicity we can ignore any subarray having less than five elements). - we will have n/5 arrays each with 5 elements.
2. Sort each subarray to determine its median. i.e. **determine median of each 5-element subarray**. Sorting a small and fixed numbered array takes constant time. At the end of this step, we have an array containing medians of all the subarray.
3. Recursively call the partitioning algorithm on the array containing medians until we get our pivot.
4. Every time the partition procedure needs to find a pivot, it will follow the above three steps.

## Implementation

```java
  private static int medianOfMedians(int[] nums, int low, int high) {
    int n = high - low + 1;
    // if we have less than 5 elements, ignore the partitioning algorithm
    if (n < 5)
      return nums[low];

    // for simplicity, lets ignore any partition with less than 5 elements
    int numOfPartitions = n / 5; // represents total number of 5 elements partitions
    int[] medians = new int[numOfPartitions];
    for (int i = 0; i < numOfPartitions; i++) {
      int partitionStart = low + i * 5; // starting index of the current partition
      Arrays.sort(nums, partitionStart, partitionStart + 5); // sort the 5 elements array
      medians[i] = nums[partitionStart + 2]; // get the middle element (or the median)
    }

    return partition(medians, 0, numOfPartitions - 1);
  }
```

## Order statistic using Median of medians

```java
import java.util.*;

class KthSmallestNumber {

  public static int findKthSmallestNumber(int[] nums, int k) {
    return findKthSmallestNumberRec(nums, k, 0, nums.length - 1);
  }

  public static int findKthSmallestNumberRec(int[] nums, int k, int start, int end) {
    int p = partition(nums, start, end);

    if (p == k - 1)
      return nums[p];

    if (p > k - 1) // search the lower part
      return findKthSmallestNumberRec(nums, k, start, p - 1);

    // search the higher part
    return findKthSmallestNumberRec(nums, k, p + 1, end);
  }

  private static int partition(int[] nums, int low, int high) {
    if (low == high)
      return low;

    int median = medianOfMedians(nums, low, high);
    // find the median in the array and swap it with 'nums[high]' which will become our pivot
    for (int i = low; i < high; i++) {
      if (nums[i] == median) {
        swap(nums, i, high);
        break;
      }
    }

    int pivot = nums[high];
    for (int i = low; i < high; i++) {
      // all elements less than 'pivot' will be before the index 'low'
      if (nums[i] < pivot)
        swap(nums, low++, i);
    }
    // put the pivot in its correct place, remember nums[high] is our pivot
    swap(nums, low, high);
    return low;
  }

  private static void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  private static int medianOfMedians(int[] nums, int low, int high) {
    int n = high - low + 1;
    // if we have less than 5 elements, ignore the partitioning algorithm
    if (n < 5)
      return nums[low];

    // for simplicity, lets ignore any partition with less than 5 elements
    int numOfPartitions = n / 5; // represents total number of 5 elements partitions
    int[] medians = new int[numOfPartitions];
    for (int i = 0; i < numOfPartitions; i++) {
      int partitionStart = low + i * 5; // starting index of the current partition
      Arrays.sort(nums, partitionStart, partitionStart + 5); // sort the 5 elements array
      medians[i] = nums[partitionStart + 2]; // get the middle element (or the median)
    }

    return partition(medians, 0, numOfPartitions - 1);
  }

  public static void main(String[] args) {
    int result = KthSmallestNumber.findKthSmallestNumber(new int[] { 1, 5, 12, 2, 11, 5 }, 3);
    System.out.println("Kth smallest number is: " + result);

    // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
    result = KthSmallestNumber.findKthSmallestNumber(new int[] { 1, 5, 12, 2, 11, 5 }, 4);
    System.out.println("Kth smallest number is: " + result);

    result = KthSmallestNumber.findKthSmallestNumber(new int[] { 5, 12, 11, -1, 12 }, 3);
    System.out.println("Kth smallest number is: " + result);
  }
}
```