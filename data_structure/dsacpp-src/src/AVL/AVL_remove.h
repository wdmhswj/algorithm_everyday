/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> bool AVL<T>::remove( const T& e ) { //��AVL����ɾ���ؼ���e
   BinNodePosi<T>& x = search( e ); if ( !x ) return false; //ɾ��ʧ��
   removeAt( x, _hot ); _size--; //�Ȱ�BST����ɾ��֮���˺�ԭ�ڵ�֮��_hot�������Ⱦ�����ʧ�⣩
   for ( BinNodePosi<T> g = _hot; g; g->updateHeight(), g = g->parent ) //�������
      if ( !AvlBalanced( g ) ) //ÿ������ʧ������g����
         rotateAt( tallerChild( tallerChild( g ) ) ); //�����á�3+4���㷨��ʹ֮����
   return true; //ɾ���ɹ�
} //��������Omega(logn)�ε���
