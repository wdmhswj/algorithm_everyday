/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> // S1[lo1, lo1 + n)和S2[lo2, lo2 + n)分别有序，n > 0，数据项可能重复
T median( Vector<T>& S1, Rank lo1, Vector<T>& S2, Rank lo2, Rank n ) { //中位数算法（高效版）
   /*DSA*/printf ( "median\n" );
   /*DSA*/for ( Rank i = 0; i < lo1; i++ ) printf ( "    ." ); for ( Rank i = 0; i < n; i++ ) print ( S1[lo1+i] ); for ( Rank i = lo1 + n; i < S1.size(); i++ ) printf ( "    ." ); printf ( "\n" );
   /*DSA*/for ( Rank i = 0; i < lo2; i++ ) printf ( "    ." ); for ( Rank i = 0; i < n; i++ ) print ( S2[lo2+i] ); for ( Rank i = lo2 + n; i < S2.size(); i++ ) printf ( "    ." ); printf ( "\n--\n" );
   if ( n < 3 ) return trivialMedian( S1, lo1, n, S2, lo2, n ); //递归基
   Rank mi1 = lo1 + n / 2, mi2 = lo2 + ( n - 1 ) / 2; //长度（接近）减半
   if ( S1[mi1] < S2[mi2] )
      return median ( S1, mi1, S2, lo2, n + lo1 - mi1 ); //取S1右半、S2左半
   else if ( S1[mi1] > S2[mi2] )
      return median ( S1, lo1, S2, mi2, n + lo2 - mi2 ); //取S1左半、S2右半
   else
      return S1[mi1];
}