#include <algorithm>
#include <iostream>
#include <vector>

#include "./并查集.h"

class Kruskal
{
    struct edge{
        int l, r, val;
    };
    
    void test(){
        int V=0, E=0;
        std::cin>>V>>E;
        std::vector<edge> edges;    // 自定义数据结构用以存储图
        int v1=0, v2=0, val=0;
        for(int i=0; i<E; i++)
        {
            std::cin>>v1>>v2>>val;
            edges.push_back({v1, v2, val});
        }

        // 根据边的权值从小到大排序
        std::sort(edges.begin(), edges.end(), [](const edge& e1, const edge& e2){
            return e1.val<e2.val;
        });

        // 并查集初始化
        DSU dsu(V+1);

        // 生成树中的边
        std::vector<edge> res;
        int res_val=0;
        // 从小到大遍历
        for(const auto& e: edges)
        {
            // 边的两边节点是否属于同一集合
            if(!dsu.isSameRoot(e.l, e.r))
            {
                res.push_back(e);
                res_val+=e.val;
                dsu.join(e.l, e.r);
            }
        }
        
        for(const auto& e: res)
        {
            std::cout << e.l << " - " << e.r << " : " << e.val << std::endl;
        }
        std::cout << res_val << std::endl;

    }
};