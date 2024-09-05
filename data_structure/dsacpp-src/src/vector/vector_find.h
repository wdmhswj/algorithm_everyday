/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //������������˳�����e��0 <= lo < hi <= _size
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const { //O(hi-lo)
   while ( ( lo < hi-- ) && ( e != _elem[hi] ) ); //�Ӻ���ǰ��˳�����
   return hi; //���������ߣ���lo-1ʾ��ʧ�ܣ�lo == 0ʱ�أ���
}
