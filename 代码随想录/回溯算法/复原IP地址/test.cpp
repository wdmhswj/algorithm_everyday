#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
private:

    void backtracking(const string&s, vector<vector<int>>& schemes, vector<int>& path, int startIndex) {
        if (startIndex>=s.size() ) {
            if(path.size()==4)
                schemes.push_back(path);
            return;
        }
        
        for (int len=1; len<=3; ++len) {
            if (startIndex+len > s.size()) {
                break;
            }
            if (len>1 && s[startIndex]=='0') {
                break;
            }
            string substr = s.substr(startIndex, len);
            int i = str2Int(substr);
            if (!isValid(i)) {
                break;   // 待优化
            }
            path.push_back(i);
            backtracking(s, schemes, path, startIndex+len);
            path.pop_back();
        }

    }
    int str2Int(const string& s) {
        int res = 0;
        for (const auto& c : s) {
            res = res*10 + (c-'0');
        }
        return res;
    }
    bool isValid(const int& i) {
        return i>=0 && i<=255;
    }
    vector<string> transform(const vector<vector<int>>& schemes) {
        vector<string> res;
        for (const auto& vec : schemes) {
            string str;
            for (const int& i : vec) {
                if (str.empty()) {
                    str += std::to_string(i);
                } else {
                    str += ("." + std::to_string(i));
                }
            }
            res.push_back(str);
        }
        return res;
    }

    // 法2：
    void backtracking_1(string& s, int startIndex, int pointNum, vector<string>& res) {
        if (pointNum == 3) {
            if (isValid_1(s, startIndex, s.size())) {
                res.push_back(s);
            }
            return;
        }

        for(int i=startIndex+1; i<=s.size(); i++) {
            if (isValid_1(s, startIndex, i)) {
                s.insert(s.begin() + i, '.');
                backtracking_1(s, i+1, pointNum+1, res);
                s.erase(s.begin()+i);
            } else {
                break;
            }
        }
    }
    bool isValid_1(const string& s, int start, int end) {
        if (start>=end) {
            return false;
        }
        if (s[start] == '0' && start+1 != end) {
            return false;
        }
        int num = 0;
        for(int i=start; i<end; i++) {
            if (s[i]<'0' || s[i]>'9') {
                return false;
            }
            num = num*10 + (s[i] - '0');
            if (num<0 || num >255) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> path;
        backtracking(s, res, path, 0);
        // std::cout<<"res.size(): "<< res.size()<<std::endl;
        return transform(res);
    }
};


int main() {
    string s = "25525511135";
    Solution solution;
    auto res = solution.restoreIpAddresses(s);
    for(auto s: res) {
        std::cout<< s <<" ";
    }
}