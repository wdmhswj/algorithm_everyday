#include "../../utils/utils.h"



class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const std::string& word: strs) {
            std::string key = word;
            std::sort(key.begin(), key.end());
            map[key].emplace_back(word);
        }
        std::vector<std::vector<std::string>> ret;
        for (auto& pair: map) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};