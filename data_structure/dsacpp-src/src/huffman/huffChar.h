/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#define  N_CHAR  (0x80 - 0x20) //仅以可打印字符为例
struct HuffChar { //Huffman（超）字符
   char ch; unsigned int weight; //字符、频率
   HuffChar ( char c = '^', unsigned int w = 0 ) : ch ( c ), weight ( w ) {};
   HuffChar ( HuffChar const & hc ) : ch( hc.ch ), weight( hc.weight ) {};
   // 比较器、判等器（各列其一，其余自行补充）
   bool operator< ( HuffChar const& hc ) { return weight > hc.weight; } //此处故意大小颠倒
   bool operator== ( HuffChar const& hc ) { return weight == hc.weight; }
};