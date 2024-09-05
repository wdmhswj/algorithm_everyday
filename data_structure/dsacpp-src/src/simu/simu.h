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
#include <ctime>
#include <climits>

#include "queue/queue.h" //�������
#include "Customer.h" //�˿���

int bestWindow( Queue<Customer> *, Rank );
void printCustomer( Customer );
void displayProgress( Queue<Customer> *, Rank, Rank );
void simulate( Rank, Rank );

extern int delay; //���ƽ�����ʾ���ӳ�