#include "../../utils/utils.h"

class MapSum {
private:
    struct Trie {
        Trie* children[26] = {nullptr};
        bool isWord = false;
        int val;
    };

    Trie* root;

    int dfs(Trie* root) {
        int ret = 0;
        if (root->isWord) ret += root->val;
        for (int i=0; i<26; ++i) {
            if (root->children[i]!=nullptr) {
                ret += dfs(root->children[i]);
            }
        }
        return ret;
    }

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie();
    }
    
    void insert(std::string key, int val) {
        Trie* cur = root;
        for (char c: key) {
            if (cur->children[c-'a']==nullptr) {
                cur->children[c-'a'] = new Trie();
            }
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
        cur->val = val;
    }
    
    int sum(std::string prefix) {
        Trie* cur = root;
        for (char c: prefix) {
            if (cur->children[c-'a']==nullptr) {
                return 0;
            }
            cur = cur->children[c-'a'];
        }

        // int ret = 0;
        return dfs(cur);

    }
};

class MapSum {
private:
    std::unordered_map<std::string, int> _map_values;
    std::unordered_map<std::string, int> _map_sums;

public:
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(std::string key, int val) {
        int old = _map_values[key];
        _map_values[key] = val;
        for (size_t i=1; i<=key.size(); ++i) {
            std::string prefix = key.substr(0, i);
            _map_sums[prefix] += (val-old);
        }
    }
    
    int sum(std::string prefix) {
        return _map_sums[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */