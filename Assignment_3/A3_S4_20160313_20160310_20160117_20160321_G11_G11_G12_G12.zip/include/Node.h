#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node
{
    int iKey,iHeight;
    Node *left,*right;
    Node(){
        left=right=NULL;
        iHeight=1;
    }
    Node(int iData,Node *l,Node*r){
        iKey=iData;
        left=l;
        right=r;
    }
};

#endif // NODE_H
