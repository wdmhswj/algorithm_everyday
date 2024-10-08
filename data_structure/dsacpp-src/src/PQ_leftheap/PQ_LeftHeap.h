/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include "BinTree/BinTree.h" //引入二叉树节点模板类
#include "PQ/PQ.h" //引入优先级队列ADT

template <typename T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T> { //基于二叉树，以左式堆形式实现的PQ
   /*DSA*/ friend class UniPrint; //演示输出使用，否则不必设置友类
 public:
   PQ_LeftHeap() {} //默认构造
   PQ_LeftHeap( T* E, int n ) //批量构造：可改进为Floyd建堆算法
    { for ( int i = 0; i < n; i++ ) insert( E[i] ); }
   PQ_LeftHeap( PQ_LeftHeap& A, PQ_LeftHeap& B ) { //合并构造
      _root = merge( A._root, B._root ); _size = A._size + B._size;
      A._root = B._root = NULL; A._size = B._size = 0;
   }
   void insert( T ); //按照比较器确定的优先级次序插入元素
   T delMax(); //删除优先级最高的元素
   T & getMax(); //取出优先级最高的元素
}; // PQ_LeftHeap

#include "PQ_LeftHeap_implementation.h"