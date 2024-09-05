/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once
using Rank = unsigned int; //��

template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*; //�б�ڵ�λ��
template <typename T> struct ListNode { //�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
// ��Ա
   T data; ListNodePosi<T> pred, succ; //��ֵ��ǰ�������
// ���췽��
   ListNode() {} //���head��tail�Ĺ���
   ListNode ( T const& e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL )
      : data( e ), pred( p ), succ( s ) {} //Ĭ�Ϲ���������T�붨�帴�Ʒ�����
// �����ӿ�
   ListNodePosi<T> insertPred( T const& e ); //������ǰ�ڵ�֮ǰ�����½ڵ�
   ListNodePosi<T> insertSucc( T const& e ); //���浱ǰ�ڵ�֮������½ڵ�
};

#include "listNode_implementation.h"
