/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> Rank quickSelect( T const * A, Rank n, Rank k ) { //���ڿ��ٻ��ֵ�kѡȡ�㷨
   Vector<Rank> R(n); for ( Rank i = 0; i < n; i++ ) R.insert(i); //ʹ����������������ԭ���еĴ���
   for ( Rank lo = 0, hi = n; ; ) { //������quickParititon
      swap( R[lo], R[lo + rand()%(hi-lo)] ); T pivot = A[R[lo]]; Rank mi = lo; //�󵨲²�
      for ( Rank i = lo+1; i < hi; i++ ) //LGU��partition�㷨
         if ( A[R[i]] < pivot )
            swap( R[++mi], R[i] );
      swap( R[lo], R[mi] ); //[0,mi) < [mi] <= (mi, n)
      if ( mi < k ) lo = mi + 1; //��С�ˣ������ǰ׺
      else if ( k < mi ) hi = mi; //�´��ˣ��������׺
      else return R[mi]; //�����٣����ܲ���
      //*DSA*/ printf( "%d ~ %d ~ %d : %d\n", lo, k, hi, mi );
      //*DSA*/ for ( Rank i =  0; i < lo; i++ ) printf ( "   x" ); printf("\n");
      //*DSA*/ for ( Rank i =  0; i < lo; i++ ) printf ( "    " );
      //*DSA*/ for ( Rank i = lo; i < hi; i++ ) printf ( "%4d", A[R[i]] ); printf("\n");
      //*DSA*/ for ( Rank i =  0; i < hi; i++ ) printf ( "    " ); if (hi < n) printf("%4d", A[R[hi]]);
      //*DSA*/ for ( Rank i = hi+1; i <  n; i++ ) printf ( "   x" ); printf ( "\n\n\n" );
   }
}
