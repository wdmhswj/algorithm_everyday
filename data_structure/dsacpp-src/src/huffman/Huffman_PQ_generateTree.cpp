/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

// forest�������ȼ�����ʵ�֣����㷨�����ڷ���PQ�ӿڵ��κ�ʵ�ַ�ʽ
// ΪHuffman_PQ_List��Huffman_PQ_ComplHeap��Huffman_PQ_LeftHeap����
// ����ǰ��Ӧ����ֻ��������Ӧ�ı�־��DSA_PQ_List��DSA_PQ_ComplHeap��DSA_PQ_LeftHeap
HuffTree generateTree( HuffForest* forest ) { //��Huffmanɭ�֣������Huffman������
   while ( 1 < forest->size() ) { //ÿ����һ����ɭ���ж������һ����
      HuffTree T1 = forest->delMax(), T2 = forest->delMax(); //ȡ��Ȩ����С��������
      /*DSA*/printf( "Merging " ); print( T1.root()->data ); printf( " with " ); print( T2.root()->data ); printf( " ...\n" );
      HuffTree S; //����ϲ���һ������
      S.insert( HuffChar ( '^', T1.root()->data.weight + T2.root()->data.weight ) );
      S.attach( T2, S.root() ); S.attach( S.root(), T1 ); //T2Ȩ�ز�С��T1
      forest->insert( S ); //�ٲ����ɭ��
   } //ɭ��������Ψһ��ʣ���ǿ�������Huffman�������������α������б�Ȼ����������
   return forest->delMax(); //�ʷ���֮
}