#include <iostream>
#include <vector>
#include <list>
#include <queue>


void dfs(const std::vector<std::list<int>>& graph, std::vector<int>& visited, int key)
{
    if(visited[key]==1)
    {
        return;
    }
    visited[key]=1;
    for(int e: graph[key])
    {
        dfs(graph, visited, e);
    }
}

void bfs(const std::vector<std::list<int>>& graph, std::vector<int>& visited, int key)
{
    std::queue<int> que;
    visited[key]=1;
    que.push(key);
    while(!que.empty())
    {
        int key=que.front();
        que.pop();
        for(int e: graph[key])
        {
            if(visited[e]==1)
                continue;
            visited[e]=1;
            que.push(e);
        }
    }
}

int main()
{
    int N=0, K=0;
    std::cin>>N>>K;
    std::vector<std::list<int>> graph(N+1);
    int s=-1, t=-1;
    for(int i=0; i<K; i++)
    {
        std::cin>>s>>t;
        graph[s].push_back(t);
    }

    std::vector<int> visited(N+1, 0);
    // dfs(graph, visited, 1);
    bfs(graph, visited, 1);
    for(int i=1; i<=N; i++)
    {
        if(visited[i]==0)
        {
            std::cout<<-1;
            return 0;
        }
    }
    std::cout<<1;
    return 0;
}