/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> ListNodePosi<T> List<T>::insertFirst( T const& e )
   { _size++; return head->insertSucc( e ); } // e�����׽ڵ����

template <typename T> ListNodePosi<T> List<T>::insertLast( T const& e )
   { _size++; return tail->insertPred( e ); } // e����ĩ�ڵ����

template <typename T> ListNodePosi<T> List<T>::insert( ListNodePosi<T> p, T const& e )
   { _size++; return p->insertSucc( e ); } // e����p�ĺ�̲���

template <typename T> ListNodePosi<T> List<T>::insert( T const& e, ListNodePosi<T> p )
   { _size++; return p->insertPred( e ); } // e����p��ǰ������
