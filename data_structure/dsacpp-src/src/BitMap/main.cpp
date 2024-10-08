/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma warning(disable : 4996 4800)
#include "_share/util.h"
//#include "Bitmap_O1_init.h"
#include "Bitmap.h"

/******************************************************************************************
 * 测试位图
 ******************************************************************************************/
int testBitmap( int n, int t ) {
   bool* B = new bool[n]; //常规位图
   Bitmap M ( n ); //高效位图
   while ( t-- > 0 ) { //重复使用位图多次
      memset ( B, 0, n * sizeof ( bool ) ); //逐位清零，O(n)
      M.reset(); //逻辑清零，O(1)
      for ( int i = 0; i < 3 * n; i++ ) { //反复地
         Rank k = dice ( n ); //在随机位置上
         if ( dice ( 2 ) ) { //以50%的概率插入
            B[k] = true; M.set ( k );
         } else { //或50%的概率清除
            B[k] = false; M.clear ( k );
         }
      }
      //M.set( 29 ); //有时可卖个破绽，以反向测试本测试程序
      int sz = 0; for ( int j = 0; j < n; j++ ) sz += B[j];
      printf( "\nM[] x %d %s %d\n", M.size(), ( M.size() == sz ? "==" : "<>" ), sz );
      for ( int j = 0; j < n; j++ ) printf ( "%c", M.test ( j ) ? 'x' : '.' );
      int k = 0;
      while ( k++ < n ) //逐位地对比
         if ( B[k] != M.test ( k ) ) //一旦发现不合
            break; //随即退出
      if ( k < n ) { //并报告（assert:: k == n+1）
         printf ( "\n B[]\n" );
         for ( int j = 0; j <= k; j++ ) printf ( "%c", B[j] ? 'x' : '.' );
         printf ( "\n M[] x %d\n", M.size() );
         for ( int j = 0; j <= k; j++ ) printf ( "%c", M.test ( j ) ? 'x' : '.' );
         printf ( "\n" );
      } else
         printf( "\nTest %4d OK\n", t );
   }
   delete [] B;
   return 0;
}

/******************************************************************************************
 * 测试位图
 ******************************************************************************************/
int main( int argc, char* argv[] ) {
   if ( 3 > argc ) { printf ( "Usage: %s <bitmap size> <#test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   return testBitmap( max(0, atoi(argv[1])), max(0, atoi(argv[2]))); //启动测试
}