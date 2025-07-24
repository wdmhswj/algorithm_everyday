#include "../../utils/utils.h"

class Solution {
public:
    // 哈希表
    int findRepeatDocument(std::vector<int>& documents) {
        std::unordered_map<int, int> document_count;
        for(int id: documents) {
            ++document_count[id];
            if (document_count[id]>1) {
                return id;
            }
        }
        return -1;
    }

    // 排序
    int findRepeatDocument_1(std::vector<int>& documents) {
        std::sort(documents.begin(), documents.end());
        for (size_t i = 0; i < documents.size()-1; i++)
        {
            if (documents[i]==documents[i+1])
            {
                return documents[i];
            }
        }
        return -1;
        
    }

    // 原地交换
    int findRepeatDocument_2(std::vector<int>& documents) {
        for (int i = 0; i < documents.size(); i++)
        {
            while (i != documents[i]) {
                int j = documents[i];
                if (documents[j]==j)
                    return j;
                std::swap(documents[i], documents[j]);
            }
        }
        return -1;
        
    }
    
};