#include "../../../structs/TreeNode.h"
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

using std::vector;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void traversal(TreeNode* root, vector<int>& asc_vec) {
        if (root==nullptr) {
            return;
        }
        traversal(root->left, asc_vec);
        asc_vec.emplace_back(root->val);
        traversal(root->right, asc_vec);
    }
    bool static cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second>b.second;
    }

    void searchBST(TreeNode* cur, std::unordered_map<int, int>& map) { // 前序遍历
        if (cur == nullptr) return ;
        map[cur->val]++; // 统计元素频率
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return ;
    }

    // 注意pre类型需要为指针的引用
    void searchBST_2(TreeNode* cur, int& max_count, TreeNode* &pre, int& cur_count, vector<int>& res) { // 中序遍历 
        if (cur == nullptr) return ;

        searchBST_2(cur->left, max_count, pre, cur_count, res);

        if (pre==nullptr) { // 第一个节点
            cur_count=1;
        } else if (pre->val==cur->val) {
            ++cur_count;
        } else if (pre->val!=cur->val) {
            cur_count=1;
        }
        if (cur_count>max_count) {
            max_count=cur_count;
            res.clear();
            res.push_back(cur->val);
        } else if (cur_count==max_count) {
                res.push_back(cur->val);
        }
        pre = cur;

        searchBST_2(cur->right, max_count, pre, cur_count, res);
    }

public:
    vector<int> findMode(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        vector<int> asc_vec;
        traversal(root, asc_vec);
        std::map<int, int> map;
        for (const int& ele : asc_vec) {
            if(map.find(ele)==map.end()) {
                map[ele]=1;
            } else {
                map[ele]+=1;
            }
        }
        vector<int> res;
        int max_count = 0;
        for (auto it : map) {
            if (it.second>max_count) {
                max_count=it.second;
                res.clear();
                res.push_back(it.first);
            } else if (it.second==max_count) {
                res.push_back(it.first);
            }
        }
        return res;
        
    }
    vector<int> findMode_1(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        vector<int> asc_vec;
        traversal(root, asc_vec);
        std::map<int, int> map;
        for (const int& ele : asc_vec) {
            if(map.find(ele)==map.end()) {
                map[ele]=1;
            } else {
                map[ele]+=1;
            }
        }
        vector<int> res;
        vector<std::pair<int, int>> record(map.begin(), map.end());
        std::sort(record.begin(), record.end(), cmp);
        res.push_back(record[0].first);
        for (int i=1; i<record.size(); ++i) {
            if (record[i].second==record[0].second) {
                res.push_back(record[i].first);
            }
        }
        return res;
        
    }

    vector<int> findMode_2(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        std::unordered_map<int, int> map;
        searchBST(root, map);
        vector<int> res;
        vector<std::pair<int, int>> record(map.begin(), map.end());
        std::sort(record.begin(), record.end(), cmp);
        res.push_back(record[0].first);
        for (int i=1; i<record.size(); ++i) {
            if (record[i].second==record[0].second) {
                res.push_back(record[i].first);
            }
        }
        return res;

    }

    vector<int> findMode_3(TreeNode* root) {
        if (root==nullptr) {
            return {};
        }
        TreeNode* pre = nullptr;
        int max_count = 0, cur_count = 0;
        vector<int> res;
        searchBST_2(root, max_count, pre, cur_count, res);
        return res;

    }
};