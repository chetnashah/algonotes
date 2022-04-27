#include<cstdio>
#include<algorithm>
#include<vector>

int N, W;
// N * W table
// 1-indexed tabulation, items will be considered from 1 to N
// Weights will be considered from 0 to W, so total W+1 needed.
long long dp[101][100001];// limits are N+1 x W+1, where N is no of items, W is possible weights

// tabulated knapsack
long long solveDP(std::vector<std::pair<int, int>>& items){
    // base case 1 - N items allowed to pick,but 0 weight constraint
    for(int i=0;i<N;i++) {
        dp[i][0] = 0;// 0 because there is no weight is allowed and each item weighs something positive
    }

    // base case 2 - 0 items allowed to pick, all possible weights
    for(int j=0;j<=W;j++) {
        dp[0][j] = 0;
    }
    
    // dp is 1-indexed, items is 0-indexed
    for(int i=1;i<=N;i++) {// outer loop on items
        for(int j=1;j<=W;j++) {// inner loop on weights
            // we are now considering item i for upto J weight
            if(items[i-1].first > j) {// weight of item under consideration is larger than capacity, cannot be picked
                dp[i][j] = dp[i-1][j];// not picking ith item, get from upper row
            } else {
                dp[i][j] = std::max(
                    dp[i-1][j],// not picking i'th item, get from upper row
                    items[i-1].second + dp[i-1][j-items[i-1].first]// picking ith item, remaining weight was filled with earlier items
                );
            }
        }
    }

    return dp[N][W];
}

int main(){
    scanf("%d %d", &N, &W);
    std::vector<std::pair<int,int>> items;// items is 0-indexed collection of items.
    memset(dp, 0ll, sizeof dp);// in tabulation init all with 0
    for(int i=0;i < N; i++) {// items are indexed from 0 to 99
        int wi, vi;
        scanf("%d %d", &wi, &vi);
        items.push_back({ wi, vi});
    }
    printf("%lld\n", solveDP(items));
    return 0;
}