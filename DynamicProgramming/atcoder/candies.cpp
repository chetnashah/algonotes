
#include<cstdio>
#include<vector>

int N,K;
void printWays(std::vector<int> &maxCandiesAllowed) {

}
// TODO finish this
int main(){
    scanf("%d %d", &N, &K);
    std::vector<int> maxCandiesAllowed;
    for(int i=0;i<N; i++){
        int j;
        scanf("%d", &j);
        maxCandiesAllowed.push_back(j);
    }
    printWays(maxCandiesAllowed);
    return 0;
}