#include "../../utils/utils.h"


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    void buildDict(std::vector<std::string> dictionary) {
        for (std::string word: dictionary) {
            _words.insert(word);
            for (const std::string& p: _patterns(word)) {
                ++_count[p];
            }
        }
    }
    
    bool search(std::string searchWord) {
        for (const std::string& p: _patterns(searchWord)) {
            if (_count[p]>1 || (_count[p]==1 && !_words.count(searchWord)))
                return true;
        }
        return false;
    }

    void buildDict1(std::vector<std::string> dictionary) {
        char c;
        for (std::string word: dictionary) {
            _words.insert(word);
            for (size_t i = 0; i < word.size(); i++)
            {
                c = word[i];
                word[i] = '*';
                ++_count[word];
                word[i] = c;
            }
            
        }
    }
    
    bool search1(std::string searchWord) {
        for (const std::string& p: _patterns(searchWord)) {
            if (_count[p]>1 || (_count[p]==1 && !_words.count(searchWord)))
                return true;
        }
        std::string originWord = searchWord;
        char c;
        for (size_t i = 0; i < searchWord.size(); i++)
        {
            c = searchWord[i];
            searchWord[i] = '*';
            if (_count[searchWord]>1 || (_count[searchWord]==1 && !_words.count(originWord)))
                return true;
            searchWord[i] = c;
        }
        
        return false;
    }
    

private:
    std::unordered_set<std::string> _words;
    std::unordered_map<std::string, int> _count;

    std::vector<std::string> _patterns(std::string word) {
        std::vector<std::string> ret(word.size());
        for (size_t i = 0; i < word.size(); i++)
        {
            char c = word[i];
            word[i] = '*';
            ret[i] = word;
            word[i] = c;
        }
        return ret;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */


class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    void buildDict(std::vector<std::string> dictionary) {
        for (std::string& word: dictionary) {
            _groups[word.size()].push_back(std::move(word));
        }
    }
    
    bool search(std::string searchWord) {
        auto it = _groups.find(searchWord.size());
        if (it==_groups.end()) {
            return false;
        }

        for (const std::string& candidate: it->second) {
            size_t diff = 0;
            for (size_t i=0; i<searchWord.size(); ++i) {
                if (searchWord[i]!=candidate[i]) ++diff;
                if (diff>1) break;
            }
            if (diff==1) return true;
        }
        return false;
    }

    
    

private:
    std::unordered_map<int, std::vector<std::string>> _groups;  // 按照单词的长度分组

};

