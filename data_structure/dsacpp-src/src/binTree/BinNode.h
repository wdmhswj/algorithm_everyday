/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

using Rank = unsigned int;

#if defined( DSA_REDBLACK ) //�ں������
#define stature( p ) ( ( p ) ? ( p )->height : 0 ) //�ⲿ�ڵ㣨�ڣ��߶�Ϊ0�����ϵ���
#else //����BST��
#define stature( p ) ( (int)( ( p ) ? ( p )->height : -1 ) ) //�ⲿ�ڵ�߶�Ϊ-1�����ϵ���
#endif

typedef enum { RB_RED, RB_BLACK} RBColor; //�ڵ���ɫ

template <typename T> struct BinNode;
template <typename T> using BinNodePosi = BinNode<T>*; //�ڵ�λ��

template <typename T> struct BinNode { //�������ڵ�ģ����
// ��Ա��Ϊ���������ͳһ���ţ����߿ɸ�����Ҫ��һ����װ��
   T data; //��ֵ
   BinNodePosi<T> parent, lc, rc; //���ڵ㼰���Һ���
   Rank height; //�߶ȣ�ͨ�ã�
   Rank npl; //Null Path Length����ʽ�ѣ�Ҳ��ֱ����height���棩
   RBColor color; //��ɫ���������
// ���췽��
   BinNode() : parent( NULL ), lc( NULL ), rc( NULL ), height( 0 ), npl( 1 ), color( RB_RED ) {}
   BinNode( T e, BinNodePosi<T> p = NULL, BinNodePosi<T> lc = NULL,
            BinNodePosi<T> rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED )
      : data( e ), parent( p ), lc( lc ), rc( rc ), height( h ), npl( l ), color( c )
      { if (lc) lc->parent = this; if (rc) rc->parent = this; }
// �����ӿ�
   Rank size(); //ͳ�Ƶ�ǰ�ڵ����������༴����Ϊ���������Ĺ�ģ
   Rank updateHeight(); //���µ�ǰ�ڵ�߶�
   void updateHeightAbove(); //���µ�ǰ�ڵ㼰�����ȵĸ߶�
   BinNodePosi<T> insertLc( T const& ); //��������
   BinNodePosi<T> insertRc( T const& ); //�����Һ���
   void attachLc( BinNodePosi<T> ); //����������
   void attachRc( BinNodePosi<T> ); //����������
   BinNodePosi<T> succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��
   template <typename VST> void travLevel( VST& ); //������α���
   template <typename VST> void travPre( VST& ); //�����������
   template <typename VST> void travIn( VST& ); //�����������
   template <typename VST> void travPost( VST& ); //�����������
   /*DSA*/ template <typename VST> void traverse( VST& ); //�Զ������
// �Ƚ������е�����������һ���������в��䣩
   bool operator< ( BinNode const& bn ) { return data < bn.data; } //С��
   bool operator== ( BinNode const& bn ) { return data == bn.data; } //����
   /*DSA*/
   /*DSA*/BinNodePosi<T> zig(); //˳ʱ����ת
   /*DSA*/BinNodePosi<T> zag(); //��ʱ����ת
   /*DSA*/BinNodePosi<T> balance(); //��ȫƽ�⻯
   /*DSA*/BinNodePosi<T> imitate( const BinNodePosi<T> ); //��ġ
};

#include "BinNode_implementation.h"