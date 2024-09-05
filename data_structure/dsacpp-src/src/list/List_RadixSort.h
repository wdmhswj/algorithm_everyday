/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

using U = unsigned int; //Լ��������T�����U�����ת��ΪU�������˶���

template <typename T> //���б�����ʼ��λ��p�����Ϊn����������������
void List<T>::radixSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*///printf ( "RadixSort ...\n" );
   ListNodePosi<T> h = p->pred; //����������Ϊ(h, t)
   ListNodePosi<T> t = p; for ( Rank i = 0; i < n; i++ ) t = t->succ;
   for ( U radixBit = 0x1; radixBit && (p = h); radixBit <<= 1 ) //���·�����
      for ( Rank i = 0; i < n; i++ ) //���ݵ�ǰ����λ�������нڵ�
         radixBit & U (p->succ->data) ? //�ּ�Ϊ��׺��1����ǰ׺��0��
            insert( remove( p->succ ), t ) : p = p->succ;
} //Ϊ���ⷴ��remove()��insert()��������List::move(p,t)�ӿڣ����ڵ�pֱ������t֮ǰ
