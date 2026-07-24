#include "../../utils/utils.h"


class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        const int n = graph.size();
        std::vector<std::vector<int>> res;

        std::function<void(std::vector<int>&, int)> dfs = [&](std::vector<int>& path, int index) {
            if (path.back() == n-1) {
                res.push_back(path);
                return;
            }
            for (int j: graph[index]) {
                path.push_back(j);
                dfs(path, j);
                path.pop_back();
            }
        };

        std::vector<int> path;
        path.push_back(0);
        dfs(path, 0);
        return res;

    }

};