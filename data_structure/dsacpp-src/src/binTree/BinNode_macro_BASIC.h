/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BinNode状态与性质的判断
 ******************************************************************************************/
#define IsLChild(x) ( ((x)->parent) && ((x) == (x)->parent->lc) )
#define IsLeaf(x) ( (!(x)->lc) && (!(x)->rc) )

/******************************************************************************************
 * 与BinNode具有特定关系的节点及指针
 ******************************************************************************************/
#define sibling( p ) ( ((p) == (p)->parent->lc) ? (p)->parent->rc : (p)->parent->lc ) /*兄弟*/
#define uncle( x ) ( sibling( (x)->parent ) ) /*叔叔*/
#define FromParentTo( x ) /*来自父亲的引用*/ \
   ( (x)->parent ? ( ((x) == (x)->parent->lc) ? (x)->parent->lc : (x)->parent->rc ) : _root )
