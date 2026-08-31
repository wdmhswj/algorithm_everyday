#include "../../../utils/utils.h"

class Solution {
public:
    std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
            std::stack<std::pair<int, int>> st; // {idx, 开始运行的时间}
            std::vector<int> res(n, 0);
            for (auto& log : logs) {
                char type[10];
                int idx, timestamp;
                std::sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
                if (type[0] == 's') {
                    if (!st.empty()) {
                        res[st.top().first] += timestamp - st.top().second; // 先暂停，计算当前运行的时间
                        // st.top().second = timestamp;
                    }
                    st.emplace(idx, timestamp);
                } else {
                    auto t = st.top();
                    st.pop();
                    res[t.first] += timestamp - t.second + 1; // +1
                    if (!st.empty()) {
                        st.top().second = timestamp + 1; // 暂停 -> 运行
                    }
                }
            }
            return res;
    }
};