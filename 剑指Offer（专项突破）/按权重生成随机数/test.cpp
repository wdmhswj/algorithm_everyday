#include "../../utils/utils.h"

class Solution {
public:
    Solution(std::vector<int>& w): _weights(w), _engine(std::random_device{}()) {
        for (const int& e: w) {
            _sum += e;
        }

    }
    
    int pickIndex() {
        // 生成0~_sum-1的随机数rand
        std::uniform_int_distribution<long long> dist(0, _sum-1);
        long long rand = dist(_engine);
        // 根据rand范围选取
        long long s = 0;
        for (int i=0; i<_weights.size(); ++i) {
            s += _weights[i];
            if (s>rand) {
                return i;
            }
        }
        return 0;
    }
private:
    long long _sum = 0;
    std::vector<int> _weights;
    std::mt19937 _engine;

};

class Solution {
public:
    Solution(std::vector<int>& w): _engine(std::random_device{}()) {
        _prefix_sums.reserve(w.size());
        for (const int& e: w) {
            _sum += e;
            _prefix_sums.push_back(_sum);
        }
        _dist = std::uniform_int_distribution<long long>(1, _sum);
    }
    
    int pickIndex() {
        // 生成1~_sum的随机数rand
        long long rand = _dist(_engine);
        // 根据rand范围选取
        auto it = std::lower_bound(_prefix_sums.begin(), _prefix_sums.end(), rand);
        return std::distance(_prefix_sums.begin(), it);
    }
private:
    long long _sum = 0;
    std::vector<long long> _prefix_sums;
    std::mt19937 _engine;
    std::uniform_int_distribution<long long> _dist;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */