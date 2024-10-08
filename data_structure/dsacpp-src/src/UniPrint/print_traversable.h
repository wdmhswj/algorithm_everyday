/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 向量、列表等支持traverse()遍历操作的线性结构
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p ( T& s ) { //引用
   printf ( "%s[%d]*%d:\n", typeid ( s ).name(), (int) &s, s.size() ); //基本信息
   s.traverse ( print ); //通过print()遍历输出所有元素
   printf ( "\n" );
}