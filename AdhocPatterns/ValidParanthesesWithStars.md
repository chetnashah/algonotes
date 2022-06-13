
##

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


##

https://leetcode.com/problems/valid-parenthesis-string/

## Idea

### First go from left to right

### count stars as you go, if you encounter a extra closing brace, try to see if you have seen some stars that you can use

### at the end you can satisfy the answer if number of stars remaining are greater than or equal to open positive depths

### Similar repeat the process from right to left

##

```java
class Solution {
    public boolean checkValidString(String s) {
        int d = 0;
        int starCnt = 0;
        boolean satisfiesLeftToRight = false;
        boolean satisfiesRightToLeft = false;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == ')') {
                d -= 1;
                if(d< 0) { // closing seen before an opening brace
                    if(starCnt <= 0) { // no stars seen before that can be used
                        return false;
                    }
                    starCnt--;
                    d = d+1;
                }
            } else if(s.charAt(i) == '(') {
                d += 1;
            } else {
                starCnt++;
            }
        }
        
        // System.out.println("ltor d = " +d + "starCnt = "+starCnt);
        if(d == 0 && starCnt >= 0 || starCnt >= d) {
            satisfiesLeftToRight = true;
        }
        
        // right to left
        starCnt = 0;
        d = 0;
        for(int i=s.length() - 1;i>=0;i--) {
            if(s.charAt(i) == ')') {
                d += 1;
            } else if(s.charAt(i) == '(') {
                d -= 1;
                if(d< 0) { // closing seen before an opening brace
                    if(starCnt <= 0) { // no stars seen before that can be used
                        return false;
                    }
                    starCnt--;
                    d = d+1;
                }
            } else {
                starCnt++;
            }
        }
        
        // System.out.println("rtol d = " +d + "starCnt = "+starCnt);

        if(d == 0 && starCnt >= 0 || starCnt >= d) {
            satisfiesRightToLeft = true;
        }

        return satisfiesLeftToRight && satisfiesRightToLeft;
    }
}
```

## Test cases

"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
"()"
"(*)"
"(*))"
"((*)"