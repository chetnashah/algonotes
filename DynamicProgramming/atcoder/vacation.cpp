#include<cstdio>
#include<iostream>
#include<vector>
// https://atcoder.jp/contests/dp/tasks/dp_c
int main(){
    int N;
    scanf("%d", &N);
    std::vector<std::vector<int>> happiness;
    std::vector<std::vector<int>> ans;

    for(int i = 0; i < N; i++ ){
        int ai, bi, ci;
        scanf("%d", &ai);
        scanf("%d", &bi);
        scanf("%d", &ci);
        happiness.push_back({ai, bi, ci});
    }

    ans.push_back({happiness[0][0],happiness[0][1], happiness[0][2]});
    for(int i=1;i<N;i++) {
        ans.push_back({0 ,0, 0});
        ans[i][0] = happiness[i][0] + std::max(ans[i-1][1], ans[i-1][2]);
        ans[i][1] = happiness[i][1] + std::max(ans[i-1][0], ans[i-1][2]);
        ans[i][2] = happiness[i][2] + std::max(ans[i-1][0], ans[i-1][1]);
    }

    int max = 0;
    for(auto a : ans[N-1]){
        if(a > max) {
            max = a;
        }
    }
    std::cout << max << std::endl;
    return 0;
}