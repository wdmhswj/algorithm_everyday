#include "../../utils/utils.h"


class Solution {
public:
    std::string reverseMessage(std::string message) {
        int i = 0;
        int j = 0;
        int n = message.size();

        while (i<n)
        {
            while (i<n && message[i]==' ')
            {
                ++i;
            }
            if (i<n)
            {
                if (j!=0)
                {
                    message[j++] = ' ';
                }
                int k = i;
                while (k<n && message[k]!=' ')
                {
                    message[j++] = message[k++];
                }
                std::reverse(message.begin()+j-(k-i), message.begin()+j);
                i = k;
            }
        }
        message.erase(message.begin()+j, message.end());
        std::reverse(message.begin(), message.end());

        return message;   
    }

    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        while (ss >> word) {  // 自动忽略多余空格
            words.push_back(word);
        }
        if (words.empty()) return {};
        reverse(words.begin(), words.end());
        // return std::accumulate(
        //     next(words.begin()), words.end(), words[0],
        //     [](std::string a, const std::string& b) { return a + " " + b; });
        return std::accumulate(
            next(words.begin()),
            words.end(),
            words[0],
            [](const std::string& a, const std::string& b) { return a + " " + b; }
        );
    }

};