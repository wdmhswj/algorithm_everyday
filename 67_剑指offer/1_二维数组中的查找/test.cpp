#include<vector>
using namespace std;

// 从右上角遍历到左下角
bool Find_1(int target, vector<vector<int> > array){
    // 判断特殊情况
    if(array.empty() || array[0].empty())
        return false;
    // 行列值
    int row=array.size(), col=array[0].size();
    // 遍历的指针
    int w=col-1, h=0;
    while(w>=0 && h<col){
        if(array[h][w] == target) return true;
        else if( array[h][w] < target) return ++h;
        else --w;
    }
    return false;   // 遍历完数组，未找到
}


// 对每个子一维数组使用二分查找
bool Find_2(int target, vector<vector<int> > array){
    // 判断特殊情况
    if(array.empty() || array[0].empty())
        return false;
    for( vector<int> arr: array){
        if(hasTarget_binarySearch(arr, target)) return true;
    }
    return false;
}

bool hasTarget_binarySearch(const vector<int>& arr, int target){
    // 左右指针（左闭右开）
    int left=0, right=arr.size();
    while(left<right){
        int mid = left + (right-left)/2;    // 中间节点
        if(arr[mid]==target)    return true;
        else if(target<arr[mid])    right=mid;
        else    left=mid+1;
    }
    return false;
}