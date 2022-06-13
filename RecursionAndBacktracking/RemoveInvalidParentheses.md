https://leetcode.com/problems/remove-invalid-parentheses/

## Backtracking approach

### Search pruning

In your backtracking state, if you have an extra closing brace before a opening brace, does not make sense to search more down that configuration.

### Backtracking state


```java
    public void backtrackHelper(String s, int idx, int leftCnt, int rightCnt, StringBuilder expression, int removedCnt) {
    }
```

`String s` - necessary to get values

`idx` - necessary to move recursion forward, and also terminate recursion.

`leftCnt, rightCnt` - number of left and right parens added to expression till now, helpful in search pruning

`expression` - building the answer as we are going forward

`removedCnt` - Even though we have a valid expression, we also need to keep track of the number of removals we did to get this expression, this is because even we are at a valid expression, we must not select valid expressions with high number of removals, only consider expressions with global minima number of removals.