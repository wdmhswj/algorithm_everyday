#include "../../utils/utils.h"

class Solution {
public:
    bool isPalindrome(std::string s) {
        const int n = s.size();
        if (n==0) return true;
        int l=0, r=n-1;
        while (l<r)
        {
            while (l<r && !isNumOrChar(s[l])) ++l;
            while (l<r && !isNumOrChar(s[r])) --r;
            if (toLower(s[l])!=toLower(s[r])) return false; 
            ++l;
            --r;
        }
        return true;
    }

    bool isNumOrChar(char c) {
        return (c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z');
    }

    char toLower(char c) {
        if (c>='A' && c<='Z')
            return c - ('A' - 'a');
        return c;
    }


    bool isPalindrome_1(std::string s) {
        const int n = s.size();
        if (n==0) return true;
        int l=0, r=n-1;
        while (l<r)
        {
            while (l<r && !isNumOrChar(s[l])) ++l;
            while (l<r && !isNumOrChar(s[r])) --r;
            if (std::tolower(s[l])!=std::tolower(s[r])) return false; 
            ++l;
            --r;
        }
        return true;
    }
    
};