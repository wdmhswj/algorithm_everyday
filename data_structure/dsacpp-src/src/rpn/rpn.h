/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once
#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "stack/stack.h" //ʹ��ջ
#include "priority.h"

__int64 facI ( int n );
double calcu ( double a, char op, double b );
double calcu ( char op, double b );
void displayProgress ( char*, char*, Stack<double>&, Stack<char>&, char* );
void readNumber ( char*&, Stack<double>& );
Operator optr2rank ( char );
char priority ( char, char );
void append ( char*, double ); //����
void append ( char*, char ); //����
double evaluate ( char* expr, char* rpn );
