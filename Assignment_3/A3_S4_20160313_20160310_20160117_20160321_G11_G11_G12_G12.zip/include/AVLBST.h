#ifndef AVLBST_H
#define AVLBST_H

#include "Node.h"
#include <algorithm>
using namespace std;

class AVLBST
{
    Node *root;
    public:
        AVLBST(){
            root=NULL;
        }
        int height(Node* root){
            if(root==NULL)
                return 0;
            return root->iHeight;
        }
        Node *rotateRight(Node *root){
            Node* temp=root->left;
            Node* tempChild=temp->right;
            temp->right=root;
            root->left=tempChild;

            root->iHeight = max(height(root->left), height(root->right))+1;
            temp->iHeight = max(height(temp->left), height(temp->right))+1;

            return temp;
        }
        Node *rotateLeft(Node *root){
            Node* temp=root->right;
            Node* tempChild=temp->left;
            temp->left=root;
            root->right=tempChild;

            root->iHeight = max(height(root->left), height(root->right))+1;
            temp->iHeight = max(height(temp->left), height(temp->right))+1;

            return temp;
        }
        int balanceFactor(Node *root){
            if(root==NULL)
                return 0;
            return height(root->left)-height(root->right);
        }
        Node* insertNode(Node *root,int iData){
            if (root==0){
                Node *temp=new Node;
                temp->iKey=iData;
                temp->right=temp->left=NULL;
                return temp;
            }
            if (iData>root->iKey)
                root->right=insertNode(root->right,iData);
            if (iData<root->iKey)
                root->left=insertNode(root->left,iData);
            else
                return root;

            root->iHeight=1+max(height(root->left),height(root->right));

            int iBalnceOr=balanceFactor(root);

            if(iBalnceOr>1 && root->left->iKey > root->iKey){ // Left Left
                cout<<"here\n";
                root=rotateRight(root);

            }
            else if(iBalnceOr<-1 && root->right->iKey < root->iKey )
                root=rotateLeft(root);
            else if(iBalnceOr>1 && root->left->iKey < root->iKey ){
                root->left=rotateLeft(root->left);
                root=rotateRight(root);
            }
            else if(iBalnceOr<-1 && root->left->iKey > root->iKey ){
                root->right=rotateRight(root->right);
                root=rotateLeft(root);
            }
            return root;
        }
        void insertNode(int iData){
            root=insertNode(root,iData);
        }
        Node * minValueNode(Node* node){
            Node* temp = node;
            while (temp->left != NULL)
                temp = temp->left;
            return temp;
        }
        Node* deleteNode(Node* root, int iData){
            if (root == NULL)
                return root;
            if ( iData< root->iKey )
                root->left = deleteNode(root->left, iData);
            else if( iData > root->iKey )
                root->right = deleteNode(root->right, iData);
            else{
                if( (root->left == NULL) || (root->right == NULL) ){
                    Node *temp = root->left ? root->left:root->right;

                    if (temp == NULL){
                        temp = root;
                        root = NULL;
                    }
                    else
                        *root = *temp;
                    delete temp;
                }
                else{
                    Node* temp = minValueNode(root->right);
                    root->iKey = temp->iKey;
                    root->right = deleteNode(root->right, temp->iKey);
                }
            }
            if (root == NULL)
              return root;
            root->iHeight = 1 + max(height(root->left),
                                   height(root->right));
            int iBalance = balanceFactor(root);
            if (iBalance > 1 && balanceFactor(root->left) >= 0)
                return rotateRight(root);
            if (iBalance > 1 && balanceFactor(root->left) < 0){
                root->left =  rotateLeft(root->left);
                return rotateRight(root);
            }
            if (iBalance < -1 && balanceFactor(root->right) <= 0)
                return rotateLeft(root);
            if (iBalance < -1 && balanceFactor(root->right) > 0){
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
            return root;
        }
        void deleteNode(int iData){
            deleteNode(root,iData);
        }
        void inOrder(Node *root){
            if(root != NULL){
                inOrder(root->left);
                cout<<root->iKey<<"  ";
                inOrder(root->right);
            }
        }
        void inOrder(){
            inOrder(root);
        }
        void preOrder(Node *root){
            if(root!= NULL){
                cout<<root->iKey<<"  ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
        void preOrder(){
            preOrder(root);
        }
        void postOrder(Node *root){
            if(root!=NULL){
                postOrder(root->left);
                postOrder(root->right);
                cout<<root->iKey<<"  ";
            }
        }
        void postOrder(){
            postOrder(root);
        }
        bool isBalanced(Node *root){
            if(root==NULL)
                return 1;
            int iLeftHeight=height(root->left);
            int iRightHeight=height(root->right);
            if(abs(iLeftHeight-iRightHeight)<2 && isBalanced(root->left) && isBalanced(root->right))
                return 1;
            return 0;
        }
        bool isBalanced(){
            isBalanced(root);
        }
};

#endif // AVLBST_H
