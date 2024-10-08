/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "_share/util.h"
/*DSA*/#include "random/shuffle.h"
/*DSA*/#include "UniPrint/print_int_array.h"

/*DSA*/void bubblesort ( int A[], int n ); //algorithm#0
/*DSA*/void bubblesort1A ( int A[], int n ); //algorithm#1A
/*DSA*/void bubblesort1B ( int A[], int n ); //algorithm#1B
/*DSA*/void bubblesort2 ( int A[], int n ); //algorithm#2

/******************************************************************************************
 * 构造随机数组（可根据测试需要相应地改写）
 ******************************************************************************************/
void randomArray ( int A[], int n, int seed ) {
   srand(seed);
   for (int i = 0; i < n; i++) A[i] = i;
   shuffle(A, n);
}

/******************************************************************************************
 * 起泡排序测试程序
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   int n = atoi ( argv[1] ); if ( n < 0 ) n = 0; //make sure length is non-negative
   int* A = new int[ n ]; //allocate an array of size n
   unsigned int seed = ( unsigned int ) time ( NULL ); //A same seed is used here to compare different algorithms
   printf ( "\n== Bubblesort algorithm #0 ========\n" );
   randomArray ( A, n, seed ); //create a randomized array using the same seed
   printf ( "-->  " ); print ( A, n );
   bubblesort ( A, n ); //sort the array using algorithm#0
   printf ( "==>  " ); print ( A, n );
   printf ( "\n== Bubblesort algorithm #1A ========\n" );
   randomArray ( A, n, seed ); //create a randomized array using the same seed
   printf ( "-->  " ); print ( A, n );
   bubblesort1A ( A, n ); //sort the array using algorithm#1A
   printf ( "==>  " ); print ( A, n );
   printf ( "\n== Bubblesort algorithm #1B ========\n" );
   randomArray ( A, n, seed ); //create a randomized array using the same seed
   printf ( "-->  " ); print ( A, n );
   bubblesort1B ( A, n ); //sort the array using algorithm#1B
   printf ( "==>  " ); print ( A, n );
   printf ( "\n== Bubblesort algorithm #2 ========\n" );
   randomArray ( A, n, seed ); //create a randomized array using the same seed
   printf ( "-->  " ); print ( A, n );
   bubblesort2 ( A, n ); //sort the array using algorithm#2
   printf ( "==>  " ); print ( A, n );
   delete [] A;
   return 0;
}