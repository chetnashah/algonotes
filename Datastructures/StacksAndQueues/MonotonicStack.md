Monotonic stack is like a regular stack with one key distinction in the push operation: Before we push a new element onto the stack, we first check if adding it breaks the monotonic condition. If it does, then we pop the top element off the stack until pushing the new element no longer breaks the monotonic condition.

https://algo.monster/problems/mono_stack_intro

https://www.youtube.com/watch?v=dtiBmmIPR0E

## Monotonic increasing stack

normal stack but one extra condition, elements should always be increasing,
if you have to push a smaller element, start popping off elements, till the case where pushing new element still keeps this invariant condition: monotonic increasing stack.

Get nearest previous smaller element with monotonically increasing stack
`1,3,10,7,5,24,4`
Stack:
1
1 | 3
1 | 3 | 10
1 | 3 | 7
1 | 3 | 5
1 | 3 | 5 | 24
1 | 3 | 4

Similarly you can find next nearest smaller element by traversing the array in reverse direction and maintaining a 
monotonically increasing stack
`1,3,10,7,5,24,4`
4                   // no next smaller element for 4
4 | 24              // next smaller element for 24 is 4
4 | 5               // next smaller element for 5
4 | 5 | 7           // next smaller element for 7 is 5
4 | 5 | 7 | 10      // next smaller element for 10 is 7
3                   // no next smaller element for 3
1                   // no next smaller element for 1


## Why and when is it useful?

**You can find nearest previous greater and next greater elements in linear time.**

## Monotonic decreasing stack

Helps you get `previous greater element`: any element that is next to be popped than the currrent one is a previous greater eelemnt, start pushing from start of the array.
e.g.
`1,3,10,7,5,24,4`
Stack:
1             // no previous greater
3             // no previous greater elements
10            // no previous greater elements
10 | 7        // previous greater of 7 is one after 7 to be popped, i.e. 10 
10 | 7 | 5    // 
24
24 | 4

Finding `next greater element` with same technique, but reverse traversal:
**Start pushing from end of the array**
Stack:
4                   // no next greater element than 4
24                  // no next greater element than 24
24 | 5              // next greater element of 5 is 24
24 | 7              // next greater element of 7 is 24
24 | 10             // next greater element of 10 is 24
24 | 10 | 3         // next greater element of 3 is 10
24 | 10 | 3 | 1     // next greater element of 1 is 3

## Variant: next greater with a circular array (you can wrap around to find next greater)

one approach: copy all elements except last and append them to original and find 
next greater for first N elements
        

improvement: instead of copying the array and appending it, use (i % n) as index to get elements
starting from i = (2n-1 % n) down to 0
managing a monotonic decreasing stack

```java
    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 2 * nums.length - 1; i >= 0; --i) {
            while (!stack.empty() && nums[stack.peek()] <= nums[i % nums.length]) {
                stack.pop();
            }
            res[i % nums.length] = stack.empty() ? -1 : nums[stack.peek()];
            stack.push(i % nums.length);
        }
        return res;
    }
```