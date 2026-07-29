#include "../../utils/utils.h"


class Solution {
public:
    std::string alienOrder(std::vector<std::string>& words) {
        const int n = words.size();
        if (n == 1) return words[0];

        std::array<bool, 26> hasChar{};
        // 标记所有出现在单词中的字符（不仅是出现在边中的）
        for (const auto& word : words) {
            for (char ch : word) {
                hasChar[ch - 'a'] = true;
            }
        }

        std::vector<std::pair<int, int>> records;
        for (int i=0; i<n-1; ++i) {
            int j=0;
            while (j<words[i].size() && j<words[i+1].size()) {
                if (words[i][j] != words[i+1][j]) {
                    records.push_back({words[i][j]-'a', words[i+1][j]-'a'});
                    // hasChar[words[i][j]-'a'] = true;
                    // hasChar[words[i+1][j]-'a'] = true;
                    break;
                }
                ++j;
            }
            // 若 words[i] 长度 > words[i+1] 且 words[i+1] 是 words[i] 的前缀 → 非法
            if (j == words[i+1].size() && words[i].size() > words[i+1].size()) {
                return "";
            }
        }

    
        const int node_num = std::count(hasChar.begin(), hasChar.end(), true);
        // std::cout << "node_num: " << node_num << std::endl;
        std::array<int, 26> inDegree{};
        std::array<std::vector<int>, 26> nextChars{};

        // std::cout << "records size: " << records.size() << std::endl;
        for (auto& p: records) {
            ++inDegree[p.second]; // 入度+1
            // std::cout << "Edge: " << char('a'+p.first) << " -> " << char('a'+p.second) << std::endl;
            nextChars[p.first].push_back(p.second);
        }

        std::queue<int> q;
        for (int i=0; i<26; ++i) {
            if (hasChar[i] && inDegree[i]==0) q.push(i);
        }

        std::string res;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            res.push_back('a'+cur);
            // std::cout << "Processing character: " << res.back() << std::endl;

            for (int next: nextChars[cur]) {
                --inDegree[next];
                // std::cout << "Decreasing inDegree of " << char('a'+next) << " to " << inDegree[next] << std::endl;
                if (inDegree[next] == 0) {
                    q.push(next);
                    // std::cout << "Pushing character: " << char('a'+next) << " to queue" << std::endl;
                }
            }
        }

        return res.size()==node_num ? res : "";
    }
};


int main() {

    std::vector<std::string> words = {"wrt","wrf","er","ett","rftt"};
    Solution s;
    std::string res = s.alienOrder(words);
    std::cout << res << std::endl;
}