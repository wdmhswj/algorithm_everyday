/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST�ڵ���ת�任ͳһ�㷨��3�ڵ� + 4�����������ص���֮��ֲ��������ڵ��λ��
 * ע�⣺��������������ȷָ���ϲ�ڵ㣨������ڣ�������������������ϲ㺯�����
 ******************************************************************************************/
template <typename T> BinNodePosi<T> BST<T>::rotateAt( BinNodePosi<T> v ) { //vΪ�ǿ��ﱲ�ڵ�
   /*DSA*/if ( !v ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
   BinNodePosi<T> p = v->parent; int TurnV = (v == p->rc);
   BinNodePosi<T> g = p->parent; int TurnP = (p == g->rc);
   BinNodePosi<T> r = ( TurnP == TurnV ) ? p : v; //�����µĸ��ڵ�
   ( FromParentTo(g) = r )->parent = g->parent;; //�뱣����ĸ��������
   switch ( ( TurnP << 1 ) | TurnV ) { //��p��v�Ĺ����޷��������
      case 0b00 : //zig-zig
         return connect34( v, p, g,  v->lc, v->rc, p->rc, g->rc );
      case 0b01 : //zig-zag
         return connect34( p, v, g,  p->lc, v->lc, v->rc, g->rc );
      case 0b10 : //zag-zig
         return connect34( g, v, p,  g->lc, v->lc, v->rc, p->rc );
      default : //0b11 ~ zag-zag
         return connect34( g, p, v,  g->lc, p->lc, v->lc, v->rc );
   }
}