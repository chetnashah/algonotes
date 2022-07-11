

##

https://leetcode.com/problems/median-of-two-sorted-arrays/

##

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```
Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 ```

Constraints:
```
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
```

## Obvious approach: Merge arrays and report median - O(m+n)

### Refer merge sort to merge two sorted arrays

[Merge sort](../sorting/../Sorting/MergeSort.md)

## O(log (m+n)) approach

### Idea 1: Total number of elements will be m+n, so we want m+n/2 th element.

### Idea 2: We must find index i in first array, and index j in second aray such that i+j = (m+n)/2

we can search on either i or j, and calculate the other one, by subtracting from `(m+n)/2`.

### Idea 3: partition predicate condiitons `arr2[0..j] <= arr1[i+1..end]` and `arr1[0..i] <= arr2[j+1..end]`

This  makes sure, that `arr1[0..i]` along with elements `arr2[0..j]` fall to the left of median.

Binary search predicate condition is the one mentioned above.
first indices `i`,`j` such that
`arr2[0..j] <= arr1[i+1..end]` and `arr1[0..i] <= arr2[j+1..end]`


### Pick median from last value of first partitions of both arrays, and first value of second partitions of both array

## Code TODO

```java

```