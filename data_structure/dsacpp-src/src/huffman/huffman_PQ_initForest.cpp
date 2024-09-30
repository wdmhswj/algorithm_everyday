/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

/******************************************************************************************
 * ��ʼ��Huffmanɭ�֣����ݴ����Ƶ��ͳ�Ʊ�freq��Ϊÿ���ַ�����һ����
 ******************************************************************************************
 * forest�������ȼ�����ʵ�֣����㷨�����ڷ���PQ�ӿڵ��κ�ʵ�ַ�ʽ
 * ΪHuffman_PQ_List��Huffman_PQ_ComplHeap��Huffman_PQ_LeftHeap����
 * ����ǰ��Ӧ����ֻ��������Ӧ��־��DSA_PQ_List��DSA_PQ_ComplHeap��DSA_PQ_LeftHeap
 ******************************************************************************************/
HuffForest* initForest ( unsigned int * freq ) {
   HuffForest* forest = new HuffForest; //��PQʵ�ֵ�Huffmanɭ��
   for ( int i = 0; i < N_CHAR; i++ ) { //Ϊÿ���ַ�
      BinTree<HuffChar>* tree = new BinTree<HuffChar>(); //����һ�����������ַ���Ƶ��
      tree->insert ( HuffChar ( 0x20 + i, freq[i] ) ); //��������
      forest->insert ( *tree ); //�ٽ���������ɭ��
   }
   return forest;
}
/*DSA*///�κ�ʵ��PQ_ComplHeap��PQ_LeftHeap��Robert Floyd�㷨�������㷨��Ч�������O(n)