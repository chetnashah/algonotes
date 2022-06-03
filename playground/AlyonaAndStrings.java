
import java.util.*;
public class Main{
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int n,m,k;
         n = sc.nextInt();
         m = sc.nextInt();
         k = sc.nextInt();
         String s = sc.next();
         String t = sc.next();
         
         System.out.println(longestCommonSubsequence(s, t));
    }

    public static int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()][text2.length()];
        // dp[i][j] = lcs for text1 ending in ith char and text2 ending in jth char
        dp[0][0] = text1.charAt(0) == text2.charAt(0) ? 1 : 0;
        for(int i=1;i<text1.length();i++) {// filling first col
            dp[i][0] = Math.max(dp[i-1][0], text2.charAt(0) == text1.charAt(i) ? 1 : 0);
        }
        for(int i=1;i<text2.length();i++) { // fillig first row
            dp[0][i] = Math.max(dp[0][i-1], text1.charAt(0) == text2.charAt(i) ? 1 : 0);
        }
        for(int i=1;i<text1.length();i++) {
            for(int j=1;j<text2.length();j++) {
                dp[i][j] = Collections.max(Arrays.asList(dp[i-1][j], dp[i][j-1], ((text1.charAt(i) == text2.charAt(j) ? 1 : 0) + dp[i-1][j-1])));
            }
        }

        // print dp state
        // for(int i=0;i<text1.length();i++) {
        //     for(int j=0;j<text2.length();j++) {
        //         System.out.print(dp[i][j]);
        //     }
        //     System.out.println();
        // }
        return dp[text1.length() - 1][text2.length() - 1];
    }

 }