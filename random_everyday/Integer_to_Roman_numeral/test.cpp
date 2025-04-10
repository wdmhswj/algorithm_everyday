#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string intToRoman(int num) {
        const string I_R = "I";
        const string V_R = "V";
        const string X_R = "X";
        const string L_R = "L";
        const string C_R = "C";
        const string D_R = "D";
        const string M_R = "M";
        const string IV_R = "IV";
        const string IX_R = "IX";
        const string XL_R = "XL";
        const string XC_R = "XC";
        const string CD_R = "CD";
        const string CM_R = "CM";
        
        string res = "";

        while(num) {
            if(num>=1000) {
                int cur = num/1000;
                {
                    for(int i=0; i<cur; ++i) {
                        res += M_R;
                    }
                    num -= cur*1000;
                }
            } else if(num>=100) {
                int cur = num/100;
                if(cur==4) {
                    res += CD_R;
                    num -= 400;
                } else if(cur==9) {
                    res += CM_R;
                    num -= 900;
                } else {
                    if(cur>=5) {
                        res += D_R;
                        cur -= 5;
                        num -= 500;
                    }
                    for(int i=0; i<cur; ++i) {
                        res += C_R;
                    }
                    num -= cur*100;
                }
            } else if(num>=10) {
                int cur = num/10;
                if(cur==4) {
                    res += XL_R;
                    num -= 40;
                } else if(cur==9) {
                    res += XC_R;
                    num -= 90;
                } else {
                    if(cur>=5) {
                        res += L_R;
                        cur -= 5;
                        num -= 50;
                    }
                    for(int i=0; i<cur; ++i) {
                        res += X_R;
                    }
                    num -= cur*10;
                }

            } else {
                int cur = num;
                if(cur==4) {
                    res += IV_R;
                    num -= 4;
                } else if(cur==9) {
                    res += IX_R;
                    num -= 9;
                } else {
                    if(cur>=5) {
                        res += V_R;
                        cur -= 5;
                        num -= 5;
                    }
                    for(int i=0; i<cur; ++i) {
                        res += I_R;
                    }
                    num -= cur;
                }

            }
        }
        return res;
    }


};


int main() {
    Solution s;
    std::cout << s.intToRoman(3749) << std::endl;    
    std::cout << s.intToRoman(58) << std::endl;    
    std::cout << s.intToRoman(1994) << std::endl;    
}