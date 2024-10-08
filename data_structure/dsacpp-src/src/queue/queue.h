/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include "List/List.h" //以List为基类派生出的
template <typename T> class Queue: public List<T> { //队列模板类
public: //原有接口一概沿用
   void enqueue( T const& e ) { insertLast( e ); } //入队：尾部插入
   T dequeue() { return remove( first() ); } //出队：首部删除
   T& front() { return first()->data; } //队首
};

#include "queue_implementation.h"
