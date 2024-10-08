/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //向量快速排序
void Vector<T>::quickSort( Rank lo, Rank hi ) { // 0 <= lo < hi <= size
   /*DSA*/ // printf ( "\tQUICKsort [%3d, %3d)\n", lo, hi );
   if ( hi - lo < 2 ) return; //单元素区间自然有序，否则...
   Rank mi = partition( lo, hi ); //在[lo, hi)内构造轴点
   quickSort( lo, mi ); quickSort( mi + 1, hi ); //前缀、后缀各自递归排序
}
