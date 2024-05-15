#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;

class Solution {
private:
    vector<string> res;
    string str;
    vector<string> getLetters(const char& c) {
        if (c<'2' || c >'9') {
            return {};
        }
        int n = c - '2';
        string start(1,'a');
        vector<string> res;
        res.push_back(string(1,'a'+n*3));
        res.push_back(string(1,'a'+n*3+1));
        res.push_back(string(1,'a'+n*3+2));
        return res;
    }
    std::unordered_map<char, vector<string>> map = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };

    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
    
    void backtracking(const string& digits, int index) {
        if (digits.empty()) {
            return;
        }
        if (index == digits.size()) {
            res.push_back(str);
            return;
        }
        vector<string> letters = getLetters(digits[index]);
        for (auto letter : map[digits[index]]) {
            str += letter;
            backtracking(digits, index+1);
            str.pop_back();
        }

    }

    void backtracking_1(const string& digits, int index) {
        if (digits.empty()) {
            return;
        }
        if (index == digits.size()) {
            res.push_back(str);
            return;
        }
        string letters = letterMap[digits[index]-'0'];
        for (int i=0; i<letters.size(); ++i) {
            str += letters[i];
            backtracking(digits, index+1);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return res;
    }
};