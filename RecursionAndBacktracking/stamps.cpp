#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans = 0, astamp[10];
int H, K, use[10];
int dp[200][10] = {};
void dfs(int idx, int last, int lastcan) {
    printf("idx = %d, last = %d, lastcan = %d \n", idx, last, lastcan);
    int can = 0, i, j, k;
    // this loops break either when j has reached number of max stamps that can be used i.e. H, 
    // or dp[i][j] != 0 where j ranges for each step
    for(i = lastcan; ; i++) {
        printf("  i = %d\n", i);
        for(j = 0; j <= H; j++) {
            printf("    j = %d\n", j);
            printf("     dp[%d][%d] = %d\n", i,j, dp[i][j]);
            if(dp[i][j] != 0) {
                printf("     dp[%d][%d] != 0, so break out of j = %d", i, j, j);
                break;
            }
        }
        if(j == H+1) {// we have used all stamps, j = H+1
            can = i-1;
            printf("base case hit: j == H+1 = %d, setting can = i-1 = %d \n", j, can);
            break;
        }
    }
    if(idx == K) {
        if(can >= ans) {// ans return
            ans = can;
            printf("base case 2: idx == K = %d, ans = %d\n", K, ans);
            for(i = 0; i < K; i++)
                astamp[i] = use[i];
        }
        return;
    }
    int step[10000][2], re;
    for(i = last+1; i <= can+1; i++) {
        printf("i2 = %d , j2 will start from 0 to 100\n", i);
        re = 0;
        for(j = 0; j <= 100; j++) {
            printf("  j2 = %d  k2 will start from 0 to H-1 \n\n", j);
            for(k = 0; k < H; k++) {
                printf("    k2 = %d\n", k);
                if(dp[j+i][k+1] == 0 && dp[j][k] != 0) {
                    step[re][0] = j+i;
                    step[re][1] = k+1;
                    re++;
                    dp[j+i][k+1] = 1;
                }
            }
        }
        use[idx] = i;
        dfs(idx+1, i, can);
        for(j = 0; j < re; j++)
            dp[step[j][0]][step[j][1]] = 0;
    }
}
int main() {
    while(scanf("%d %d", &H, &K) == 2) {
        if(H == 0 && K == 0)
            break;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        ans = 0;
        dfs(0, 0, 0);
        int i;
        for(i = 0; i < K; i++) {
            printf("%3d", astamp[i]);
        }
        printf(" ->%3d\n", ans);
    }
    return 0;
}