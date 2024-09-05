/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

extern int s_lo, s_hi;

int gs_IC( int A[], int n ) { //�������ԣ�O(n^2)
   int gs = A[0]; s_lo = 0; s_hi = 1;
   for ( int lo = 0; lo < n; lo++ ) { //ö��������ʼ��lo
      for ( int s = 0, hi = lo; hi < n; ) { //��ֹ��hi������
         s += A[hi++]; //�����صõ����ܺͣ�O(1)
         if ( gs < s )
            { gs = s; s_lo = lo; s_hi = hi; } //���š�����
      }
   }
   return gs;
}
