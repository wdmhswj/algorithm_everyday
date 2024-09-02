#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include "../../../utils/printH.h"

struct Edge {
    int u, v, w;
};

const int INF = std::numeric_limits<int>::max();

int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<std::vector<std::vector<int>>> dp(N+1, std::vector<std::vector<int>>(N+1, std::vector<int>(N+1, INF)));
    int u, v, w;
    for(int i=0; i<M; i++)
    {
        std::cin>>u>>v>>w;
        dp[u][v][0] = w;
        dp[v][u][0] = w;
    }

    // printVector3D(dp);

    int Q=0;
    std::cin>>Q;
    std::vector<std::pair<int, int>> schedule(Q);
    for(auto& pair: schedule)
    {
        std::cin>>pair.first>>pair.second;
    }


    for(int k=1; k<=N; ++k)
    {
        for(int i=1; i<=N; ++i)
        {
            for(int j=1; j<=N; ++j)
            {
                int opt = 0;
                if(dp[i][k][k-1]==INF || dp[k][j][k-1]==INF) {
                    opt = INF;
                }else {
                    opt = dp[i][k][k-1] + dp[k][j][k-1];
                }
                dp[i][j][k] = std::min(dp[i][j][k-1], opt);
            }
        }
    }

    // printVector3D(dp);

    int start = 0, end = 0;

    for(const auto& pair: schedule)
    {
        start = pair.first;
        end = pair.second;

        if (dp[start][end][N]==INF) {
            std::cout<<-1<<std::endl;
        }else{
            std::cout<<dp[start][end][N]<<std::endl;
        }
    }
    return 0;
}