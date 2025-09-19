#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class MonotonicQueue {
public:
    // 插入元素，保持递减
    void push(int x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back(); // 保持递减
        }
        dq.push_back(x);
    }

    // 弹出元素（如果等于队首才弹出）
    void pop(int x) {
        if (!dq.empty() && dq.front() == x) {
            dq.pop_front();
        }
    }

    // 获取当前窗口最大值
    int max() const {
        return dq.front();
    }

private:
    deque<int> dq; // 双端队列实现单调队列
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    MonotonicQueue mq;

    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {  
            // 先填满窗口
            mq.push(nums[i]);
        } else {
            // 加入新元素
            mq.push(nums[i]);
            // 记录当前窗口最大值
            result.push_back(mq.max());
            // 移除窗口最左元素
            mq.pop(nums[i - k + 1]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int x : ans) cout << x << " ";
    return 0;
}
