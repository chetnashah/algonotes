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
