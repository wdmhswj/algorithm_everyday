/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> Rank List<T>::clear() { //清空列表
   Rank oldSize = _size;
   while ( 0 < _size ) remove ( head->succ ); //反复删除首节点，直至列表变空
   return oldSize;
}