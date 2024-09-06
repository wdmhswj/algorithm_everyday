#include "RB_Tree.h"
#include "RB_Tree_Node.h"

template <typename T>
RB_Tree<T>::RB_Tree(T root_data): rootNode(nullptr)
{
    if (rootNode==nullptr) {
        rootNode = new RB_Tree_Node<T>(root_data);
        rootNode->color_tag = 0;
    }
}

template <class T>
RB_Tree<T>::~RB_Tree()
{
}


// 左旋
template <typename T>
void RB_Tree<T>::leftRotate(RB_Tree_Node<T>* currentNode)
{
    // 右孩子
    RB_Tree_Node<T>* rc = currentNode->RC;
    // 父节点
    RB_Tree_Node<T>* fn = currentNode->Father;
    
    // 左旋后当前节点的右孩子为左旋前当前节点右孩子的左孩子
    currentNode->RC = rc->LC;
    rc->LC->Father = currentNode;

    // 原右孩子的父节点变为当前节点的父节点
    rc->Father = fn;    // 不管fn是否为空
    // 父节点重新指向原右孩子   
    if(fn==nullptr) // 判断父节点是否为空
    {
        rootNode = rc;  // 根节点指针指向新的根节点
    }else if(currentNode == fn->LC) // 当前节点为父节点的左孩子
    {
        fn->LC = rc;
    }else
    {
        fn->RC = rc;
    }
    
    rc->LC = currentNode;   // 当前节点作为左孩子
    currentNode->Father = rc;
}

// 右旋
template <typename T>
void RB_Tree<T>::rightRotate(RB_Tree_Node<T>* currentNode)
{
    // 左孩子
    RB_Tree_Node<T>* lc = currentNode->LC;
    // 父节点
    RB_Tree_Node<T>* fn = currentNode->Father;

    // 右旋后当前节点的右孩子为右旋前当前节点左孩子的右孩子
    currentNode->RC = lc->RC;
    lc->RC->Father = currentNode;

    // 原左孩子的父节点变为当前节点的父节点
    lc->Father = fn;    // 不管fn是否为空
    // 父节点重新指向原右孩子   
    if(fn==nullptr) // 判断父节点是否为空
    {
        rootNode = lc;  // 根节点指针指向新的根节点
    }else if(currentNode == fn->LC) // 当前节点为父节点的左孩子
    {
        fn->LC = lc;
    }else
    {
        fn->RC = lc;
    }
    
    lc->RC = currentNode;   // 当前节点作为右孩子
    currentNode->Father = lc;
}

// 插入节点
template <typename T>
void RB_Tree<T>::insertNode(T insertData)
{
    // 从根节点开始根据二叉搜索树的顺序找到插入位置
    RB_Tree_Node<T>* tempNode = rootNode;
    while(tempNode != nullptr)
    {
        if(insertData>tempNode->data)
        {
            if(tempNode->RC == nullptr)
            {
                tempNode->RC = new RB_Tree_Node<T>(insertData);
                tempNode->RC->color_tag = 1;
                tempNode->RC->Father = tempNode;
                if(tempNode->color_tag == 1)    // 双红
                {
                    fixTree(tempNode->RC);
                }
                break;
            }else{
                tempNode = tempNode->RC;
            }
        }else if(insertData<tempNode->data){
            if(tempNode->LC == nullptr)
            {
                tempNode->LC = new RB_Tree_Node<T>(insertData);
                tempNode->LC->color_tag = 1;
                tempNode->LC->Father = tempNode;
                if(tempNode->color_tag == 1)
                {
                    fixTree(tempNode->LC);
                }
                break;
            }else{
                tempNode = tempNode->LC;
            }
        }
    }
}

// 插入节点后维护红黑树
template <typename T>
void RB_Tree<T>::fixTree(RB_Tree_Node<T>* currentNode)
{
    RB_Tree_Node<T>* tempCurrentNode = currentNode;
    RB_Tree_Node<T>* uncleNode = nullptr;
    while(true)
    {
        if(tempCurrentNode->Father == nullptr)  // 当前节点为根节点
        {
            break;
        }
        if(tempCurrentNode->Father->color_tag != 1) // 没有违反红黑树的性质
        {
            break;
        }

        RB_Tree_Node<T>* fn = tempCurrentNode->Father;  // 父节点
        RB_Tree_Node<T>* gfn = fn->Father;  // 祖父节点

        if(gfn)
        {
            if(fn == gfn->LC)   // 父节点为祖父节点的左孩子
            {
                uncleNode = gfn->RC;
                // 如果有叔叔节点
                if(uncleNode)
                {
                    // 情况1：叔叔为红色 ==》将父节点和叔叔节点变为黑色
                    //                                       祖父节点设置为红色
                    //                                       将祖父节点设置为当前节点
                    if(uncleNode->color_tag==1)
                    {
                        fn->color_tag = 0;
                        uncleNode->color_tag = 0;
                        gfn->color_tag = 1;
                        tempCurrentNode = gfn;
                    }
                    // 情况2：叔叔为黑色，且当前节点为左孩子（LL型） ==》父节点设置为黑色，祖父节点设置为红色
                    //                                                                                       再对祖父节点进行右旋                                    
                    else if(tempCurrentNode == fn->LC)
                    {
                        fn->color_tag = 0;
                        gfn->color_tag = 1;
                        rightRotate(gfn);
                    }
                    // 情况3：叔叔是黑色，且当前节点为右孩子（LR型）==》理论上先对父节点进行左旋，再对祖父节点进行右旋
                    //                                                                                      实际可以将父节点设置为当前节点，对父节点进行左旋（变为LL型），通过while循环解决
                    else
                    {
                        tempCurrentNode = fn;
                        leftRotate(tempCurrentNode);
                    }
                }else{  // 没有叔叔节点，null节点为黑色
                    if(tempCurrentNode == fn->LC)
                    {
                        fn->color_tag = 0;
                        gfn->color_tag = 1;
                        rightRotate(gfn);
                    }else{
                        tempCurrentNode = fn;
                        leftRotate(tempCurrentNode);
                    }
                }
            }else{  // 父节点为祖父节点的右孩子
                uncleNode = gfn->LC;
                // 如果有叔叔节点
                if(uncleNode)
                {
                    // 情况1：叔叔为红色 ==》将父节点和叔叔节点变为黑色
                    //                                       祖父节点设置为红色
                    //                                       将祖父节点设置为当前节点
                    if(uncleNode->color_tag==1)
                    {
                        fn->color_tag = 0;
                        uncleNode->color_tag = 0;
                        gfn->color_tag = 1;
                        tempCurrentNode = gfn;
                    }
                    // 情况2：叔叔为黑色，且当前节点为右孩子（RR型） ==》父节点设置为黑色，祖父节点设置为红色
                    //                                                                                       再对祖父节点进行左旋                                    
                    else if(tempCurrentNode == fn->RC)
                    {
                        fn->color_tag = 0;
                        gfn->color_tag = 1;
                        leftRotate(gfn);
                    }
                    // 情况3：叔叔是黑色，且当前节点为左孩子（RL型）==》理论上先对父节点进行右旋，再对祖父节点进行左旋
                    //                                                                                      实际可以将父节点设置为当前节点，对父节点进行右旋（变为RR型），通过while循环解决
                    else
                    {
                        tempCurrentNode = fn;
                        rightRotate(tempCurrentNode);
                    }
                }else{  // 没有叔叔节点，null节点为黑色
                    if(tempCurrentNode == fn->LC)
                    {
                        fn->color_tag = 0;
                        gfn->color_tag = 1;
                        leftRotate(gfn);
                    }else{
                        tempCurrentNode = fn;
                        rightRotate(tempCurrentNode);
                    }
                }
            }
        }

        
    }

    rootNode->color_tag = 0;    // 根节点始终为黑色
}
