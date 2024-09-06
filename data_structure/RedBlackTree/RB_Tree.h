#pragma once

#include "RB_Tree_Node.h"

template <typename T>  
class RB_Tree
{
public:
    RB_Tree(T root_data);
    ~RB_Tree();
    void leftRotate(RB_Tree_Node<T>* currentNode);
    void rightRotate(RB_Tree_Node<T>* currentNode);
    int deleteNode(T deleteData);
    void insertNode(T insertData);
    void fixTree(RB_Tree_Node<T>* currentNode);
    void eraseNode(RB_Tree_Node<T>* delNode);
    void fixTreeDelete(RB_Tree_Node<T>* currentNode);
    RB_Tree_Node<T>* findSuccessorNode(RB_Tree_Node<T>* currentNode);
    RB_Tree_Node<T>* rootNode;
};