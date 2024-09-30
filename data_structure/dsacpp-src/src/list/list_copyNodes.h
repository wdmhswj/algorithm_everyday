/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //�б��ڲ������������б�����λ��p���n��
void List<T>::copyNodes( ListNodePosi<T> p, Rank n ) { // p�Ϸ�����������n-1������
   init(); //����ͷ��β�ڱ��ڵ㲢����ʼ��
   while ( n-- ) { insertLast( p->data ); p = p->succ; } //������p��n��������Ϊĩ�ڵ����
}