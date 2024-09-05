/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ_test.h"

struct visit { virtual void operator()( HuffChar & e ) { printf( "%8d", e.weight ); } };

/******************************************************************************************
 * ���۱���ɭ�����б���ȫ�ѻ�����ʽ��ʵ�֣������Թ��̶�������
 * ����ɭ�ֵ�ʵ�ַ�ʽ�������ȼ�����ʱ������ǰ��Ӧ�Ĺ���ֻ��������Ӧ��־��
 *    DSA_PQ_List��DSA_PQ_ComplHeap��DSA_PQ_LeftHeap
 ******************************************************************************************/
int main ( int argc, char* argv[] ) { //Huffman�����㷨ͳһ����
   /*DSA*/if ( 3 > argc ) { printf ( "Usage: %s <sample-text-file> <message#1> [message#2] ...\a\n", argv[0] ); return -1; }
   unsigned int * freq = stat ( argv[1] ); //���������ļ���ͳ�Ƹ��ַ��ĳ���Ƶ��
   HuffForest* forest = initForest ( freq ); delete freq; //����Huffmanɭ��
   HuffTree tree = generateTree( forest ); delete forest; print( tree ); //����Huffman������
   tree.travLevel( visit() ); printf("\n\n"); //��֤����α��������У����ڵ��Ȩ�ص�������
   HuffTable* table = generateTable ( tree ); //��Huffman������ת��Ϊ�����
   for ( int i = 0; i < N_CHAR; i++ ) //��������
      printf ( " %c: %s\n", i + 0x20, * ( table->get ( i + 0x20 ) ) );
   for ( int i = 2; i < argc; i++ ) { //���������д����ÿһ���Ĵ�
      /*DSA*/printf ( "\nEncoding: %s\n", argv[i] ); //���²��Ա���
      Bitmap codeString; //�����Ʊ��봮
      int n = encode ( table, &codeString, argv[i] ); //�����ݱ�������ɣ�����Ϊn��
      /*DSA*/printf ( "%s\n", codeString.bits2string ( n ) ); //����ñ��봮
      /*DSA*/printf ( "Decoding: " ); //���²��Խ���
      decode( tree, &codeString, n ); //����Huffman���������Գ���Ϊn�Ķ����Ʊ��봮����
   }
   delete table; return 0; //�ͷű����������
}