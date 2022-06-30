

##

https://leetcode.com/problems/uncrossed-lines/

## Same as LCS

## code

```java
class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        // same as LCS
        int[][] dp = new int[nums1.length][nums2.length];
        // dp[i][j] = lcs for text1 ending in ith char and text2 ending in jth char
        dp[0][0] = nums1[0] == nums2[0] ? 1 : 0;
        for(int i=1;i<nums1.length;i++) {// filling first col
            dp[i][0] = Math.max(dp[i-1][0], nums2[0] == nums1[i] ? 1 : 0);
        }
        for(int i=1;i<nums2.length;i++) { // fillig first row
            dp[0][i] = Math.max(dp[0][i-1], nums1[0] == nums2[i] ? 1 : 0);
        }
        for(int i=1;i<nums1.length;i++) {
            for(int j=1;j<nums2.length;j++) {
                dp[i][j] = Collections.max(Arrays.asList(dp[i-1][j], dp[i][j-1], ((nums1[i] == nums2[j] ? 1 : 0) + dp[i-1][j-1])));
            }
        }

        // print dp state
        // for(int i=0;i<text1.length();i++) {
        //     for(int j=0;j<text2.length();j++) {
        //         System.out.print(dp[i][j]);
        //     }
        //     System.out.println();
        // }
        return dp[nums1.length - 1][nums2.length - 1];

    }
}
```