#include <vector>
#include <algorithm>
#include <list>
using std::vector;
using std::list;

class Solution {
public:
    static bool compare(vector<int>l, vector<int> r) {
        return l[0]>r[0]  || l[0]==r[0]&&l[1]<l[2];
    }

    // 直接使用vector动态插入，可以省去移动部分数组的开销
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // std::sort(people.begin(), people.end(), compare);
        std::sort(people.begin(), people.end(), [](vector<int>l, vector<int> r) -> bool { return l[0]>r[0] || l[0]==r[0]&&l[1]<r[1];});
        vector<vector<int>> res(people.size(), {-1, -1});
        for (int i=0; i<people.size(); ++i) {
            if (res[people[i][1]][0]==-1) {
                res[people[i][1]][0]=people[i][0];
                res[people[i][1]][1]=people[i][1];
            }else{
                for(int j=i; j>=people[i][1]+1; --j) {
                    res[j][0]=res[j-1][0];
                    res[j][1]=res[j-1][1];
                }
                res[people[i][1]][0]=people[i][0];
                res[people[i][1]][1]=people[i][1];
            }
        }
        return res;
    }
    vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
        // std::sort(people.begin(), people.end(), compare);
        std::sort(people.begin(), people.end(), [](vector<int>l, vector<int> r) -> bool { return l[0]>r[0] || l[0]==r[0]&&l[1]<r[1];});
        vector<vector<int>> res;
        for (int i=0; i<people.size(); ++i) {
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;
    }

     vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](vector<int>l, vector<int> r) -> bool { return l[0]>r[0] || l[0]==r[0]&&l[1]<r[1];});
        list<vector<int>> que; // list底层是链表实现，插入效率比vector高的多
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};