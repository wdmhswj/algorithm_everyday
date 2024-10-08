/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include "stack/stack.h" //栈
#include "queen.h" //引入皇后类

typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; //运行模式
extern int nSolu; //解的总数
extern int nCheck; //尝试的总次数

void placeQueens ( Rank );
void displayRow ( Queen& q, Rank );
void displayProgress ( Stack<Queen>& S, Rank );