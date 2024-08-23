#include <algorithm>
#include <vector>
#include <queue>

using std::vector;
class Solution {

public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // 构造邻接表
        int n=patience.size();
        vector<vector<int>> adj(n);
        for(auto& v: edges)
        {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        // 计算最短路径
        auto mindst =bfs(adj);

        int max=0;
        for(int i=0; i<mindst.size(); i++)
        {
            max = std::max(max, idleTime(mindst[i], patience[i]));
        }
        return max+1;
    }
private:
    vector<int> bfs(const vector<vector<int>>& adj)
    {
        std::queue<int> que;
        vector<bool> visited(adj.size(), false);
        que.emplace(0);
        visited[0]=true;
        int dist=0;
        vector<int> res(adj.size());
        while(!que.empty())
        {
            int sz=que.size();
            for(int i=0; i<sz; i++)
            {
                int node=que.front();
                que.pop();
                res[node]=dist;
                for(const int& e: adj[node])
                {
                    if(visited[e])  continue;
                    que.push(e);
                    visited[e]=true;
                }
            }
            ++dist;
        }
        return res;
    }

    int idleTime(int minDist, int patience) {

        int num = (2*minDist-1)/patience;   // 多发的消息数目
        return num*patience + 2*minDist;

    }
};