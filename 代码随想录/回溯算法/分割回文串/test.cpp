#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> isPalindrome;

    void computePalindrome(const string& s) {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size()-1; i>=0; i--) {
            for(int j=i; j<s.size(); j++) {
                if (j==i) {
                    isPalindrome[i][j] = true;
                } else if (j-i==1) {
                    isPalindrome[i][j] = (s[i]==s[j]);
                } else {
                    isPalindrome[i][j] = (s[i]==s[j] && isPalindrome[i+1][j-1]);
                }

            }
        }
    }

    void backtracking(const string& s, int startIndex) {
        if (startIndex>=s.size()) {
            res.push_back(path);
            return;
        }
        for (int i=startIndex; i<s.size(); ++i) {
            if (isPalindrome[startIndex][i]) {
                path.push_back(s.substr(startIndex, i-startIndex+1));
            } else {
                continue;
            }
            backtracking(s, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return {};
        }
        computePalindrome(s);
        backtracking(s, 0);
        return res;
    }
};