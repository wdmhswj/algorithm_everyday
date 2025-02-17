#include <vector>
#include <iostream>
using std::vector;


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 1;
        int res = arr[0];
        for(int i=1; i<arr.size()*3/4.0; ++i) {
            if(arr[i]==arr[i-1]) {
                ++count;
                if(count > arr.size()/4.0) {
                    return res;
                }
            }else{
                count = 1;
                res = arr[i];
            }
            // if(i>=arr.size()*3/4.0) {
            //     return arr[i];
            // }
        }
        return res;
    }
    int findSpecialInteger_1(vector<int>& arr) {
        const int n = arr.size();
        int index_1 = n/4;
        int index_2 = n/2;
        int index_3 = n*3/4;
        if(help(n, index_1, arr))
            return arr[index_1];
        else if(help(n, index_2, arr))
            return arr[index_2];
        else 
            return arr[index_3];

    }

    bool help(const int& n, int index, const vector<int>& arr) {
        int l_count = 0;
        int r_count = 0;
        for(int i=index-1; i>=0; --i) {
            if(arr[i]==arr[index]) {
                ++l_count;
            } else {
                break;
            }
        }
        for(int i=index+1; i<n; ++i) {
            if(arr[i]==arr[index]) {
                ++r_count;
            } else {
                break;
            }
        }
        if(l_count+r_count+1 > n/4.0)
            return true;
        else 
            return false;
    }
};

int main() {
    Solution s;
    vector<int> test{1,2,2,6,6,6,6,7,10};
    std::cout << s.findSpecialInteger(test) << std::endl;
}