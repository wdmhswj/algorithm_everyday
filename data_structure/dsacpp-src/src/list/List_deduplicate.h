/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> Rank List<T>::dedup() {
   Rank oldSize = _size; ListNodePosi<T> p = first();
   for ( Rank r = 0; p != tail; p = p->succ ) //O(n)
      if ( ListNodePosi<T> q = find(p->data, r, p) )
         remove(q); //此时q与p相等，但删除前者更为简明
      else r++; //r为无重前缀的长度
   return oldSize - _size; //删除元素总数
}