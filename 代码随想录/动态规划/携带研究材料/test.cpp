#include <algorithm>
#include <vector>
#include <iostream>


void getInput(int& M, int& N, std::vector<int>& weight, std::vector<int>& value) {
    std::cin>>M>>N;
    weight.resize(M);
    value.resize(M);
    for (int i=0; i<M; ++i) {
        std::cin>>weight[i];
    }
    for (int i=0; i<M; ++i) {
        std::cin>>value[i];
    }
}

int solution(const int& M, const int& N, const std::vector<int>& weight, const std::vector<int>& value){
    // dp数组
    std::vector<std::vector<int>> dp(M, std::vector<int>(N+1, 0));
    // 数组初始化
    for(int i=0; i<M; ++i){
        dp[i][0]=0;
    }
    for(int i=0; i<weight[0]; ++i){
        dp[0][i]=0;
    }
    for(int i=weight[0]; i<=N; ++i){
        dp[0][i]=value[0];  // 是价值value[0]而不是1
    }

    // 遍历
    for(int i=1; i<M; ++i) {
        for(int j=1; j<=N; ++j) {
            if (weight[i]>j) {
                dp[i][j] = dp[i-1][j];  // 当前物品重量大于背包剩余容量
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    return dp[M-1][N];
}
int solution1(const int& M, const int& N, const std::vector<int>& weight, const std::vector<int>& value){
    // dp数组
    std::vector<int> dp(N+1, 0);
    // 遍历
    for(int i=0; i<M; ++i) {
        for(int j=N; j>=weight[i]; --j) {
            dp[j]=std::max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    return dp[N];
}
int main() {

    int M=0, N=0;
    std::vector<int> weight, value;
    getInput(M, N, weight, value);
    std::cout<<solution1(M, N, weight, value);

    return 0;
}