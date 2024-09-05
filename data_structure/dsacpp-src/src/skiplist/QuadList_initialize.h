/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> void Quadlist<T>::init() { //Quadlist��ʼ��������Quadlist����ʱͳһ����
   head = new QNode<T>; //����ͷ�ڱ��ڵ�
   tail = new QNode<T>; //����β�ڱ��ڵ�
   head->succ = tail; head->pred = NULL; //�غ��������ڱ�
   tail->pred = head; tail->succ = NULL; //�غ��������ڱ�
   head->above = tail->above = NULL; //����ĺ���ÿ�
   head->below = tail->below = NULL; //�����ǰ���ÿ�
   _size = 0; //��¼��ģ
} //��˹���������������κ�ʵ�ʵĽڵ㣬����ʱ�������������໥����