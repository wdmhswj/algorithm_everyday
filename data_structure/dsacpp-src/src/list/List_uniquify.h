/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> Rank List<T>::uniquify() { //�����޳��ظ�Ԫ�أ�Ч�ʸ���
   if ( _size < 2 ) return 0; //ƽ���б�����Ȼ�������Ԫ��
   Rank oldSize = _size; //��¼ԭ��ģ
   ListNodePosi<T> p = first(); ListNodePosi<T> q; //pΪ��������㣬qΪ����
   while ( tail != ( q = p->succ ) ) //����������ڵĽڵ��(p, q)
      if ( p->data != q->data ) p = q; //�����죬��ת����һ����
      else remove( q ); //������ȣ�ֱ��ɾ�����ߣ�����������������ӵ����ɾ��
   return oldSize - _size; //�б���ģ�仯��������ɾ��Ԫ������
}