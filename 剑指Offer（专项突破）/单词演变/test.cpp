#include "../../utils/utils.h"

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        if (auto it = std::find(wordList.begin(), wordList.end(), endWord); it == wordList.end()) {
            return 0;
        }
        if (beginWord.size() != endWord.size()) {
            return 0;
        }

        std::unordered_set<std::string> words(wordList.begin(), wordList.end());
        int res = 1;
        std::queue<std::string> q({beginWord});
        while (!q.empty())
        {
            for (int i=q.size(); i>0; --i) {
                std::string cur = q.front(); q.pop();
                for (int j=0; j<cur.size(); ++j) {
                    char ch = cur[j];
                    for (int k=0; k<26; ++k) {
                        cur[j] = 'a' + k;
                        // if (std::find(words.begin(), words.end(), cur) == words.end()) // O(n)
                        //     continue;
                        if (words.count(cur) == 0) continue;
                        if (cur == endWord)
                            return res + 1;
                        q.push(cur);
                        words.erase(cur);
                    }
                    cur[j] = ch;
                }
            }
            ++res;
        }
        return 0;
    }
};