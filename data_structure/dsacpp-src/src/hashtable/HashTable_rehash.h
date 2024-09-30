/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * ��ɢ�У���Ͱ̫��ʱ��ɢ�б��������������ݣ��ٽ�������һ�����±�
 * ɢ�к����Ķ�ַ�����Mֱ����أ��ʲ��ɼ򵥵���������ԭͰ����
 ******************************************************************************************/
template <typename K, typename V> void Hashtable<K, V>::rehash() {
   Rank oldM = M; Entry<K, V>** oldHt = ht;
   M = primeNLT( 4 * N, 1048576, PRIME_TABLE ); //�������ټӱ���������ɾ���ܶ࣬���ܷ������ݣ�
   ht = new Entry<K, V>*[M]; N = 0; memset( ht, 0, sizeof( Entry<K, V>* ) * M ); //Ͱ����
   delete removed; removed = new Bitmap( M ); //����ɾ�����
   /*DSA*///printf("A bucket array has been created with capacity = %d\n\n", M);
   for ( Rank i = 0; i < oldM; i++ ) //ɨ��ԭ��
      if ( oldHt[i] ) //��ÿ���ǿ�Ͱ�еĴ���
         put( oldHt[i]->key, oldHt[i]->value ); //ת���±�
   delete[] oldHt; //�ͷš��������д�������ת�ƣ���ֻ���ͷ�Ͱ���鱾��
}