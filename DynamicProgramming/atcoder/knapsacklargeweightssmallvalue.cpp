#include<vector>
#include<cstdio>
int N, W;

// https://atcoder.jp/contests/dp/tasks/dp_e
// knapsack variant - Weights are large, values are limited
int dp[100*1000 + 1]; // all possible values, 100 items, each item can give a value of 1000
// dp[i] = min possible weight, if i is the totalvalue

int solveDP(std::vector<std::pair<int, int>> &items) {
    dp[0] = 0;
    for(auto item: items) {
        for(int j = 100000 - item.second; j >= 0 ; j--) {
            dp[j+item.second] = std::min(dp[j] + item.first, dp[j+item.second]);
        }
    }

    int i = 0, ans = 0;
    for(;i<100001;i++){
        if(dp[i] <= W) {
            ans = i;
        }
    }
    return ans;
}

int main(){
    scanf("%d %d", &N, &W);
    std::vector<std::pair<int,int>> items;// items is 0-indexed collection of items.

    int INF = 1e9+1;
    for(int i=0;i<100001;i++){    // initially fill all of dp arr with INF
        dp[i] = INF;
    }
    for(int i=0;i < N; i++) {// items are indexed from 0 to 99
        int wi, vi;
        scanf("%d %d", &wi, &vi);
        items.push_back({ wi, vi});
    }
    printf("%d\n", solveDP(items));
    return 0;
}