/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Skiplist<K, V>::put( K k, V v ) { //��ת�����������㷨
   Entry<K, V> e = Entry<K, V>( k, v ); //������Ĵ���������ͬһ�������нڵ㹲�ã�
   QNodePosi< Entry<K, V> > p = search( k ); //���Ҳ���λ�ã��������������ң��������
   ListNodePosi< Quadlist< Entry<K, V> >* > qlist = last(); //��������ײ�
   QNodePosi< Entry<K, V> > b = qlist->data->insert( e, p ); //���������Ļ���
   while ( rand() & 1 ) { //��Ͷ��Ӳ�ң���ȷ��������Ҫ�ٳ��ߣ���
      while ( p->pred && !p->above ) p = p->pred; //�ҳ������ڴ˸߶ȵ����ǰ��
      if ( !p->pred && !p->above ) { //����ǰ����head����������㣬��
         insertFirst( new Quadlist< Entry<K, V> > ); //��Ҫ�����µ�һ��
         first()->data->head->below = qlist->data->head;
         qlist->data->head->above = first()->data->head;
      }
      p = p->above; qlist = qlist->pred; //����һ�㣬���ڸò�
      b = qlist->data->insert( e, p, b ); //���½ڵ����p֮��b֮��
   } //�κ󣺵�������������۲������ߵ���Ӧ�仯
   return true; //Dictionary����Ԫ����ȣ�����سɹ�
} //��᣺�������ڱ������ã���Щ���ڱ����ˣ�