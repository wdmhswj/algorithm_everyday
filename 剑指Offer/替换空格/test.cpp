#include "../../utils/utils.h"

class Solution {
public:
    // 原地修改
    std::string pathEncryption(std::string path) {
        for (char& c: path)
        {
            if (c=='.') {
                c=' ';
            }
        }
        return path;
    }

    // 另起炉灶
    std::string pathEncryption_1(std::string path) {
        std::string s;
        for (const char& c: path)
        {
            if (c=='.')
            {
                s += ' ';
            } else {
                s += c;
            }
        }
        return s;
    }

    // 原地修改(替换字符串>原字符)
    std::string pathEncryption_2(std::string path) {
        // const std::string s_r = "rpl";
        const std::string s_r = " ";
        const int len = path.size();
        int count = 0;
        for (char& c: path)
        {
            if (c=='.') {
                ++count;
            }
        }
        int incLen = s_r.size()-1;
        path.resize(len + count*incLen);
        for (int i=0; i<len; ++i)
        {
            if (path[i]=='.') {
                for (int j=0; j<=incLen; ++j)
                {
                    path[i+count*incLen-(incLen-j)] = s_r[j];
                }
                --count;
            } else {
                path[i+count*incLen] = path[i];
            }
        }
        return path;
    }
};