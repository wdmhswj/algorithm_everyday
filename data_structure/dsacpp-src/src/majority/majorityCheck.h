/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> bool majCheck ( Vector<T> A, T maj ) { //验证候选者是否确为众数
   Rank occurrence = 0; //maj在A[]中出现的次数
   for ( Rank i = 0; i < A.size(); i++ ) //逐一遍历A[]的各个元素
      if ( A[i] == maj ) occurrence++; //每遇到一次maj，均更新计数器
   /*DSA*/printf ( "%d found with %d/%d occurrence(s)\n", maj, occurrence, A.size() );
   return 2 * occurrence > A.size(); //根据最终的计数值，即可判断是否的确当选
}