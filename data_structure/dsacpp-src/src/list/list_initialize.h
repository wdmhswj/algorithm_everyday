/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::init() { //列表初始化，在创建列表对象时统一调用
   head = new ListNode<T>; tail = new ListNode<T>; //创建头、尾哨兵节点
   head->succ = tail; head->pred = NULL; //向前链接
   tail->pred = head; tail->succ = NULL; //向后链接
   _size = 0; //记录规模
}