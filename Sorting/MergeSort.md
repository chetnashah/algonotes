
## Classic sorting algorithm


## Needs O(n) extra space

## MergeSort function takes an array to sort, and returns new array 

```java
	private int[] mergeSort(int[] input){
        //...
    }
```

### In MergeSort function, create two new subarrays and pass them to merge fn

Basecase sits here in mergeSort function.

```java
	private int[] mergeSort(int[] input){
        if(input.length == 1) {
            return input;
        }
        int[] left = new input[0..(mid-1)];// first half of input
        int[] right = new input[mid..(input.length-1)];... // second half of input
        // recursively sort subarrays before merging
        return merge(mergeSort(left), mergeSort(right));
    }
```

## Merge function will receive two small arrays, will create new full array and return

Merge function returns a new sorted array which is a sorted version of combination of two sorted input arrays.
```java
    private int[] merge(int[] left, int[] right){
		int[] result = new int[left.length + right.length];
        //...
    }
```

## Full code

```java
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        
        int[] arr = new int[] {4,2,5,1,3,0};
        int[] ans = mergeSort(arr);
        System.out.println(Arrays.toString(ans));
        
    }
    
    static private int[] mergeSort(int[] input) {
        if(input.length == 1) {
            return input;
        }
        
        int[] left;
        int[] right;
        int mid = input.length/2;
        left = new int[mid];
        right = new int[input.length - mid];
        
        for(int i=0;i<mid;i++) {
            left[i] = input[i];
        }
        int cnt=0;
        for(int i=mid; i<input.length;i++) {
            right[cnt++] = input[i];
        }
        // recursively sort sub arrays before merging
        return merge(mergeSort(left), mergeSort(right));
    }
    
    static private int[] merge(int[] left, int[] right){
		int[] result = new int[left.length + right.length];
		int leftIndex = 0;
		int rightIndex = 0;
		int resultIndex = 0;
		
		while(leftIndex < left.length || rightIndex < right.length){
			if(leftIndex < left.length && rightIndex < right.length){
				if(left[leftIndex] < right[rightIndex]){
					result[resultIndex] = left[leftIndex];
					leftIndex++;
					resultIndex++;
				}
				else{
					result[resultIndex] = right[rightIndex];
					rightIndex++;
					resultIndex++;
				}
			}
			else if(leftIndex < left.length){
				for (int i = resultIndex; i < result.length; i++) {
					result[i] = left[leftIndex];
					leftIndex++;
				}
			}
			else if(rightIndex < right.length){
				for (int i = resultIndex; i < result.length; i++) {
					result[i] = right[rightIndex];
					rightIndex++;
				}
			}
		}
		
		return result;
	}
}
```