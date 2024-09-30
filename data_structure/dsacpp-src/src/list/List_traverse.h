/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::traverse( void ( *visit )( T& ) ) //��������ָ����Ʊ���
{  for ( ListNodePosi<T> p = head->succ; p != tail; p = p->succ ) visit ( p->data );  }

template <typename T> template <typename VST> //Ԫ�����͡�������
void List<T>::traverse( VST& visit ) //��������������Ʊ���
{  for ( ListNodePosi<T> p = head->succ; p != tail; p = p->succ ) visit ( p->data );  }