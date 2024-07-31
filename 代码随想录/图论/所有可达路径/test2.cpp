#include <vector>
#include <iostream>
#include <list>

void dfs(int x, const std::vector<std::list<int>>& graph, int N, std::vector<std::vector<int>>& res, std::vector<int>& path);

int main()
{

        
    // 输入
    int N=0, M=0;
    std::cin>>N>>M;
    // N和M被赋值后再创建存储图的邻接矩阵
    std::vector<std::list<int>>graph(N+1);

    int s=0, t=0;
    for(int i=0; i<M;i++)
    {
        std::cin>>s>>t;
        graph[s].push_back(t);
    }    

    std::vector<int> path;
    path.push_back(1);  // 从节点1开始
    std::vector<std::vector<int>> res;
    dfs(1, graph, N, res, path);

    if(res.empty())
    {
        std::cout<<-1<<std::endl;
    }
    // 输出
    for(const auto& vec: res)
    {
        for(int i=0; i<vec.size()-1; i++)
        {
            std::cout<<vec[i]<<" ";
        }
        std::cout<<vec[vec.size()-1]<<std::endl;
        
    }
    return 0;
}

void dfs(int x, const std::vector<std::list<int>>& graph, int N, std::vector<std::vector<int>>& res, std::vector<int>& path)
{
    if(x==N)
    {
        res.push_back(path);
        return;
    }

    for(int i: graph[x])
    {
        path.push_back(i);
        dfs(i, graph, N, res, path);
        path.pop_back();
    }
}