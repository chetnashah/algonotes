
## Stack approach

Push when see "(" and pop when see ")"

Anytime you reach a case where you are trying to pop from an empty stack, you have reached invalid parentheses

## Counter approach

Keep counter.
When see "(" increment by 1.
When see ")" decrement by 1.
If ever see counter go to -1.
we have seen a closing brace, which cannot be filled by any opening brace coming after it.

## Variant: Parentheses of many types

e.g. check if `[(])` is valid? It is not.

Here  counter approach is not enough, stack can be used against verifying only popping what was last pushed.

