
## Goal

Rearrage array so that result is a uniformly random permutation of the original array

## Approach 1: shuffle sort (assign random numbers to elements and sort)

### Generate random real number (between 0 to 1) for each item in the array, in an auxillary array e.g rnd[i]

### sort the list of random numbers and also rearrange the corresponding original array

### Complexity: O(n) for gen rand numbers + O(n lg n) to sort rand nums

## Approach 2: Knuth shuffle - O(n)

### Run an iteration index i from `n-1` to `1`

Invariant: All elements after `i` index have been shuffled

### Pick random index between 0 & i (inclusive) and swap, decrement i

### Code

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
    
        int[] arr = new int[]{1,2,3,4,5,6,7};
        shuffle(arr);
    }
    
    public static void shuffle(int[] arr) {
        for(int i=arr.length-1;i>0;i--) {
            int randIdx = (int)(Math.random()*(i+1));// get random num between 0 and i inclusive
            swap(arr,i, randIdx);
        }
        System.out.println(Arrays.toString(arr));
    }
    
    public static void swap(int[] arr, int p, int q) {
        int temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
    }
}
```




