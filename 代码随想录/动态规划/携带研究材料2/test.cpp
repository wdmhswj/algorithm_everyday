#include <algorithm>
#include <vector>
#include <iostream>


void getInput(int& N, int& V, std::vector<int>& weight, std::vector<int>& value) {
    std::cin>>N>>V;
    weight.resize(N);
    value.resize(N);
    for (int i=0; i<N; ++i) {
        std::cin>>weight[i]>>value[i];
    }
}


int solution(const int& N, const int& V, const std::vector<int>& weight, const std::vector<int>& value){
    // dp数组
    std::vector<int> dp(V+1, 0);
    // 遍历
    for(int i=0; i<N; ++i) {
        for(int j=weight[i]; j<=V; ++j) {
            dp[j]=std::max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    return dp[V];
}

int solution1(const int& N, const int& V, const std::vector<int>& weight, const std::vector<int>& value){
    // dp数组
    std::vector<int> dp(V+1, 0);
    // 遍历
    for(int i=0; i<=V; ++i) {   // 背包容量
        for(int j=0; j<N; ++j) {    // 物品
            if (i>=weight[j]) {
                dp[i]=std::max(dp[i], dp[i-weight[j]]+value[j]);
            }
        }
    }
    return dp[V];
}
int main() {

    int N=0, V=0;
    std::vector<int> weight, value;
    getInput(N, V, weight, value);
    std::cout<<solution(N, V, weight, value);

    return 0;
}