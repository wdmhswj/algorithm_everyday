/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //��e������[r]
Rank Vector<T>::insert ( Rank r, T const & e ) { //0 <= r <= size
   //print( e );
   expand(); //���Ҫ��������
   for ( Rank i = _size; r < i; i-- ) //�Ժ���ǰ�����Ԫ��
      _elem[i] = _elem[i-1]; //˳�κ���һ����Ԫ
   _elem[r] = e; _size++; //������Ԫ�ز���������
   return r; //������
}