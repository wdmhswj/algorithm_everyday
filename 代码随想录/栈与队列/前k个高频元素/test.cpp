#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using std::vector;

class Solution {
public:
    // 自定义比较函数类
    class mycomparison {
        public:
            bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs){
                return lhs.second>rhs.second;
            }
    };

    // 法1：基于堆排序；时间复杂度：O(n log k)；空间复杂度：O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计元素出现的频率
        std::unordered_map<int, int> map;
        for (int i=0; i<nums.size(); ++i) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫描所有频率的数值
        for (auto pair : map) {
            pri_que.push(pair);
            if (pri_que.size()>k) {
                pri_que.pop();
            }
        }

        // 按照频率由大到小的顺序输出
        vector<int> res(k);
        for (int i=k-1; i>=0; --i) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }

        return res;
    }
};