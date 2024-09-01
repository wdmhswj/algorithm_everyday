#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    int findKthNumber(int n, int k) {
        auto cmp = [this](const int& n1, const int& n2) {
            return smaller2(n1, n2);
        };
        std::vector<int> arr(n,0);
        for(size_t i = 0; i<n; i++)
        {
            arr[i] = i+1;
        }
        // std::sort(arr.begin(), arr.end(), cmp);

        std::nth_element(arr.begin(), arr.begin()+k-1, arr.end(), cmp);
        return arr[k-1];
    }

    int findKthNumber2(int n, int k) {
        int cur = 1; // 从1开始
        --k;    // 减去已经走过的1
        while (k>0) {   // k==0则代表cur为第k小
            int steps = getSteps(cur, n);   // 获取以cur为根的子树的节点数目
            if (steps<=k) { // 第k小位于cur右边兄弟节点为根的子树中
                k -= steps;
                ++cur;  // 走到兄弟节点
            } else {
                cur*=10;    // 走到最左边孩子节点
                --k;
            }
        }
        return cur;
    }
private:
    int getSteps(int cur, long long n) {
        long long first = cur;
        long long last = cur;
        int count = 0;
        while (first<=n) {
            count += std::min(n, last) - first + 1;
            first *= 10;
            last = last*10+9;
        }
        return count;
    }
    bool smaller(int n1, int n2) {
        if (n1==n2) {
            return true;
        }

        int firstDigit1 = 0;
        int firstDigit2 = 0;
        int digits1 = 0;
        int digits2 = 0;

        while (n1>0 && n2>0) {
            getFirstDigit(n1, firstDigit1, digits1);
            getFirstDigit(n2, firstDigit2, digits2);
            if (firstDigit1<firstDigit2) {
                return true;
            } else if (firstDigit1>firstDigit2) {
                return false;
            } else {
                n1 -= firstDigit1 * std::pow(10, digits1);
                n2 -= firstDigit2 * std::pow(10, digits2);
                if (n1==0 && n2==0) {
                    return digits1<digits2;
                }
            }
        }
        if (n1<=0) {
            return true;
        }else {
            return false;
        }
        
    }

    bool smaller2(int n1, int n2) {
        if (n1==n2) {
            return true;
        }
        std::string s1 = std::to_string(n1);
        std::string s2 = std::to_string(n2);

        char firstDigit1;
        char firstDigit2;
        while (!s1.empty() && !s2.empty()) {
            firstDigit1 = s1[0];
            firstDigit2 = s2[0];
            if (firstDigit1<firstDigit2) {
                return true;
            } else if (firstDigit1>firstDigit2) {
                return false;
            } else {
                s1 = s1.erase(0, 1);
                s2 = s2.erase(0, 1);
            }
        }
        if (s1.empty()) {
            return true;
        } else {
            return false;
        }
    }
    void getFirstDigit(int n, int& firstDigit, int& digits) {
        n = std::abs(n);
        digits = 0;
        firstDigit = 0;
        while (n>=10) {
            n/=10;
            ++digits;
        }
        firstDigit = n;
    }
};

int main(){
    Solution s;
    std::cout<<s.findKthNumber2(1692778, 1545580);
}