#include <iostream>
#include <list>
#include <vector>

void removeNode(std::vector<std::list<int>>& graph, int index)
{
    // 删除graph[index]
    // graph.erase(graph.begin()+index);
    for(auto& list: graph)
    {
        list.remove(index);
    }
}
int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<std::list<int>> graph(N);   // 使用邻接表存储
    int S=-1, T=-1;
    for(int i=0; i<M; i++)
    {
        std::cin>>S>>T;
        graph[S].emplace_back(T);
    }

    std::vector<bool> visited(N, false);
    std::vector<int> res;
    
    // 寻找叶节点：后继节点为空
    for(int k=0; k<N; k++)
    {
        for(int i=0; i<graph.size(); i++)
        {
            if(!visited[i] && graph[i].empty()) // 没有访问过且为叶子节点
            {
                // std::cout << "i=" << i <<std::endl;
                res.emplace_back(i);
                removeNode(graph, i);
                visited[i]=true;
                break;
            }
        }
    }
    
    
    for(int i=0; i<N; i++)
    {
        if(!visited[i])
        {
            std::cout<<-1;
            return 0;
        }    
    }

    for(int i=N-1; i>0; i--)
        std::cout<<res[i]<<" ";

    std::cout << res[0];

    return 0;
}