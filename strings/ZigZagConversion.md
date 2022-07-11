
##


## Code

```java
class Solution {
    public String convert(String s, int numRows) {
        if(s.length() == 1 || numRows == 1) {
            return s;
        }
        
        // many chars
        // simply collect by simulation
        List<StringBuilder> ansRows = new ArrayList<>();
        for(int i=0;i<numRows;i++) {
            ansRows.add(new StringBuilder());
        }
        int dir = 1; // 1 is up to down, -1 is down to up
        int n = 0;// start row is -1, coz we first advance in current dir, and then add to row
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            
            // current row is correct, add the current row
            StringBuilder row = ansRows.get(n);
            row.append(c);
            
            // we added, change direction if we have to
            if(n == numRows-1) {
                dir = -1;// go up
            } else if (n == 0) {
                dir = 1;// go down
            }
            
            // direction is correct, update row where we should add
            if(dir == 1) {
                n++;
            } else {
                n--;
            }

        }
        
        String ans="";
        for(StringBuilder sb: ansRows) {
            ans += sb.toString();
        }
        return ans;
        
    }
}
```