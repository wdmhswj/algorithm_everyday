#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using std::vector;
using std::string;



void print2Vec(const vector<vector<int>>& intervals){
    for (auto& vec : intervals) {
        for(auto& num: vec) {
            std::cout<<num<<" ";
        }
        std::cout<<std::endl;
    }
}

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 记录26个字母在字符串s中的开始和结束位置
        vector<vector<int>> record(26, vector<int>(2, -1));
        for (int i=0; i<s.size(); ++i) {
            if (record[s[i]-'a'][0]==-1) {  // 开始位置
                record[s[i]-'a'][0]=i;
                record[s[i]-'a'][1]=i;
            } else {
                record[s[i]-'a'][1] = i;    // 又出现了一次
            }
        }
        // 删去未出现的字母
        vector<vector<int>> record2;
        for (const vector<int>& vec: record){
            if (vec[0]!=-1) {  
                record2.push_back(vec);
            } 
        }

        // 求无重叠区域的最大数目
         // 先排序
        std::sort(record2.begin(), record2.end(), 
        [](const vector<int>& l, const vector<int>& r) -> bool {
            return l[0]<r[0];
        });

        print2Vec(record2);

        vector<int> res;   
        int right_bound = record2[0][1];  // 当前已遍历的无重叠的intervals的右边界
        int length = record2[0][1]-record2[0][0]+1; // 记录当前区间长度
        for(int i=1; i<record2.size(); ++i) {
            // 判断是否重叠
            if (record2[i][0]<right_bound) {    // 有重叠(要用有边界而不是上一个index的有边界！！！)
                if (record2[i][1]>right_bound) {  // 右边界有更大的选择
                    length+=record2[i][1]-right_bound;
                    right_bound=record2[i][1];
                }
            } else {
                right_bound=record2[i][1];
                res.push_back(length);
                length=record2[i][1]-record2[i][0]+1;
            }
        }
        res.push_back(length);
        return res;

    }
    vector<int> partitionLabels1(string s) {
        vector<int> last(26, -1);
        for (int i=0; i<s.size(); ++i) {
            last[s[i]-'a']=i;
        }
        vector<int> res;
        int start=0, end=0;
        for(int i=0; i<s.size();++i){
            end = std::max(last[s[i]-'a'], end);
            if (i==end) {
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};

int main(){
    string str = "eccbbbbdec";
    Solution s;
    s.partitionLabels(str);

}