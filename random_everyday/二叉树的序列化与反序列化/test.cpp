#include "../../structs/TreeNode.h"
#include <cctype>
#include <iostream>
#include <stack>
#include <string>

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
        if(!root)
            return {};
        string s = std::to_string(root->val);
        if(!root->left && !root->right) // 左右孩子均为空
            return s;
        else if(!root->right)   // 只有右孩子为空，左孩子不为空
            return s+"("+serialize(root->left)+")";
        else // 均不为空，或左为空右不为空
            return s+"("+serialize(root->left)+")"+"("+serialize(root->right)+")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        int index=0;
        return parse(data, index);
    }
private:
    TreeNode* help_deserialize(const string& data, int begin, int end)
    {
        if(data.empty() || begin==end)
            return nullptr;
        // 找到当前节点的值
        int value = 0;

        int positive = 1;
        int i=begin;
        if(data[i]=='-')
            positive=-1;
        else{
            value = value*10+data[i]-'0';
        }
        i++;
        for(; i<end; i++)
        {
            if(data[i]>='0'&&data[i]<='9')
                value = value*10+data[i]-'0';
            else
                break;
        }
        std::cout<<"value="<<value*positive<<std::endl;
        TreeNode* cur = new TreeNode(value*positive);

        // 匹配2/1/0个括号
        // 0个括号：字符串结束/后括号
        if(i==end || data[i]==')')
            return cur;
        // 1个括号：
        if(data[i]=='(')
        {
            // 找到第一个括号对的右括号
            std::stack<char> st;
            st.push('(');
            int k=i+1;
            while (!st.empty() && k<end) {
                if(data[k]==')')
                {
                    // char c=st.top();
                    st.pop();
                    if (st.empty()) {
                        break;
                    }
                }else if(data[k]=='('){
                    st.push('(');
                }
                ++k;
            }
            std::cout <<"i+1="<<i+1<<" k="<<k<<std::endl;
            cur->left = help_deserialize(data, i+1, k);
            // 再看是否有第二个括号对
            if(k+1<end && data[k+1]=='(')
            {
                
                while (!st.empty()) {
                    st.pop();
                }
                st.push('(');
                int g = k+2;
                while (!st.empty() && g<end) {
                    if(data[g]==')')
                    {
                        // char c=st.top();
                        st.pop();
                        if (st.empty()) {
                            break;
                        }
                    }else if(data[g]=='('){
                        st.push('(');
                    }
                    ++g;
                }
                std::cout <<"k+2="<<k+2<<" g="<<g<<std::endl;
                cur->right=help_deserialize(data, k+2, g);
            }
        }
        return cur;      

    }

    TreeNode* parse(const string& data, int& index)
    {
        // 读取根节点值
        int start = index;
        while(index<data.size() && (std::isdigit(data[index]) || data[index]=='-'))
        {
            index++;
        }
        if(index==start)
            return nullptr;
        int rootVal = std::stoi(data.substr(start, index-start));
        TreeNode* root = new TreeNode(rootVal);

        // 左子树
        if(index<data.size() && data[index]=='(')
        {
            index++;    // 跳过 (
            root->left = parse(data, index);
            index++;    // 跳过 )
        }

        // 右子树
        if(index<data.size() && data[index]=='(')
        {
            index++;    // 跳过 (
            root->right = parse(data, index);
            index++;    // 跳过 )
        }
        return root;
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

    // TreeNode* root  = new TreeNode(4);
    // root->left=new TreeNode(-7);
    // root->right=new TreeNode(-3);
    // // root->left->left=new TreeNode(4);
    // root->right->left=new TreeNode(-9);
    // root->right->right=new TreeNode(-3);
    // root->right->left->left=new TreeNode(9);
    // root->right->left->right=new TreeNode(-7);
    // root->right->right->left=new TreeNode(-4);

    TreeNode* root  = new TreeNode(1);
    // root->left=new TreeNode(-7);
    root->right=new TreeNode(2);

    Codec ser, deser;

    std::cout<<ser.serialize(root)<<std::endl;

    TreeNode* ans = deser.deserialize(ser.serialize(root));

    std::cout<<ser.serialize(ans)<<std::endl;
}