/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> AVL<T>::insert( const T& e ) { //���ؼ���e����AVL����
   BinNodePosi<T>& x = search( e ); if ( x ) return x; //����ʧ��
   BinNodePosi<T> xx = x = new BinNode<T>( e, _hot ); _size++; //�����½ڵ�x
// ��ʱ��x�ĸ���_hot�����ߣ������游�п���ʧ��
   for ( BinNodePosi<T> g = _hot; g; g->updateHeight(), g = g->parent ) //�������
      if ( !AvlBalanced( g ) ) { //һ������ʧ������g����
         rotateAt( tallerChild( tallerChild( g ) ) ); //�����á�3+4���㷨��ʹ֮����
         break; //���漴��ֹ���ֲ���������󣬸߶ȱ�Ȼ��ԭ������������ظ��⣩
      }
   return xx; //����ɹ�
} //�������O(1)�ε���
