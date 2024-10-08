/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //重载下标操作符，以通过秩直接访问列表节点（O(r)效率，虽方便，勿多用）
ListNodePosi<T> List<T>::operator[]( Rank r ) const { // 0 <= r < size
   ListNodePosi<T> p = first(); //从首节点出发
   while ( 0 < r-- ) p = p->succ; //顺数第r个节点即是
   return p; //目标节点
}
