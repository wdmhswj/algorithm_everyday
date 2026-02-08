#include "../../utils/utils.h"


class Trie {
private:    
    std::vector<Trie*> _children;
    std::string _val;

public:
    Trie(): _children(26), _val("") {}
    
    void insert(const std::string& word) {
        Trie* node = this;
        for (const char& c: word) {
            if (node->_children[c-'a']==nullptr) node->_children[c-'a'] = new Trie();
            node = node->_children[c-'a'];
        }
        node->_val = word;
    }

    std::string search(const std::string& word) {
        Trie* node = this;
        for (const char& c: word) {
            if (node->_children[c-'a']==nullptr) break;
            node = node->_children[c-'a'];
            if (node->_val!="") return node->_val;  // 匹配到最短的一个前缀
        }

        return word;    // 没有匹配到的
    }

};

class Solution {
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        std::unordered_set<std::string> us(dictionary.begin(), dictionary.end());
        std::istringstream iss(sentence);
        std::string word;
        std::string prefix;
        std::string root;
        std::string ret;
        while (iss>>word) {
            root = word;
            for (std::size_t i=1; i<=word.size(); ++i) {
                prefix = word.substr(0, i);
                if (us.count(prefix)) {
                    root = prefix;
                    break;  // 由于子字符串大小是由小到大遍历的，所以在遇到匹配的字符串后立即break，确保词根是最短的
                }
            }
            ret += root + " ";
        }
        ret.pop_back(); // 删去末尾空格
        return ret;
    }

    std::string replaceWords1(std::vector<std::string>& dictionary, std::string sentence) {
        Trie* t = new Trie();
        for (const std::string& s: dictionary) {
            t->insert(s);
        }
        std::istringstream iss(sentence);
        std::string word;
        std::string ret;
        while (iss>>word) {
            ret += t->search(word) + " ";
        }
        ret.pop_back();
        return ret;
    }
};