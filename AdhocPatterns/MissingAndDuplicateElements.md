
## Variation 1: n elements, n-1 sized array, 1 element missing

### Sum technique

Missing element = `Sum(1..n)` - `sum(array)`

### XOR technique (cancels similar elements out)

XOR(1..n) xor XOR(array) = missing element

## Variation 2: n elements, n+1 sized array, 1 element duplicated once

### Sum technique

Duplicate element = `Sum(array)` - `sum(1..n)`

### XOR technique (cancels similar element out)

XOR(1..n) xor XOR(array) = duplicate element 

## HARD Variation 3: n elements, 1 element duplicated many times

https://leetcode.com/problems/find-the-duplicate-number/
https://leetcode.com/problems/find-the-duplicate-number/solution/


## Variation 3: n elements, n sized array, but 1 element duplicate, so 1 element missing

`n` elements, i.e. `0..(n-1)` are in an array sized `n`,
Ideally each element can appear once, but 
we have exactly one duplicate element `t` which appears twice in array,
and exactly one missing element `m`.

Problem: Find `t` and `m` in linear time, constant space.

Check EPI for details

1. XOR everything we know: `X = XOR(array) xor XOR(0..(n-1))`, this is equal to `X = m xor t`.
2. every `kth` set bit in `X` represents the bit position in which m & t differ.
3. `A = XOR(el in 0..(n-1), such that kth bit of el is 1)`
4. `B = XOR(el in arr, such that kth bit of el is 1)`
5. `h = A XOR B`, h will either be m or t
6. A pass through the arr will tell if `h` is `m` or `t`

An example
`arr = [5,3,0,3,1,2]` here `n = 6`, `t = 3`, `m = 4`.

1. XOR everything we know: `X = XOR(arr) xor XOR(0..5) = 111`
2. `111` means m and t differ in all bit positions
3. pick any bit position e.g. we pick last bit position
4. `A = XOR(1, 3, 5) = `
5. `B = XOR(5,3,3,1) = `
6. `h = A XOR B = 3 (remaining stuff cancels each other out)`
7. pass through array tells us that 3 is repeating el,i.e. `t` = 3.
8. `m = h XOR X`, `m = 3 XOR 7 = 011 XOR 111 = 100 = 4`.

## Code

```java
  public static DuplicateAndMissing findDuplicateMissing(List<Integer> A) {
    int t, m;
    int h = 0;
    int X = 0;
    for(int i=0;i<A.size();i++) {
      X = X ^ A.get(i);
    }
    for(int i=0; i<A.size();i++) {
      X = X ^ i;
    }

//    System.out.println(Integer.toBinaryString(X));

    int lastSetBitInt = Integer.lowestOneBit(X);// only keep last last set bit, rest is cleared
    for(int i=0;i<A.size();i++) {
      if((i & lastSetBitInt) != 0) {
        h = h ^ i;
      }
    }

    for(int i=0;i<A.size();i++) {
      if((A.get(i) & lastSetBitInt) != 0) {
        h = h ^ A.get(i);
      }
    }

    int hcount = 0;
    for(int i=0;i<A.size();i++) {
      if(A.get(i) == h) {
        hcount++;
      }
    }

    if(hcount == 0) {
      m = h;
      t = X ^ h;
    } else {
      t = h;
      m = X ^ h;
    }
    // find A
    // find B
    return new DuplicateAndMissing(t, m);
  }

```