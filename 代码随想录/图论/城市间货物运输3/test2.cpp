#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <vector>

struct Edge{
    int to;
    int weight;
    Edge(int t, int w): to(t), weight(w) {}
};


const int INF = std::numeric_limits<int>::max();

int main()
{
    int n=0, m=0;
    std::cin>>n>>m;
    std::vector<std::list<Edge>> adjList(n+1);
    int from=0, to=0, weight=0;
    for(int i=0; i<m; ++i)
    {
        std::cin>>from>>to>>weight;
        adjList[from].emplace_back(to, weight);
    }
    int src=0, dst=0, k=0;
    std::cin>>src>>dst>>k;
    k++;

    std::vector<int> dist(n+1, INF);
    std::vector<int> dist_copy;
    
    std::queue<int> que;

    
    que.push(src);
    dist[src]=0;

    while(k-- && !que.empty())
    {
        int size = que.size();
        dist_copy = dist;
        std::vector<bool> visited(n+1, false);
        while (size--) {
            int cur = que.front();
            que.pop();
            visited[cur] = false;   // 出队列，变为未访问
            // 遍历当前节点的邻接节点
            for(const Edge& e: adjList[cur])
            {
                if(dist[e.to] > dist_copy[cur] + e.weight)
                {
                    dist[e.to] = dist_copy[cur] + e.weight;
                    if(!visited[e.to]){
                        que.push(e.to);
                        visited[e.to] = true;
                    }
                        
                }
            }
        }
        
    }
    
    if (dist[dst]==INF) {
        std::cout<<"unreachable";
    } else {
        std::cout<<dist[dst];
    }
    return 0;
}

