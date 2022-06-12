
##

https://codeforces.com/contest/612/problem/C

##

For example the string `[[(){}]<>]` is RBS, but the strings `[)()` and `][()()` are not.

Determine the least number of replaces to make the string s RBS.

##

Whenever you encounter a wrong matching bracket increment with 1 (so it counts as replace), pop it, and continue.

## Accepted code

```java
import java.util.*;
public class Solution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int ans = 0;
        
        Map<Character,Character> opp = new HashMap<>();
        opp.put('(', ')');
        opp.put('<', '>');
        opp.put('[', ']');
        opp.put('{', '}');
        
        Stack<Character> st = new Stack<>();
        Boolean isPossible = true;
        for(int i=0;i<s.length();i++){
            Character c = s.charAt(i);
            if(c == '[' || c=='(' || c == '<' || c == '{') {
                st.push(c);
            } else {// closing brace found
                if(st.isEmpty()) {
                    isPossible = false;
                    break;
                } else {
                    Character peeked = st.peek();
                    if(opp.get(peeked) == c) {
                        // do nothing
                    } else {
                        ans++;
                    }
                    st.pop();
                }
            }
        }
        
        if(!isPossible || !st.isEmpty()) {
            System.out.println("Impossible");
        } else {
            System.out.println(ans);
        }
    }
}
```


