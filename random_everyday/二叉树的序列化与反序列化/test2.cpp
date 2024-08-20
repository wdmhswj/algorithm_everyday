#include "../../structs/TreeNode.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::string;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)   
            return "#";
        return std::to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto dataArray = split(data, ',');
        int index = 0;
        return parse(dataArray, index);
    }
private:
    TreeNode* parse(const std::vector<string>& dataArray, int& index) {
        if (dataArray[index]=="#") {
            return nullptr;
        }else{
            int value = std::stoi(dataArray[index]);
            TreeNode* cur = new TreeNode(value);
            ++index;
            if(index<dataArray.size())
            {
                cur->left = parse(dataArray, index);
            }
            ++index;
            if(index<dataArray.size())
            {
                cur->right = parse(dataArray, index);
            }
            return cur;
        }

    }
    std::vector<string> split(const string& data, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::stringstream ss(data);
        while(std::getline(ss, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


int main()
{
    // TreeNode* root  = new TreeNode(1);
    // root->left=new TreeNode(2);
    // root->right=new TreeNode(3);
    // // root->left->left=new TreeNode(4);
    // root->right->left=new TreeNode(4);
    // root->right->right=new TreeNode(5);

    TreeNode* root  = new TreeNode(4);
    root->left=new TreeNode(-7);
    root->right=new TreeNode(-3);
    // root->left->left=new TreeNode(4);
    root->right->left=new TreeNode(-9);
    root->right->right=new TreeNode(-3);
    root->right->left->left=new TreeNode(9);
    root->right->left->right=new TreeNode(-7);
    root->right->right->left=new TreeNode(-4);

    // TreeNode* root  = new TreeNode(1);
    // // root->left=new TreeNode(-7);
    // root->right=new TreeNode(2);

    Codec ser, deser;

    std::cout<<ser.serialize(root)<<std::endl;

    TreeNode* ans = deser.deserialize(ser.serialize(root));

    std::cout<<ser.serialize(ans)<<std::endl;
}