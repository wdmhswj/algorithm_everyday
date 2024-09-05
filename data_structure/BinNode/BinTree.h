#pragma once

#include "BinNode.h"  // 引入二叉树节点类

template <typename T> class BinTree {   // 二叉树模板类
protected:
    Rank _size; // 规模
    BinNodePosi<T> _root;   // 根节点
public:
    BinTree(): _size(0), _root(nullptr) {}  // 构造函数
    ~BinTree(){ if(_size>0) remove(_root); }    // 析构函数
    Rank size() const { return _size; } // 规模
    bool empty() const { return !_root; }   // 判空
    BinNodePosi<T> root() const { return _root; }
    BinNodePosi<T> insertAsRoot(T const&);    // 插入根节点
    BinNodePosi<T> insertAsLc(T const& e, BinNodePosi<T> x);    // e作为x的左孩子（原无）插入
    BinNodePosi<T> insertAsRc(T const& e, BinNodePosi<T> x);    // e作为x的右孩子（原无）插入
    BinNodePosi<T> attachAsLc(BinTree<T> eT, BinNodePosi<T> ex);    // eT作为ex的左子树接入
    BinNodePosi<T> attachAsRc(BinTree<T> eT, BinNodePosi<T> ex);    // eT作为ex的右子树接入
    Rank remove(BinNodePosi<T>);    // 子树删除
    BinTree<T>* secede(BinNodePosi<T>); // 子树分离，作为独立子树返回
    template<typename VST>  // 操作器
    void travLevel(VST& visit) { if(_root) _root->travLevel(visit); }   // 层次遍历
    template<typename VST>  // 操作器
    void travPre(VST& visit) { if(_root) _root->travPre(visit); }   // 层次遍历
    template<typename VST>  // 操作器
    void travIn(VST& visit) { if(_root) _root->travIn(visit); }   // 层次遍历
    template<typename VST>  // 操作器
    void travPost(VST& visit) { if(_root) _root->travPost(visit); }   // 层次遍历
    /*DSA*/template<typename VST>   // 操作器
    /*DSA*/void traverse(VST&); // 自定义遍历
    bool operator<(const BinTree<T>& t )
    { return _root && t._root && (*_root<*(t._root)); }
    bool operator==(const BinTree<T>& t )
    { return _root && t._root && (*_root==*(t._root)); }
};