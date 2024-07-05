
#include <string>
#include <vector>
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n==0) {
            return 0;
        }
        // 将n转化为对应于每一位的数字数组
        std::vector<int> digits;
        while(n) {
            digits.push_back(n%10);
            n/=10;
        }
        if (digits.size()==1) {
            return n;
        }
        for(int i=1; i<digits.size(); ++i){
            if (digits[i]>digits[i-1]) {
                for(int j=0; j<i; ++j){
                    digits[j]=9;
                }
                --digits[i];
            }
        }
        // 将数字数组转化为数
        int res = 0;
        for (int i=digits.size()-1; i>=0; --i) {
            res=res*10+digits[i];
        }
        return res;
    }
    int monotoneIncreasingDigits1(int n) {
        if (n==0) {
            return 0;
        }
        // 将n转化为对应于每一位的数字数组
        std::vector<int> digits;
        while(n) {
            digits.push_back(n%10);
            n/=10;
        }
        if (digits.size()==1) {
            return n;
        }
        int mark = 0;
        for(int i=1; i<digits.size(); ++i){
            if (digits[i]>digits[i-1]) {
                mark = i;
                --digits[i];
            }
        }
        for(int i=0; i<mark; ++i){
            digits[i]=9;
        }
        // 将数字数组转化为数
        int res = 0;
        for (int i=digits.size()-1; i>=0; --i) {
            res=res*10+digits[i];
        }
        return res;
    }

    int monotoneIncreasingDigits2(int N) {
        std::string strNum = std::to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};