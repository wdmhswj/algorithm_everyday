/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //向量归并排序
void Vector<T>::mergeSort( Rank lo, Rank hi ) { // 0 <= lo < hi <= size
   /*DSA*/ // printf ( "\tMERGEsort [%3d, %3d)\n", lo , hi );
   if ( hi - lo < 2 ) return; //单元素区间自然有序，否则...
   Rank mi = ( lo + hi ) / 2; //以中点为界
   mergeSort( lo, mi ); mergeSort( mi, hi ); //前缀、后缀分别排序
   merge( lo, mi, hi ); //归并
}
