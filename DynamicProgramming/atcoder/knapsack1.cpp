#include<cstdio>
#include<algorithm>
#include<vector>

int N, W;
long long dp[101][100001];// limits are N+1 x W+1, where N is no of items, W is possible weights

// recursive knapsack
long long solveDP(int itemId, int remW, std::vector<std::pair<int, int>>& items){
    // printf("itemId = %d remW = %d\n", itemId, remW);
    // base case
    if(itemId == N || remW <= 0) {
        return 0ll;
    }

    // 
    if(dp[itemId][remW] != -1ll) {
        // printf("found in memo: %d %d\n", itemId, remW);
        return dp[itemId][remW];
    }

    // case where cannot fit
    if(items[itemId].first > remW) {
        long long ans = solveDP(itemId+1, remW, items);
        dp[itemId][remW] = ans;
        return ans;
    }
    // case where we pick and don't pick
    long long ans = std::max(
        // not picked
        solveDP(itemId+1, remW, items),
        // picked
        items[itemId].second + solveDP(itemId+1, remW - items[itemId].first, items)
    );
    dp[itemId][remW] = ans;
    // printf("Final return ans = %lld for itemId = %d, remW = %d\n", ans, itemId, remW);
    return ans;
}

int main(){
    scanf("%d %d", &N, &W);
    std::vector<std::pair<int,int>> items;
    memset(dp, -1ll, sizeof dp);
    for(int i=0;i < N; i++) {// items are indexed from 0 to 99
        int wi, vi;
        scanf("%d %d", &wi, &vi);
        items.push_back({ wi, vi});
    }
    printf("%lld", solveDP(0, W, items));
    return 0;
}