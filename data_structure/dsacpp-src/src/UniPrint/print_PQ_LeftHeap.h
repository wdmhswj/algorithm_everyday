/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 打印输出PQ_LeftHeap
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p ( PQ_LeftHeap<T> & lh ) { //引用
   p ( ( BinTree<T>& ) lh );
}