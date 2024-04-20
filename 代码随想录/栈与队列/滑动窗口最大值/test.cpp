#include <deque>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using std::vector;
using std::string;

class Solution {
public:
    // 法1：使用最大堆; 时间复杂度：O(n log n); 空间复杂度：O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // 优先级队列
        std::priority_queue<std::pair<int, int>> q;
        // 先将前k个元素放入
        for (int i=0; i<k; ++i) {
            q.emplace(nums[i], i);
        }

        // 结果数组
        vector<int> res = {q.top().first};

        for (int i=k; i<n; ++i) {
            // 加入新的元素
            q.emplace(nums[i], i);
            // 如果堆顶元素（最大元素）超过左边界，则删除
            while(q.top().second <= i-k) {
                q.pop();
            }
            // 确定当前k个元素的最大值
            res.push_back(q.top().first);
        }
        return res;

    }
    // 法2：使用单调队列; 时间复杂度：O(n log n); 空间复杂度：O(n)
    vector<int> maxSlidingWindow_1(vector<int>& nums, int k) {
        int n = nums.size();
        // 双端队列，按照index顺序，且元素值严格单调递减
        std::deque<int> q;
        // 先将前k个元素放入，同时维护单调队列
        for (int i=0; i<k; ++i) {
            while (!q.empty() && nums[i]>=nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        // 结果数组
        vector<int> res = {nums[q.front()]};

        for (int i=k; i<n; ++i) {
            // 将单调队列的元素与要新加的元素进行比较，维护单调队列
            while (!q.empty() && nums[i]>=nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);

            // 删去超过左边界的元素
            while (q.front()<=i-k) {
                q.pop_front();
            }

            // 获取当前k个元素的最大值
            res.push_back(nums[q.front()]);
        }
        return res;

    }
};