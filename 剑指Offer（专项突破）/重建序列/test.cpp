#include "../../utils/utils.h"


class Solution {
public:
    bool sequenceReconstruction(std::vector<int>& nums, std::vector<std::vector<int>>& sequences) {
        const int n = nums.size();
        std::vector<int> inDegree(n+1, 0); // 入度
        std::vector<std::vector<int>> nextNodes(n+1); // 每个节点的邻居节点

        for (auto& sq: sequences) {
            for (int i=0; i+1<sq.size(); ++i) {
                ++inDegree[sq[i+1]];
                nextNodes[sq[i]].push_back(sq[i+1]);
            }
        }

        std::queue<int> q;
        for (int i=1; i<=n; ++i) {
            if (inDegree[i]==0) {
                q.push(i);
            }
        }
        if (q.size() > 1) {
            // std::cout << "False 0" << std::endl;
            return false;
        }

        std::vector<int> topo{};
        while (!q.empty()) {
            if (q.size() > 1) {
                // std::cout << "False 1" << std::endl;
                return false;
            }

            int cur = q.front(); q.pop();
            topo.push_back(cur);
            for (int next: nextNodes[cur]) {
                --inDegree[next];
                if (inDegree[next] == 0)
                    q.push(next);
            }
        }
        if (topo.size() != n) {
            // std::cout << "False 2" << std::endl;
            return false;
        } // 长度最短
        for (int i=0; i<n; ++i) {
            if (topo[i] != nums[i]) {
                // std::cout << "False 3" << std::endl;
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> nums = {1,2,3};
    std::vector<std::vector<int>> sequences = {{1,2},{1,3},{2,3}};
    Solution s;
    // std::cout << s.sequenceReconstruction(nums, sequences) << std::endl;
    return 0;
}