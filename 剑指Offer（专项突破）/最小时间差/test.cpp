#include "../../utils/utils.h"

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        // 将 0~12 的时间加 24 
        std::vector<std::string> add;
        for (const std::string& t: timePoints) {
            if (getHour(t)<12) {
                std::string s = t;
                s[0] += 2;
                s[1] += 4;
                add.push_back(std::move(s));
                std::cout << "add: " << s << std::endl;
            }
        }
        std::vector<std::string> merged;
        merged.reserve(timePoints.size() + add.size());
        
        // 先合并
        merged.insert(merged.end(), timePoints.begin(), timePoints.end());
        merged.insert(merged.end(), add.begin(), add.end());
        
        // 再排序
        std::sort(merged.begin(), merged.end());

        for (const std::string& t: merged) {
            std::cout << t << " ";
        }

        // 排序
        // std::sort(timePoints.begin(), timePoints.end());
        // 计算相邻时间的差值，获取最小值
        int min = INT_MAX;
        for (int i=0; i<merged.size()-1; ++i)
        {
            int dif = difMin(merged[i], merged[i+1]);
            min = std::min(min, dif);
        }
        return min;
    }


    int findMinDifference1(std::vector<std::string>& timePoints) {
        const int n = timePoints.size();
        if (n>1440) return 0; // 存在重复时间点
        std::vector<int> nums;
        for (const std::string& t: timePoints) {
            int hour = (t[0]-'a')*10 + (t[1]-'a');
            int min = (t[3]-'a')*10 + (t[4]-'a');
            nums.push_back(hour*60+min);
        }
        std::sort(nums.begin(), nums.end());
        nums.push_back(nums[0]+1440);
        int min = 1440;
        for (int i=0; i<n; i++) {
            min = std::min(min, nums[i+1]-nums[i]);
        }
        return min;
    }
private:
    int difMin(const std::string& l, const std::string& r) {
        int l_h = (l[0]-'0') * 10 + (l[1]-'0');
        int r_h = (r[0]-'0') * 10 + (r[1]-'0');
        int l_m = (l[3]-'0') * 10 + (l[4]-'0');
        int r_m = (r[3]-'0') * 10 + (r[4]-'0');
        return r_h*60+r_m - l_h*60-l_m;
    }

    int getHour(const std::string& t) {
        return (t[0]-'0')*10+(t[1]-'0');
    }


};

int main() {
    Solution sol;
    std::vector<std::string> timePoints = {"23:59","00:00"};
    int res = sol.findMinDifference(timePoints);
    std::cout << res << std::endl;
    return 0;
}