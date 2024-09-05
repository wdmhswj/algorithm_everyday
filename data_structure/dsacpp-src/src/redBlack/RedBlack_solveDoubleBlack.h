/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * RedBlack˫�ڵ����㷨������ڵ�x�뱻������Ľڵ��Ϊ��ɫ������
 * ��Ϊ�����๲���������
 *    BB-1 ��2����ɫ��ת��2�κڸ߶ȸ��£�1~2����ת�����ٵݹ�
 *    BB-2R��2����ɫ��ת��2�κڸ߶ȸ��£�0����ת�����ٵݹ�
 *    BB-2B��1����ɫ��ת��1�κڸ߶ȸ��£�0����ת����Ҫ�ݹ�
 *    BB-3 ��2����ɫ��ת��2�κڸ߶ȸ��£�1����ת��תΪBB-1��BB2R
 ******************************************************************************************/
template <typename T> void RedBlack<T>::solveDoubleBlack( BinNodePosi<T> r ) {
   while ( 1 ) {
      BinNodePosi<T> p = r ? r->parent : _hot; if ( !p ) return; //r�ĸ���
      BinNodePosi<T> s = ( r == p->lc ) ? p->rc : p->lc; //r���ֵ�
      if ( IsBlack( s ) ) { //�ֵ�sΪ��
         // s�ĺ캢��t�������Һ��ӽԺ죬�������ȣ��Ժ�ʱΪNULL
         BinNodePosi<T> t = IsRed( s->lc ) ? s->lc : IsRed( s->rc ) ? s->rc : NULL;
         if ( t ) { //��s�к캢�ӣ�BB-1
            RBColor oldColor = p->color; //����ԭ�������ڵ�p��ɫ
         // ���£�ͨ����ת��ƽ�⣬���������������Һ���Ⱦ��
            BinNodePosi<T> b = rotateAt( t ); //��ת
            if ( b->lc ) { b->lc->color = RB_BLACK; b->lc->updateHeight(); } //����
            if ( b->rc ) { b->rc->color = RB_BLACK; b->rc->updateHeight(); } //����
            b->color = oldColor; b->updateHeight(); return; //�����¸��̳�ԭ������ɫ
         } else { //��s�޺캢��
            s->color = RB_RED; s->height--; //sת��
            if ( IsRed( p ) ) { p->color = RB_BLACK; return; } //BB-2R��pת�ڣ����ڸ߶Ȳ���
            else { p->height--; r = p; } //BB-2B��p���ֺڣ����ڸ߶��½�����������
         }
      } else { //�ֵ�sΪ�죺BB-3
         s->color = RB_BLACK; p->color = RB_RED; //sת�ڣ�pת��
         BinNodePosi<T> t = ( s == p->lc ) ? s->lc : s->rc; //ȡt���丸sͬ��
         _hot = p; rotateAt( t ); //��t���丸�ס��游��ƽ�����
         //��������������r����˫�ڡ�����ʱ��p��ת�죬�ʽ�����ֻ����BB-1��BB-2R
      }
   } //while
}
