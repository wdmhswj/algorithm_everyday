#include "../../utils/utils.h"

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        if (s.size() < 4 || s.size() > 12) return {};
        std::vector<std::string> res;
        std::string path;
        const int n = s.size();

        std::function<void(int, int)> backtrack = [&](int index, int segment) {
            if (segment==4) {
                if (index == n) {
                    res.emplace_back(path.begin(), path.end()-1); // 移除最后一个'.'
                }
                return;
            }

            if (n-index > (4-segment)*3 || n-index < (4-segment)) {
                return; // 剪枝：剩余字符数不够或过多，无法形成有效IP地址
            }

            for (int j=index; j<index+3 && j<n; ++j) {
                // 判断s[index...j]是否是一个有效的IP地址段
                // 1. 不能有前导0，除非该段是单个字符'0'
                if (s[index]=='0' && j>index) {
                    break;
                }
                // 2. 数值必须在0到255之间
                int num = std::stoi(s.substr(index, j-index+1));
                if (num>255) {
                    break;
                }

                // 将该段加入当前IP地址
                path += s.substr(index, j-index+1) + '.';
                backtrack(j+1, segment+1);
                // 将该段从当前IP地址中移除以进行下一轮迭代
                path.erase(path.size() - (j-index+1) - 1); // 移除该段和最后一个'.'


            }
        };

        backtrack(0, 0);
        return res;
    }
};