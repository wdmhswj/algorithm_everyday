/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

/*DSA*/#include "Huffman_PQ.h"

static void generateCT //通过遍历获取各字符的编码
   ( Bitmap* code, int length, HuffTable* table, BinNodePosi <HuffChar> v ) {
   if ( IsLeaf ( v ) ) //若是叶节点（还有多种方法可以判断）
      {  table->put ( v->data.ch, code->bits2string ( length ) ); return;  }
   if ( v->lc ) //Left = 0
      { code->clear ( length ); generateCT ( code, length + 1, table, v->lc ); }
   if ( v->rc ) //Right = 1
      { code->set ( length ); generateCT ( code, length + 1, table, v->rc ); }
}

HuffTable* generateTable ( HuffTree tree ) { //将各字符编码统一存入以散列表实现的编码表中
   HuffTable* table = new HuffTable; Bitmap* code = new Bitmap;
   generateCT ( code, 0, table, tree.root() ); delete code; return table;
};