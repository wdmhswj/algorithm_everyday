#include <iostream>
#include <vector>

class Prim
{
    void test()
    {
        int V=0, E=0;
        std::cin>>V>>E;
        std::vector<std::vector<int>> graph(V+1, std::vector<int>(V+1, 10001)); // 初始化为10001，可以简化之后的minDist的更新
        int v1=0, v2=0, val=0;
        for(int i=0; i<E; i++)
        {
            std::cin>>v1>>v2>>val;
            graph[v1][v2]=val;
            graph[v2][v1]=val;
        }


        std::vector<int> minDist(V+1, 10001);   // 初始化为取不到的最大值，使得第一次循环时可以选择第一个节点
        std::vector<bool> visited(V+1, false);
        std::vector<int> parent(V+1, -1);   // 记录生成树
        // 循环 n-1 次，建立 n-1 条边
        for(int i=1; i<V; i++)
        {
            // 寻找距离生成树最近的节点
            int cur = -1;
            int minVal = INT_MAX;   // 最小值初始化为INT_MAX，使得至少更新1次
            for(int i=1; i<=V; i++)
            {
                if(!visited[i] && minDist[i]<minVal)
                {
                    cur=i;
                    minVal=minDist[i];
                }
            }

            // 加入生成树
            visited[cur]=true;

            // 更新 midDist
            for(int i=1; i<=V; i++)
            {
                if(!visited[i] && graph[i][cur]<minDist[i])
                {
                    minDist[i] = graph[i][cur];
                    parent[i] = cur;    // 更新生成树外的节点最终通过哪条边加入生成树
                }
            }
        }

        int res = 0;
        for(int i=2; i<=V; i++)
        {
            res += minDist[i];
        }
        std::cout<<res<<std::endl;;

        // 输出路径
        for(int i=1; i<=V; i++)
        {
            std::cout<<i<<"->"<<parent[i]<<std::endl;
        }
    }
};