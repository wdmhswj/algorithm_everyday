#include <vector>
#include <iostream>
#include <chrono>


using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        bool isEven = true;
        int even = 0, odd = 0;
        while(n) {
            int remainder = n % 2;
            if(remainder == 1) {
                if(isEven) {
                    ++even;
                } else {
                    ++odd;
                }
            }
            isEven = !isEven;
            n /= 2;
        }
        return {even, odd};
    }
    vector<int> evenOddBit2(int n) {
        vector<int> res(2, 0);
        int i = 0;
        while(n) {
            res[i] += n & 1;
            n >>= 1;    // 右移一位
            i ^= 1;     // 0和1交替
        }
        return res;
    }
};

void test(int num = 100000000) {
    // 一个大数，2147483647

    Solution s;

    const int n =  2147483647-num;


    // 获取开始时间点
    auto start = std::chrono::high_resolution_clock::now();

    // 执行一些操作
    for(int i=0; i<num; ++i) {
        auto vec = s.evenOddBit(n+i);
    }

    // 获取结束时间点
    auto end = std::chrono::high_resolution_clock::now();

    // 计算持续时间并转换为毫秒
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // 输出运行时间
    std::cout << "evenOddBit Elapsed time: " << duration << " ms\n";

    // 获取开始时间点
    start = std::chrono::high_resolution_clock::now();

    // 执行一些操作
    for(int i=0; i<num; ++i) {
        auto vec = s.evenOddBit2(n+i);
    }

    // 获取结束时间点
    end = std::chrono::high_resolution_clock::now();

    // 计算持续时间并转换为毫秒
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // 输出运行时间
    std::cout << "evenOddBit2 Elapsed time: " << duration << " ms\n";

}

int main() {
    test();
}