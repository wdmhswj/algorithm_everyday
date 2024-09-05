/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> Hashtable<K, V>::~Hashtable() { //����ǰ�ͷ�Ͱ���鼰�ǿմ���
   for ( Rank i = 0; i < M; i++ ) //��һ����Ͱ
      if ( ht[i] ) delete ht[i]; //�ͷŷǿյ�Ͱ
   delete ht; //�ͷ�Ͱ����
   delete removed; //�ͷ�����ɾ�����
}
