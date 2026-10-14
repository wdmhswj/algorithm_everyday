
#include <bits/stdc++.h>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int n = inorder.size();
        return _buildTree(inorder, postorder, 0, 0, n);
    }
private:
    TreeNode* _buildTree(std::vector<int>& inorder, std::vector<int>& postorder, int b1, int b2, int n) {
        if (n<=0) return nullptr;
        int root_val = postorder[b2 + n -1];
        int root_idx = b1;
        for ( ; root_idx<b1+n; ++root_idx) {
            if (inorder[root_idx]==root_val) break;
        }
        TreeNode* root = new TreeNode(root_val);
        root->left = _buildTree(inorder, postorder, b1, b2, root_idx-b1);
        root->right = _buildTree(inorder, postorder, root_idx+1, b2+(root_idx-b1), n-(root_idx-b1)-1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int n = inorder.size();
        for (int i=0; i<n; ++i) {
            _map[inorder[i]] = i;
        }
        return _buildTree(inorder, postorder, 0, 0, n);
    }
private:
    TreeNode* _buildTree(std::vector<int>& inorder, std::vector<int>& postorder, int b1, int b2, int n) {
        if (n<=0) return nullptr;
        int root_val = postorder[b2 + n -1];
        int root_idx = _map[root_val];
        
        TreeNode* root = new TreeNode(root_val);
        root->left = _buildTree(inorder, postorder, b1, b2, root_idx-b1);
        root->right = _buildTree(inorder, postorder, root_idx+1, b2+(root_idx-b1), n-(root_idx-b1)-1);
        return root;
    }

    std::unordered_map<int, int> _map;
};

int main() {
    
    return 0;
}