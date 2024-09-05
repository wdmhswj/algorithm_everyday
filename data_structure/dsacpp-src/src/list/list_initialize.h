/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::init() { //�б��ʼ�����ڴ����б����ʱͳһ����
   head = new ListNode<T>; tail = new ListNode<T>; //����ͷ��β�ڱ��ڵ�
   head->succ = tail; head->pred = NULL; //��ǰ����
   tail->pred = head; tail->succ = NULL; //�������
   _size = 0; //��¼��ģ
}