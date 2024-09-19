#include <iostream>
using namespace std;

int main() {
    // 枚举 a, b, c 的所有可能值，范围从 0 到 9
    for (int a = 0; a <= 9; ++a) {
        for (int b = 0; b <= 9; ++b) {
            for (int c = 0; c <= 9; ++c) {
                // abc 表示三位数 a * 100 + b * 10 + c
                int abc = a * 100 + b * 10 + c;
                // bcc 表示三位数 b * 100 + c * 10 + c
                int bcc = b * 100 + c * 10 + c;
                // 检查 abc + bcc 是否等于 532
                if (abc + bcc == 532) {
                    // 如果满足条件，输出 a, b, c
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
    return 0;
}
