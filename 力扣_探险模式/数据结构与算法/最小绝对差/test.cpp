
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int n = arr.size();
        if (n<2) return {};
        std::sort(arr.begin(), arr.end());
        std::vector<std::vector<int>> res;
        int min = INT_MAX;
        for (int i=1; i<n; ++i) {
            min = std::min(min, arr[i]-arr[i-1]);
        }

        for (int i=1; i<n; ++i) {
            if (arr[i]-arr[i-1] == min) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                res = {{arr[i - 1], arr[i]}};
            } else if (diff == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}