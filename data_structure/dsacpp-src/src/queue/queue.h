/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include "List/List.h" //��ListΪ������������
template <typename T> class Queue: public List<T> { //����ģ����
public: //ԭ�нӿ�һ������
   void enqueue( T const& e ) { insertLast( e ); } //��ӣ�β������
   T dequeue() { return remove( first() ); } //���ӣ��ײ�ɾ��
   T& front() { return first()->data; } //����
};

#include "queue_implementation.h"