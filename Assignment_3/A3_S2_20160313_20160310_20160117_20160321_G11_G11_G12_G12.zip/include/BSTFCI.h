#ifndef BSTFCI_H
#define BSTFCI_H
#include "BSTNode.h"
#include <iostream>
#include <algorithm>
using namespace std;
class BSTFCI
{
    BSTNode *root;
    public:
        BSTFCI(){
            root = 0;
        }
        BSTNode* insertNode(BSTNode* node, int iData){
            if (node == NULL){
                BSTNode *temp =  new BSTNode;
                temp->iKey=iData;
                temp->left=temp->right=0;
                return temp;
            }
            if (iData < node->iKey)
                node->left=insertNode(node->left,iData);
            else if (iData > node->iKey)
                node->right=insertNode(node->right,iData);
            return node;
        }
        void insert(int iData){
            root=insertNode(root,iData);
        }
        void printInOrder(){
            inOrder(this->root);
        }
        void inOrder(BSTNode *root){
            if (root != NULL){
                inOrder(root->left);
                cout<<root->iKey<<" ";
                inOrder(root->right);
            }
        }
        BSTNode* searchForNode(BSTNode* root,int iData){
            if (root==NULL||root->iKey==iData)
                return root;
            if(iData>root->iKey)
                return searchForNode(root->right,iData);
            else
                return searchForNode(root->left,iData);
        }
        void search(int iData){
            root=searchForNode(root,iData);
        }
        int calcHeight(BSTNode *node){
            if(node==0)
                return 0;
            else
                return 1+max(calcHeight(node->left),calcHeight(node->right));
        }
        bool isBalanced(BSTNode *node){
            int iLeftHeight;
            int iRightHeight;
            if(node==0)
                return 1;
            iLeftHeight=calcHeight(node->left);
            iRightHeight= calcHeight(node->right);
            if(abs(iLeftHeight-iRightHeight)<=1&&isBalanced(node->left)&&isBalanced(node->right))
                return 1;
            return 0;
        }

        BSTNode * minNode(BSTNode* node){
            BSTNode* temp = node;
            while (temp->left != NULL)
                temp = temp->left;
            return temp;
        }
        BSTNode* deleteNode(BSTNode *node,int iData){
            if (node==0)
                return node;
            if(iData<node->iKey)
                node->left=deleteNode(node->left,iData);
            else if(iData>node->iKey)
                node->right=deleteNode(node->right,iData);
            else{
                if(node->left==0){
                    BSTNode *temp=node->right;
                    delete node;
                    return temp;
                }
                else if(node->right==0){
                    BSTNode *temp=node->left;
                    delete node;
                    return temp;
                }
                BSTNode *temp=minNode(node->right);
                node->iKey=temp->iKey;
                node->right=deleteNode(node->right,temp->iKey);
            }
            return node;
        }
        void deleteNode(int iData){
             deleteNode(root,iData);
        }
        bool equalityComp(BSTNode *node1,BSTNode *node2){
            if(node1==0&&node2==0){
                return true;
            }
            if(node1==0||node2==0){
                return false;
            }
            return (node1->iKey==node2->iKey && equalityComp(node1->left,node2->left) && equalityComp(node1->right,node2->right));
        }
        bool isSubOR(BSTNode *node1,BSTNode *node2){
            if(node1==0)
                return false;
            if(node2==0)
                return true;
            if(equalityComp(node1,node2))
                return true;
            return isSubOR(node1->left,node2)||isSubOR(node1->right,node2);
        }
        bool isSubTree(BSTFCI t1,BSTFCI t2){
            return t1.isSubOR(t1.root,t2.root);
        }
        void printRange(BSTNode *node,int iLow,int iHigh){
            if(node==0)
                return;
            if(iLow<node->iKey)
                printRange(node->left,iLow,iHigh);
            if(node->iKey>=iLow&&node->iKey<=iHigh)
                cout<<node->iKey<<endl;
            if(iHigh>node->iKey)
                printRange(node->right,iLow,iHigh);
        }
        void printRange(int iLow,int iHigh){
            printRange(root,iLow,iHigh);
        }

};

#endif // BSTFCI_H
