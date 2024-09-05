#include "RB_Tree_Node.h"

template <typename T>
RB_Tree_Node<T>::RB_Tree_Node(T data_in)
: data(data_in), color_tag(0), LC(nullptr), RC(nullptr), Father(nullptr)
{}

template <typename T>
RB_Tree_Node<T>::~RB_Tree_Node()
{}