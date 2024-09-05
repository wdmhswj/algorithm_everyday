/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::reverse() { //ǰ����
   if ( _size < 2 ) return; //ƽ�����
   ListNodePosi<T> p, q;
   for ( p = head, q = p->succ; p != tail; p = q, q = p->succ )
      p->pred = q; //��ǰ������εߵ����ڵ��ǰ��ָ��
   tail->pred = NULL; //��������β�ڵ��ǰ��ָ��
   for ( p = head, q = p->pred; p != tail; p = q, q = p->pred )
      q->succ = p; //��ǰ������εߵ����ڵ�ĺ��ָ��
   head->succ = NULL; //��������ͷ�ڵ�ĺ��ָ��
   swap( head, tail ); //ͷ��β�ڵ㻥��
}