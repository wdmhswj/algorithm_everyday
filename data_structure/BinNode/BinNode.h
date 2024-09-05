#pragma once

using Rank = unsigned int;

#if defined (DSA_REDBLACK)  // 在红黑树中
#define stature(p) ((p) ? (p)->height : 0)  // 外部节点（黑）高度威0
#else   // 其余BST中
#define stature(p) ((int)((p) ? (p)->height : -1))  // 外部节点高度为-1
#endif

// #define BinNodePosi<T> BinNode<T>*  // 节点位置
// #define stature(p) ((p) ? (p)->height : -1) // 节点高度（与”空树高度为-1“的约定相统一）
typedef enum { RB_RED, RED_BLACK } RBColor; // 节点颜色

template<typename  T> struct BinNode;
template <typename T> using BinNodePosi = BinNode<T>*;  // 节点位置
// 二叉树节点模板类
template<typename T> struct BinNode {
// 成员，为简化描述统一开放（public）
T data;
BinNodePosi<T>  parent; // 父节点
BinNodePosi<T>  lChild; // 左孩子
BinNodePosi<T>  rChild; // 右孩子
int height;
int npl;    // Null Path Length（左式堆，也可以直接用height代替）
RBColor color;  // 颜色（红黑树）

// 构造函数
BinNode(): parent(nullptr), lChild(nullptr), rChild(nullptr), height(0), npl(1), color(RB_RED) {}
BinNode(T e, BinNodePosi<T> p = nullptr, BinNodePosi<T> lc = nullptr, BinNodePosi<T> rc = nullptr, 
                int h = 0, int l = 1, RBColor c = RB_RED)
                : data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) 
                {
                    if(lc)  lc->parent = this;
                    if(rc)  rc->parent = this;
                }

// 操作接口
Rank size(); // 当前节点后代节点的总数
Rank updateHeight();    // 更新当前节点高度
Rank updateHeightAbove();   // 更新当前节点及其祖先的高度
BinNodePosi<T>  insertLc(T const&);   // 作为当前节点的左孩子插入新节点
BinNodePosi<T>  insertRc(T const&);   // 作为当前节点的右孩子插入新节点
void attachLc(BinNodePosi<T>);  // 接入左子树
void attachRc(BinNodePosi<T>);  // 接入右子树
BinNodePosi<T>  succ(); // 取当前节点的直接后继
template<typename VST> void travLevel(VST&);    // 子树层次遍历
template<typename VST> void travPre(VST&);    // 子树先序遍历
template<typename VST> void travIn(VST&);    // 子树中序遍历
template<typename VST> void travPost(VST&);    // 子树后序遍历
/*DSA*/ template<typename  VST> void traverse(VST&);    // 自定义遍历
// 比较器、判等器
bool operator<(BinNode const& bn) { return data < bn.data; }
bool operator==(BinNode const& bn) { return data == bn.data; }

/*DSA*/
/*DSA*/BinNodePosi<T> zig(); //顺时针旋转
/*DSA*/BinNodePosi<T> zag(); //逆时针旋转
/*DSA*/BinNodePosi<T> balance(); //完全平衡化
/*DSA*/BinNodePosi<T> imitate( const BinNodePosi<T> ); //临摹

};

#include "BinNode_implementation.h"