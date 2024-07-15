


#include <algorithm>
#include <iostream>
#include <vector>
int main(){

    int C=0, N=0;
    
    std::cin>>C>>N;

    std::vector<int> weight(N, 0);
    std::vector<int> value(N, 0);
    std::vector<int> nums(N, 0);

    for(int i=0; i<N;++i) {
        std::cin>>weight[i];
    }
    for(int i=0; i<N;++i) {
        std::cin>>value[i];
    }
    for(int i=0; i<N;++i) {
        std::cin>>nums[i];
    }

    std::vector<int> dp(C+1, 0);

    for(int i=0; i<N; ++i) {
        for(int j=C; j>=weight[i]; --j) {
            for(int k=1; k<=nums[i] && (j-k*weight[i])>=0; ++k) {
                dp[j] = std::max(dp[j], dp[j-k*weight[i]]+k*value[i]);
            }
        }
    }
    std::cout<<dp[C];
    return 0;
}