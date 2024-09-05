/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> //Splay����չ�㷨
BinNodePosi<T> Splay<T>::splay( BinNodePosi<T> v ) { //vΪ�����·��ʶ�����չ�Ľڵ�
   BinNodePosi<T> p, g; //v�ĸ������游
   while ( ( p = v->parent ) && ( g = p->parent ) ) { //���¶��ϣ�������v��˫����չ
      BinNodePosi<T> gg = g->parent; //ÿ��֮��v����ԭ���游��great-grand parent��Ϊ��
      switch ( ((p == g->rc) << 1) | (v == p->rc) ) { //��p��v�Ĺ��򣬷��������
         case 0b00 : //zig-zig
            g->attachLc( p->rc ); p->attachLc( v->rc );
            p->attachRc( g );     v->attachRc( p );     break;
         case 0b01 : //zig-zag
            p->attachRc( v->lc ); g->attachLc( v->rc );
            v->attachRc( g );     v->attachLc( p );     break;
         case 0b10 : //zag-zig
            p->attachLc( v->rc ); g->attachRc( v->lc );
            v->attachLc( g );     v->attachRc( p );     break;
         default : //0b11 ~ zag-zag
            g->attachRc( p->lc ); p->attachRc( v->lc );
            p->attachLc( g );     v->attachLc( p );     break;
      }
      if ( !gg ) v->parent = NULL; //��vԭ�ȵ����游gg�����ڣ���v����ӦΪ����
      else //����gg�˺�Ӧ����v��Ϊ����Һ���
         ( g == gg->lc ) ? gg->attachLc( v ) : gg->attachRc( v );
      g->updateHeight(); p->updateHeight(); v->updateHeight();
   } //˫����չ����ʱ������g == NULL����p���ܷǿ�
   if ( p = v->parent ) { //��p�����Ǹ������������һ�ε���
      if ( v == p->lc ) { p->attachLc( v->rc ); v->attachRc( p ); }
      else              { p->attachRc( v->lc ); v->attachLc( p ); }
      p->updateHeight(); v->updateHeight();
   }
   v->parent = NULL; return v;
} //����֮��������ӦΪ����չ�Ľڵ㣬�ʷ��ظýڵ��λ���Ա��ϲ㺯����������
