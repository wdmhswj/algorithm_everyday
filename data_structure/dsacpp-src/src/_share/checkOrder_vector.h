/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include "vector/vector.h"

template <typename T> void checkOrder ( Vector<T> & V ) { //判断向量是否整体有序
   int unsorted = 0; //逆序计数器
   V.traverse ( CheckOrder<T> ( unsorted, V[0] ) ); //进行遍历
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent inversion(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
}
