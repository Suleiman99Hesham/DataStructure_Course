#include <iostream>

using namespace std;
struct Node{
    char value;
    Node *left,*right;
    Node (char val){
        this->value=val;
        this->left=NULL;
        this->right=NULL;
    }
};
class BST{
private :
    Node *root=NULL;
    int counter=0;
public :
    void addHelper(char val){
        if (root)
            add(root,val);
        else
            root=new Node (val);
    }
    void add(Node *root,char val){
        if (!root->left)
            root->left=new Node(val);
        else if(!root->right){
            root->right=new Node(val);
        }
        else
            add(root->left,val);

    }
    void printHelper(){
        print(this->root);
    }
    void print(Node * root){
        if (!root)
            return;
            print(root->left);
            print(root->right);
            cout<<root->value<<" ";
            return;
        print(root);
    }
    void flip(Node * root){
        if (!root)
            return;
        Node *node=root->left;
        root->left=root->right;
        root->right=node;
        flip(root->left);
        flip(root->right);
    }
    void flipHelper(){
        flip(this->root);
    }
};
int main()
{
    BST *bst=new BST();
    string word="123456789";
    for (unsigned int i=0;i<word.length()-1;i++){
        bst->addHelper(word[i]);
    }
    cout<<"The First Tree : ";
    bst->printHelper();
    cout<<endl<<"The Mirrored Tree : ";
    bst->flipHelper();
    bst->printHelper();

    return 0;
}
