#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>


struct Edge {
    int to; // 邻接顶点
    int val;    // 边的权重

    Edge(int t, int w): to(t), val(w) {}    // 构造函数
};

// 小顶堆
class mycomparison {
public:
    bool operator()(const std::pair<int, int>& e1, const std::pair<int, int>& e2)
    {
        return e1.second>e2.second;
    }
};

int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<std::list<Edge>> graph(N+1);
    int p1, p2, val;
    for(int i=0; i<M; i++)
    {
        std::cin>>p1>>p2>>val;
        graph[p1].push_back(Edge(p2, val));
    }

    std::vector<int> minDist(N+1, INT_MAX);   // 已访问节点中的最短距离
    std::vector<bool> visited(N+1, false);

    int start = 1, end = N; // 起点和终点

    minDist[start] = 0; // 源点到自身的距离为0

    auto cmp = [](std::pair<int, int>& l, std::pair<int, int>& r) {
        return l.second>r.second;
    };

    // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, mycomparison> pq;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.push(std::pair<int, int>(start, 0));

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(visited[cur.first]) continue;

        visited[cur.first] = true;

        // 更新最小距离
        for(Edge edge: graph[cur.first])
        {
            if(!visited[edge.to] && minDist[cur.first]+edge.val<minDist[edge.to])
            {
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(std::pair<int , int>(edge.to, minDist[edge.to]));
            }
        }
    }
    
    if(minDist[end] == INT_MAX) 
        std::cout << -1;
    else std::cout<<minDist[end];

    return 0;
}