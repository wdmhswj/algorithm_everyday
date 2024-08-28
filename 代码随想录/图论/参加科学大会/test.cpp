#include <climits>
#include <iostream>
#include <vector>



int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<std::vector<int>> graph(N+1, std::vector<int>(N+1, INT_MAX));
    int p1, p2, val;
    for(int i=0; i<M; i++)
    {
        std::cin>>p1>>p2>>val;
        graph[p1][p2] = val;
    }

    std::vector<int> minDist(N+1, INT_MAX);   // 已访问节点中的最短距离
    std::vector<bool> visited(N+1, false);

    int start = 1, end = N;

    minDist[start] = 0; // 源点到自身的距离为0

    for(int i=1; i<=N; i++)
    {
        int minVal = INT_MAX;   // 源点到未访问节点的最短距离
        int cur = 1;

        for(int j=1; j<=N; ++j)
        {
            if(!visited[j] && minDist[j]<minVal)
            {
                minVal = minDist[j];
                cur = j;
            }
        }

        visited[cur] = true;

        for(int j=1; j<=N; ++j)
        {
            if(!visited[j] && graph[cur][j]!=INT_MAX && minDist[cur]+graph[cur][j]<minDist[j])
            {
                minDist[j] = minDist[cur] + graph[cur][j];
            }
        }
    }

    if(minDist[end] == INT_MAX) 
        std::cout << -1;
    else std::cout<<minDist[end];

    return 0;
}