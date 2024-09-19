#include <iostream>
using namespace std;

int count = 0;
// 汉诺塔递归函数
void hanoi(int n, char source, char auxiliary, char destination) {
    // 基本情况：如果只有一个圆盘，直接从源柱移动到目标柱
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        ++count;
        return;
    }

    // 递归步骤：
    // 1. 先将 n-1 个圆盘从源柱移动到辅助柱
    hanoi(n - 1, source, destination, auxiliary);
    
    // 2. 将第 n 个圆盘从源柱移动到目标柱
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    ++count;
    // 3. 最后将 n-1 个圆盘从辅助柱移动到目标柱
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    // 开始汉诺塔的递归移动
    hanoi(n, 'A', 'B', 'C');  // A 是源柱，B 是辅助柱，C 是目标柱

    std::cout<<"count: "<<count;
    return 0;
}


