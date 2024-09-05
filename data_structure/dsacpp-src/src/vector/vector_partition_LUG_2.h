/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //ͨ������Ԫ��λ�ã����������[lo, hi)�ڵ�һ�����
Rank Vector<T>::partition( Rank lo, Rank hi ) { // LUG�棺������ʽ
   swap( _elem[lo], _elem[lo + rand() % ( hi - lo )] ); //��ѡһ��Ԫ������Ԫ�ؽ���
   T pivot = _elem[lo]; hi--; //�����Ͻ�������Ч�����ѡȡ��ѡ���
   while ( 1 ) { //�����˽���ɨ�裬ֱ������
      while ( ( lo < hi ) && ( pivot <= _elem[hi] ) ) hi--; //������չ��׺G
      if ( lo == hi ) break; _elem[lo++] = _elem[hi]; //�赲�߹���ǰ׺L
      while ( ( lo < hi ) && ( _elem[lo] <= pivot ) ) lo++; //������չǰ׺L
      if ( lo == hi ) break; _elem[hi--] = _elem[lo]; //�赲�߹����׺G
   } //assert: quit with lo == hi or hi + 1
   _elem[hi] = pivot; //��ѡ�������ǰ׺����׺֮�䣬����������ʵ
   return hi; //����������
}
