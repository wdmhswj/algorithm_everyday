#include "../../utils/utils.h"


class Solution {
public:
    std::vector<std::string> goodsOrder(std::string goods) {
        
        std::vector<std::string> rt;

        std::function<void(int)> dfs = [&](int index) {
            if (index == goods.size()-1) {
                rt.push_back(goods);
                return;
            }

            std::unordered_set<char> visit;
            for (int i=index; i<goods.size(); ++i) {
                if (!visit.count(goods[i])) {
                    visit.insert(goods[i]);
                    std::swap(goods[index], goods[i]);
                    dfs(index+1);
                    std::swap(goods[index], goods[i]);
                }
            }
        };

        dfs(0);

        return rt;
    }

    std::vector<std::string> goodsOrder1(std::string goods) {
        
        std::unordered_set<std::string> rt_hash;
        std::vector<bool> visit(goods.size(), false);
        std::string tmp;
        std::function<void(int)> dfs = [&](int index) {
            if (index == goods.size()) {
                rt_hash.insert(tmp);
                return;
            }

            // std::unordered_set<char> visit;
            for (int i=0; i<goods.size(); ++i) {
                if (!visit[i]) {
                    visit[i]=true;
                    tmp.push_back(goods[i]);
                    dfs(index+1);
                    tmp.pop_back();
                    visit[i]=false;
                }
            }
        };

        dfs(0);

        return {rt_hash.begin(), rt_hash.end()};
    }
};