/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "string_pm/string_pm_test.h"

int match( char* P, char* T ) { //Boyer-Morre�㷨���򻯰棬ֻ����Bad Character Shift��
   int* bc = buildBC( P ); //Ԥ����
   int n = strlen( T ), i; //�ı������ȡ���ģʽ�����ַ��Ķ���λ��
   int m = strlen( P ), j; //ģʽ�����ȡ�ģʽ����ǰ�ַ�λ��
   for ( i = 0; i+m <= n; i += max(1, j - bc[ T[i+j] ]) ) { //��������P
      for ( j = m-1; (0 <= j) && (P[j] == T[i+j]); j-- ); //������������ȶ�
      /*DSA*/showProgress ( T, P, i, j );
      if ( j < 0 ) break; //һ����ȫƥ�䣬�漴�չ�
   }
   delete [] bc; return i; //����BC���������յĶ���λ��
}