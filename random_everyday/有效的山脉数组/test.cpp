#include <vector>
using std::vector;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;

        int max = arr[0];
        bool isIncrease = true;
        bool s1=false;  // 是否经历第一阶段
        bool s2=false;  // 是否经历第二阶段
        for(int i=1; i<arr.size(); ++i)
        {
            if(arr[i]==arr[i-1])
                return false;
            // 第一阶段：严格增
            if(isIncrease && arr[i]>arr[i-1])
                s1=true;
            else if(s1 && isIncrease && arr[i]<arr[i-1])  // 转折
            {
                isIncrease = false; 
                s2 = true;
            }
            else if(!isIncrease && arr[i]<arr[i-1]) // 第二阶段：严格减
                continue;
            else return false;
        }
        return s1&&s2;
    }   
    bool validMountainArray2(vector<int>& arr) {
        if(arr.size()<3) return false;

        bool s1=false;  // 是否经历第一阶段
        bool s2=false;  // 是否经历第二阶段
        for(int i=1; i<arr.size(); ++i)
        {
            if(arr[i]==arr[i-1])
                return false;
            // 第一阶段：严格增
            if(!s1 && !s2 && arr[i]>arr[i-1])
                s1=true;
            else if(s1 && !s2 && arr[i]>arr[i-1])
                continue;
            else if(s1 && !s2 && arr[i]<arr[i-1])
                s2=true;
            else if(s1 && s2 && arr[i]<arr[i-1])
                continue;
            else return false;
        }
        return s1&&s2;
    }   
    // 双指针法
    bool validMountainArray3(vector<int>& arr) {
        if(arr.size()<3) return false;

        int left = 0;
        int right = arr.size()-1;
        while (left<arr.size()-1 && arr[left]<arr[left+1]) {
            ++left;
        }
        while (right>0 && arr[right-1]>arr[right]) {
            --right;
        }
        if(left==right && left!=0 && right!=arr.size()-1)
            return true;
        else return false;
    }   
};