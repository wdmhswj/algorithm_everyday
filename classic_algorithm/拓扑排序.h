#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

class tpSort
{
    int test()
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

    int test1()
    {
        int m, n, s, t;
        std::cin >> n >> m;
        std::vector<int> inDegree(n, 0); // 记录每个文件的入度

        std::unordered_map<int, std::vector<int>> umap;// 记录文件依赖关系
        std::vector<int> result; // 记录结果

        while (m--) {
            // s->t，先有s才能有t
            std::cin >> s >> t;
            inDegree[t]++; // t的入度加一
            umap[s].push_back(t); // 记录s指向哪些文件
        }
        std::queue<int> que;
        for (int i = 0; i < n; i++) {
            // 入度为0的文件，可以作为开头，先加入队列
            if (inDegree[i] == 0) que.push(i);
            //cout << inDegree[i] << endl;
        }
        // int count = 0;
        while (que.size()) {
            int  cur = que.front(); // 当前选中的文件
            que.pop();
            //count++;
            result.push_back(cur);
            std::vector<int> files = umap[cur]; //获取该文件指向的文件
            if (files.size()) { // cur有后续文件
                for (int i = 0; i < files.size(); i++) {
                    inDegree[files[i]] --; // cur的指向的文件入度-1
                    if(inDegree[files[i]] == 0) que.push(files[i]);
                }
            }
        }
        if (result.size() == n) {
            for (int i = 0; i < n - 1; i++) std::cout << result[i] << " ";
            std::cout << result[n - 1];
        } else std::cout << -1 << std::endl;

    }

};