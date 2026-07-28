#include "../../utils/utils.h"

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        // 入度
        std::vector<int> inDegree(numCourses, 0);
        // next courses
        std::vector<std::vector<int>> nextCourses(numCourses);

        for (auto& p: prerequisites) {
            ++inDegree[p[0]];
            nextCourses[p[1]].push_back(p[0]);
        }

        std::queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        std::vector<int> res;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int next: nextCourses[cur]) {
                --inDegree[next];
                if (inDegree[next] == 0) q.push(next);
            }
            res.push_back(cur);
        }

        return res.size()==numCourses ? res : std::vector<int>();
    }
};