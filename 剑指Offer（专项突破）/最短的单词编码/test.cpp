#include "../../utils/utils.h"


class Solution {

    struct Trie {
        Trie* children[26] = {nullptr};
    };


public:
    int minimumLengthEncoding(std::vector<std::string>& words) {
        // 构建前缀树
        Trie* root = new Trie();
        Trie* cur = nullptr;
        for (const std::string& w: words) {
            cur = root;
            for (int i=w.size()-1; i>=0; --i) {
                if (cur->children[w[i]-'a']==nullptr) {
                    cur->children[w[i]-'a'] = new Trie();
                }
                cur = cur->children[w[i]-'a'];
            }
        }
        return dfs(root, 1);    // 统计前缀树中叶子节点对应的长度之和
    }

private:
    int dfs(Trie* cur, int l) {
        int ret = 0;    // 返回值
        bool isLeaf = true; // 判断是否为叶子
        for (int i=0; i<26; ++i) {
            if (cur->children[i]!=nullptr) {
                isLeaf = false;
                ret += dfs(cur->children[i], l+1);  // 当前不是叶子节点，所以递归直到是叶子节点
            }
        }
        if (isLeaf) {
            ret += l;
        }
        return ret;
    }
};