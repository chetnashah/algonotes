#include<cstdio>
#include<algorithm>
#include<vector>

int N, W;
long long dp[100001];// W+1, W is possible weights
// https://atcoder.jp/contests/dp/submissions/31398095 - ACCEPTED
long long solveDP(std::vector<std::pair<int, int>>& items){
    for(auto item: items) {
        for(long long j = item.first; j <= W;j++) {
            dp[j] = std::max(dp[j], dp[j-item.first] + item.second);
        }
    }
    return dp[W];
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