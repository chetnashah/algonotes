
## 

https://www.educative.io/courses/grokking-the-coding-interview/3Yj2BmpyEy4

We are interested in knowing the smallest element in one part and the biggest element in the other part.

## Variant: Median of number stream

Use two heaps:
1. min heap for smallest element
2. max heap for largest element

### Median definition

when the input size is odd, we take the middle element of sorted data. 

If the input size is even, we pick the average of the middle two elements in the sorted stream.
   
### API

`insertNum(int num)`: inserts number
`findMedian(): int`: returns median for all the numbers till now.

e.g.
```
1. insertNum(3)
2. insertNum(1)
3. findMedian() -> output: 2
4. insertNum(5)
5. findMedian() -> output: 3
6. insertNum(4)
7. findMedian() -> output: 3.5
```

### Core idea

Use two heaps:
1. min heap for smallest element - smallest among all the large elements (i.e. second half of all the numbers seen in sorted order)
2. max heap for largest element - largest among all the smaller elements (i.e. first half of all the numbers seen in sorted order)

**Note** **we must reorder elements in order to keep the two heap sizes equal (max difference 1)** so that the peaks in the two heaps shall represent the middle two elements according to sorted order.

