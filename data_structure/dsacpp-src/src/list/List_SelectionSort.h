/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //���б�����ʼ��λ��p�����Ϊn��������ѡ������
void List<T>::selectionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*///printf ( "SelectionSort ...\n" );
   ListNodePosi<T> h = p->pred; //����������Ϊ(h, t)
   ListNodePosi<T> t = p; for ( Rank i = 0; i < n; i++ ) t = t->succ;
   while ( 1 < n ) { //�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
      ListNodePosi<T> max = selectMax ( h->succ, n ); //�ҳ�����ߣ�����ʱ�������ȣ�
      insert( remove( max ), t ); //����������������ĩβ����Ϊ���������µ���Ԫ�أ�
      /*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
      t = t->pred; n--;
   }
}