/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include <cstdio>
#include <cstring>
/*DSA*/void showProgress ( char*, char*, int, int );

/******************************************************************************************
 * Text     :  0   1   2   .   .   .   i-j .   .   .   .   i   .   .   n-1
 *             ------------------------|-------------------|------------
 * Pattern  :                          0   .   .   .   .   j   .   .
 *                                     |-------------------|
 ******************************************************************************************/
int match ( char* P, char* T ) { //��ƥ���㷨��Brute-force-1��
   int n = strlen ( T ), i = 0; //�ı������ȡ���ǰ���ܱȶ��ַ���λ��
   int m = strlen ( P ), j = 0; //ģʽ�����ȡ���ǰ���ܱȶ��ַ���λ��
   while ( (j < m) && (i < n) ) //������������ȶ��ַ�
      /*DSA*/{ showProgress ( T, P, i - j, j );
      if ( T[i] == P[j] ) //��ƥ��
         { i ++;  j ++; } //��ת����һ���ַ�
      else //����
         { i -= j - 1; j = 0; } //�ı������ˡ�ģʽ����λ
      /*DSA*/}
   return i - j; //���ͨ������ֵ���ж�ƥ������
}