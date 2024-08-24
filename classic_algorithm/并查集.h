#include <vector>

struct DSU{
    std::vector<int> father;
    DSU(int n): father(n) {
        for(int i=0; i<n; i++)
            father[i]=i;
    }

    // 寻找根节点
    int find(int u)
    {
        return u == father[u] ? u : father[u]=find(father[u]);
    }

    // 判断是否属于同一集合
    bool isSameRoot(int u, int v)
    {
        return find(u) == find(v);
    }

    // 右边节点加入左边节点的集合中
    void join(int u, int v)
    {
        int r_u = find(u);
        int r_v = find(v);
        if(r_u==r_v) return;
        else father[r_v] = r_u;
    }
};
