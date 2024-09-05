/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#include "sum/sum.h"
extern int s_lo, s_hi;

int gs_BF( int A[], int n ) { //�������ԣ�O(n^3)
   int gs = A[0]; s_lo = 0; s_hi = 1;
   for ( int lo = 0; lo < n; lo++ ) //ö�����е�
      for ( int hi = lo; hi < n; ) { //O(n^2)������
         int s = sum(A, lo, ++hi); //��O(n)ʱ����ͣ�����sum(A+lo,++hi-lo)�ռ�Ч�ʸ��ߣ�
         if ( gs < s )
            { gs = s; s_lo = lo; s_hi = hi; } //���š�����
      }
   return gs;
}
