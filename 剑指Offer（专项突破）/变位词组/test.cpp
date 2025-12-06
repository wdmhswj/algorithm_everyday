#include "../../utils/utils.h"
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const std::string& s: strs) {
            std::string k = s;
            std::sort(k.begin(), k.end());
            map[k].emplace_back(s);
        }
        std::vector<std::vector<std::string>> ret;
        for (auto& [_, v]: map)
            ret.emplace_back(v);
        return ret;
    }

    std::vector<std::vector<std::string>> groupAnagrams1(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const std::string& s: strs) {
            std::array<int, 26> cnt = {};
            for (const char& c: s) {
                ++cnt[c-'a'];
            }
            std::string k;
            for (int i=0; i<26; ++i) {
                if (cnt[i]) {
                    k += 'a'+i;
                    k += std::to_string(cnt[i]);
                }        
            }
            map[k].emplace_back(s);
        }
        std::vector<std::vector<std::string>> ret;
        for (auto& [_, v]: map)
            ret.emplace_back(v);
        return ret;
    }
};