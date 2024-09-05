/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * RedBlack˫������㷨������ڵ�x���丸��Ϊ��ɫ�����⡣��Ϊ�����������
 *    RR-1��2����ɫ��ת��2�κڸ߶ȸ��£�1~2����ת�����ٵݹ�
 *    RR-2��3����ɫ��ת��3�κڸ߶ȸ��£�0����ת����Ҫ�ݹ�
 ******************************************************************************************/
template <typename T> void RedBlack<T>::solveDoubleRed( BinNodePosi<T> x ) { //x��ǰ��Ϊ��
   while ( 1 ) {
      if ( !x->parent ) //���ѣ��ݹ飩ת������������ת�ڣ������ڸ߶�Ҳ��֮����
         {  x->color = RB_BLACK; x->height++; return;  } //����x�ĸ���p�ش���
      BinNodePosi<T> p = x->parent; if ( IsBlack( p ) ) return; //��pΪ�ڣ������ֹ����
      BinNodePosi<T> g = p->parent; //����x���游�ش�����Ϊ��
      BinNodePosi<T> u = uncle( x ); //���£���x�常����ɫ�ֱ���
      if ( IsBlack( u ) ) { // uΪ��ɫ����NULL��ʱ /*DSA*///printf("  case RR-1:\n");
      // ��x��pͬ�࣬��p�ɺ�ת�ڣ�x���ֺ죩����x��p��࣬��x�ɺ�ת�ڣ�p���ֺ죩
         ( IsLChild( x ) == IsLChild( p ) ? p : x )->color = RB_BLACK;
      // g�ɺ�ת�첢��x��ת�󣬼�����޸�
         g->color = RB_RED; rotateAt( x ); return;
      } else { //��uΪ��ɫ /*DSA*///printf("  case RR-2:\n");
         p->color = RB_BLACK; p->height++; //p�ɺ�ת��
         u->color = RB_BLACK; u->height++; //u�ɺ�ת��
         g->color = RB_RED; //��B-����g�൱���Ͻ������ڵ�Ĺؼ��룬���ݱ��Ϊ��
         x = g; //��������
      }
   } //while
}
