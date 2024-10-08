/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "nest.h"

bool paren ( const char exp[], Rank lo, Rank hi ) { //����ʽ����ƥ���飬�ɼ����������
   Stack<char> S; //ʹ��ջ��¼�ѷ��ֵ���δƥ���������
   for ( Rank i = lo; i <= hi; i++ ) /* ��һ��鵱ǰ�ַ� */ /*DSA*/{
      switch ( exp[i] ) { //������ֱ�ӽ�ջ������������ջ��ʧ�䣬�����ʽ�ز�ƥ��
         case '(': case '[': case '{': S.push ( exp[i] ); break;
         case ')': if ( ( S.empty() ) || ( '(' != S.pop() ) ) return false; break;
         case ']': if ( ( S.empty() ) || ( '[' != S.pop() ) ) return false; break;
         case '}': if ( ( S.empty() ) || ( '{' != S.pop() ) ) return false; break;
         default: break; //�������ַ�һ�ɺ���
      /*DSA*/} displayProgress ( exp, i, S );
   }
   return S.empty(); //����ջ�գ����ҽ���ƥ��
}