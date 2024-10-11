#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) {
            return 1;
        }
        int p1 = 1, p2=1;
        int flag = 0;
        const int n = nums.size();
        while (p1<n && p2<n) {
            if(flag == 0 ){
                if(nums[p1-1]==nums[p2]){
                    flag = 1;
                }
                nums[p1] = nums[p2];
                ++p1;
                ++p2;
            }else if (flag==1) {
                if(nums[p1-2]==nums[p2]){
                    flag = 2;
                }else{
                    nums[p1] = nums[p2];
                    ++p1;
                    flag = 0;
                }
                ++p2;
            }else{
                if(nums[p1-2]!=nums[p2]){
                    nums[p1] = nums[p2];
                    ++p1;
                    flag = 0;
                }
                ++p2;
            }

        }
        return p1;
    }

    int removeDuplicates2(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int p1 = 2;  // 从第三个元素开始判断
        for (int p2 = 2; p2 < n; ++p2) {
            if (nums[p2] != nums[p1 - 2]) {
                nums[p1] = nums[p2];  // 当前元素与 p1-2 元素不相等，放入 p1 位置
                ++p1;  // 更新 p1，表示新数组的有效长度
            }
        }

        return p1;  // 新数组的长度
    }
};