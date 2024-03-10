#include "../../structs/TreeNode.h"
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param vinOrder int整型vector 
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        // write code here
        if(preOrder.size()==0 || vinOrder.size()==0) return nullptr;

        // 根节点为前序遍历的第一个
        TreeNode* res = new TreeNode(preOrder[0]);
        // 在中序遍历找到根节点的位置
        int mid = distance(vinOrder.begin(), find(vinOrder.begin(), vinOrder.end(), preOrder[0]));
        // 递归处理
        vector<int> left_pre(preOrder.begin()+1, preOrder.begin()+1+mid);
        vector<int> right_pre(preOrder.begin()+1+mid, preOrder.end());
        vector<int> left_vin(vinOrder.begin(), vinOrder.begin()+mid);
        vector<int> right_vin(vinOrder.begin()+1+mid, vinOrder.end());

        res->left = reConstructBinaryTree(left_pre, left_vin);
        res->right = reConstructBinaryTree(right_pre, right_vin);

        return res;
    }
};