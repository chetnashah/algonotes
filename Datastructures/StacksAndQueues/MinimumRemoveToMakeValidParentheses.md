
## Idea

Check the array from left to right, remove characters that do not meet the property mentioned above, same idea in backward way.

## Code

```java
import java.util.*;
class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Character> st = new Stack<>();
        StringBuilder sb = new StringBuilder();
        // traverse left to right only keeping valid ones, 
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c == ')') {
                if(!st.isEmpty() && st.peek() == '(') {
                    st.pop();
                    sb.append(')');
                }
            } else if (c == '(') {
                st.push(c);
                sb.append(c);
            } else {
                sb.append(c);
            }
        }
        
        String intermediate = sb.toString();
        Stack<Character> finalSb = new Stack<>();
        st.clear();
        
        // now we traverse from right to left
        for(int i=intermediate.length() - 1;i>=0;i--) {
            char c = intermediate.charAt(i);
            if(c == '(') {
                if(!st.isEmpty() && st.peek() == ')'){
                    st.pop();
                    finalSb.push('(');
                }
            } else if ( c == ')') {
                st.push(c);
                finalSb.push(c);
            } else {
                finalSb.push(c);
            }
        }
        
        StringBuilder finalAns= new StringBuilder();
        
        while(!finalSb.isEmpty()) {
            Character c = finalSb.pop();
            finalAns.append(c);
        }
        
        return finalAns.toString();
    }
}
```