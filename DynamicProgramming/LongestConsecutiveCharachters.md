
## dp on strings ending in idx i on 1st string and idx j on 2nd string

## For each last char seen in two strings, try to extend consecutive if same char, else reset


For `t = "abcb"` and `s = "kbc"`;

|   |   | `k` | `b` | `c` |
| --- | --- | --- | --- | --- |
|   |   | 0 | 0 | 0 |
| `a` | 0 | 0 | 0 | 0 |
| `b` | 0 | 0 | 1 | 0 |
| `c` | 0 | 0 | 0 | 2 |
| `b` | 0 | 0 | 1 | 0 |

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        String t = "abcb";
        String s = "kbc";
        int[][] consecutive = new int[t.length()+1][s.length()+1];// first row and first column is all 0
        
        for(int i = 1; i <= t.length(); ++i){
            for(int j = 1; j <= s.length(); ++j){
                if(s.charAt(j-1) == t.charAt(i-1)){
                    consecutive[i][j] = 1 + consecutive[i-1][j-1];// chars match, add to previous match count
                } else {
                    consecutive[i][j] = 0;
                }
            }
        }
        
        // print state
        // for(int i = 1; i<=t.length();i++) {
        //     for(int j = 1; j<= s.length();j++) {
        //         System.out.print(consecutive[i][j]);
        //     }
        //     System.out.println();
        // }

    }
}
```