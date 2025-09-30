

class Solution {
public:
    int encryptionCalculate(int dataA, int dataB) {
        while (dataB)
        {
            // 进位
            unsigned int c = static_cast<unsigned int>((dataA&dataB) << 1);
            // 无进位和
            dataA = dataA ^ dataB;
            dataB = c;
        }
        return dataA;
    }
};