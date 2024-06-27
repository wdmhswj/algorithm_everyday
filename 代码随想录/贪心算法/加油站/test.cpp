#include <vector>

using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1;
        int size = gas.size();
        for (int i=0; i<size; ++i) {
            int sum1 = 0;
            int sum2 = 0;
            // bool flag = true;
            for (int j=0; j<size; ++j) {
                sum1 += gas[(i+j)%size];
                sum2 += cost[(i+j)%size];
                if (sum1<sum2) {
                    // flag=false;
                    break;
                }
            }
            if (sum1>=sum2) {
                res=i;
                break;
            }
        }
        return res;
    }

    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
       for (int i = 0; i < cost.size(); i++) {
            int rest = gas[i] - cost[i]; // 记录剩余油量
            int index = (i + 1) % cost.size();
            while (rest > 0 && index != i) { // 模拟以i为起点行驶一圈（如果有rest==0，那么答案就不唯一了）
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            // 如果以i为起点跑一圈，剩余油量>=0，返回该起始位置
            if (rest >= 0 && index == i) return i;
        }
        return -1;
    }

     int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int startIndex = 0;
        int total_rest = 0;
        int cur_gas = 0;
        for (int i=0; i<gas.size(); i++) {
            cur_gas += gas[i]-cost[i];
            total_rest += gas[i]-cost[i];
            if (cur_gas<0) {
                cur_gas = 0;
                startIndex = i+1;
            }
        }
        if (total_rest<0) {
            return -1;
        }
        return startIndex;
    }
};