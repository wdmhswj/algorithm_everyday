/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "huffman_PQ.h"

HuffTree delMax( HuffForest* forest ) { //��Huffmanɭ���У��ҳ����ȼ���ߣ�Ȩ����С������
   ListNodePosi<HuffTree> m = forest->first(); //���׽ڵ����
   for ( ListNodePosi<HuffTree> p = m->succ; forest->valid( p ); p = p->succ ) //�������нڵ�
      if ( m->data < p->data ) //���ϸ��£����Ѷ���Ƚ��������ܼ�ݣ�
         m = p; //���ȼ����ߣ�Ȩ�ظ�С����
   return forest->remove( m ); //ȡ������߲�����
} //O(n)���������ȼ����к������O(logn)

HuffTree generateTree( HuffForest* forest ) { //��Huffmanɭ�֣������Huffman������
   while ( 1 < forest->size() ) { //ÿ����һ����ɭ���ж������һ����
      HuffTree T1 = delMax( forest ), T2 = delMax( forest ); //ȡ��Ȩ����С��������
      /*DSA*/printf( "Merging " ); print( T1.root()->data ); printf( " with " ); print( T2.root()->data ); printf( " ...\n" );
      HuffTree S; //����ϲ���һ������
      S.insert( HuffChar ( '^', T1.root()->data.weight + T2.root()->data.weight ) );
      S.attach( T2, S.root() ); S.attach( S.root(), T1 ); //T2Ȩ�ز�С��T1
      forest->insertLast( S ); //�ٲ����ɭ��
   } //ɭ��������Ψһ��ʣ���ǿ�������Huffman�������������α������б�Ȼ����������
   return forest->first()->data; //�ʷ���֮
}