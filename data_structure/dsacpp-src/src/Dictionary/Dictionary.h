/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> struct Dictionary { //词典Dictionary模板类
   virtual Rank size() const = 0; //当前词条总数
   virtual bool put( K, V ) = 0; //插入词条
   virtual V* get( K k ) = 0; //读取词条
   virtual bool remove( K k ) = 0; //删除词条
};
