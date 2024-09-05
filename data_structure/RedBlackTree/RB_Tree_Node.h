#pragma once

template<typename T>
class RB_Tree_Node
{
public:
    RB_Tree_Node(T data_in);
    ~RB_Tree_Node();

    T data;
    int color_tag;
    RB_Tree_Node* LC;
    RB_Tree_Node* RC;
    RB_Tree_Node* Father;
    
};
