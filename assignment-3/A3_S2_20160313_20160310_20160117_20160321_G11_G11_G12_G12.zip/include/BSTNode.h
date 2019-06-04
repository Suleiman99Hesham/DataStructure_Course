#ifndef BSTNODE_H
#define BSTNODE_H

struct BSTNode
{
    int iKey;
    BSTNode *left,*right;
    public:
		BSTNode () {left = right = 0;}
		BSTNode (int iData, BSTNode* l = 0, BSTNode* r = 0){
           iKey   = iData;
           left  = l;
           right = r;
        }
};

#endif // BSTNODE_H
