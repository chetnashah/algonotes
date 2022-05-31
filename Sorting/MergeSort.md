
## Classic sorting algorithm


## Needs O(n) extra space

## MergeSort function takes an array to sort, and returns new array 

```java
	private int[] mergeSort(int[] input){
        //...
    }
```

### In MergeSort function, create two new subarrays and pass them to merge fn

```java
	private int[] mergeSort(int[] input){
        int[] left = // first half of input
        int[] right = // second half of input
        return merge(mergeSort(left), mergeSort(right));
    }
```

## Merge function will receive two small arrays, will create new full array and return

```java
	private int[] merge(int[] left, int[] right){
		int[] result = new int[left.length + right.length];
        //...
    }
```

