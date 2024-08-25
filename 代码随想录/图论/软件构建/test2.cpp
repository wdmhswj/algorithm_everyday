#include <iostream>
#include <list>
#include <vector>
#include <algorithm>


int main()
{
    int N=0, M=0;
    std::cin>>N>>M;
    std::vector<std::list<int>> graph(N);   // 使用邻接表存储
    std::vector<int> outDegree(N, 0);   // 记录出度
    int S=-1, T=-1;
    for(int i=0; i<M; i++)
    {
        std::cin>>S>>T;
        graph[S].emplace_back(T);
        outDegree[S]++;
    }

    std::vector<bool> visited(N, false);
    std::vector<int> res;
    
    // 寻找叶节点：后继节点为空
    for(int k=0; k<N; k++)
    {
        for(int i=0; i<graph.size(); i++)
        {
            if(!visited[i] && outDegree[i]==0) // 没有访问过且为叶子节点
            {
                // std::cout << "i=" << i <<std::endl;
                res.emplace_back(i);
                // 指向i的节点出度减1
                for(int j=0; j<N; j++)
                {
                    if(std::find(graph[j].begin(), graph[j].end(), i)!=graph[j].end())
                    {
                        outDegree[j]--;
                    }
                }

                visited[i]=true;
                break;
            }
        }
    }
    
    

    if(res.size()!=N)
    {
        std::cout<<-1;
        return 0;
    }    


    for(int i=N-1; i>0; i--)
        std::cout<<res[i]<<" ";

    std::cout << res[0];

    return 0;
}