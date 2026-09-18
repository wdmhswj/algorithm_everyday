#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue_0(vector<int>& arr1, vector<int>& arr2, int d) {
        // 
        std::sort(arr1.begin(), arr1.end());
        std::sort(arr2.begin(), arr2.end());

        // arr1 升序遍历，arr2 降序遍历，找到第一个 arr1[i]-arr2[j]>d 的，则 [i,n-1] [0,j] 都符合
        // 找到最后一个 arr1[i]-arr2[j]<-d 的 则 [0,i] [0,j] 都符合
        // arr1 降序遍历，arr2 升序遍历，找到第一个 arr2[j]-arr1[i]>d 的，则 [j,n-1] [0,i] 都符合

        int res = 0;
        bool found = false;
        for (int i=0; i<arr1.size() && !found; ++i) {
            for (int j=arr2.size()-1; j>=0; --j) {
                if (arr1[i]-arr2[j] > d) {
                    res += (arr1.size()-i) * (j+1);
                    found = true;
                    break;
                }
            }
        }

        found = false;
        for (int j=0; j<arr2.size() && !found; ++j) {
            for (int i=arr1.size()-1; i>=0; --i) {
                if (arr2[j]-arr1[i] > d) {
                    res += (arr2.size()-j) * (i+1);
                    found = true;
                    break;
                }
            }
        }
        return res;
        
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());

        int res = 0;
        for (int x: arr1) {
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x-d);
            if (it==arr2.end() || *it>x+d) {
                ++res;
            }
        }
        return res;
    }
};


int main() {
    
    return 0;
}