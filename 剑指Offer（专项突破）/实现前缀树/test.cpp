#include "../../utils/utils.h"


class Trie {
private:
    Trie* _search(const std::string& prefix) {
        Trie* node = this;
        for (const char& c: prefix) {
            if (!node->_children[c-'a']) return nullptr;
            node = node->_children[c-'a'];
        }
        return node;
    }
public:
    /** Initialize your data structure here. */
    Trie(): _children(26), _isEnd(false) {

    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        Trie* node = this;
        for (const char& c: word) {
            if (!node->_children[c-'a'])
                node->_children[c-'a'] = new Trie();
            node = node->_children[c-'a'];
        }
        node->_isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        Trie* node = _search(word);
        return node!=nullptr && node->_isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        return _search(prefix)!=nullptr;
    }

private:
    std::vector<Trie*> _children;
    bool _isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */