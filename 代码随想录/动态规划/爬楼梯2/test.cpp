#include <iostream>
#include <vector>
int main(){

    int n=0, m=0;
    std::cin>>n>>m;

    std::vector<int> dp(n+1, 0);
    dp[0]=1;

    for(int j=0; j<=n; ++j) {
        for(int i=1; i<=m; ++i) {
            if (j>=i) {
                dp[j] += dp[j-i];
            }
        }
    }
    
    std::cout<<dp[n];
    return 0;
}