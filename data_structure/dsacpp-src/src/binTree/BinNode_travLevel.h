/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "queue/queue.h" //引入队列
template <typename T> template <typename VST> //元素类型、操作器
void BinNode <T>::travLevel( VST& visit ) { //二叉树层次遍历算法
   Queue<BinNodePosi<T>> Q; Q.enqueue( this ); //引入辅助队列，根节点入队
   while ( !Q.empty() ) { //在队列再次变空之前，反复迭代
      BinNodePosi<T> x = Q.dequeue(); visit( x->data ); //取出队首节点并访问之
      if ( x->lc ) Q.enqueue( x->lc ); //左孩子入队
      if ( x->rc ) Q.enqueue( x->rc ); //右孩子入队
   }
}