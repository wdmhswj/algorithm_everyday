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
   for ( ListNodePosi<T> p = head; p; p = p->pred ) //��ǰ�������
      swap( p->pred, p->succ ); //�������ڵ��ǰ�������ָ��
   swap( head, tail ); //ͷ��β�ڵ㻥��
}