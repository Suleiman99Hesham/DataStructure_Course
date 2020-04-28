#include <iostream>

using namespace std;


struct Node{
    char value;
    Node *left;
    Node *right;

    Node (char val){
        this->value=val;
        this->right=this->left=NULL;
    }
};

class BST {
    private:
        Node *root=NULL;

    public:
        int second_value=0,total=0;
        void Add(Node *root,char val){
            if (!root->left) {
                root->left = new Node (val);
            }
            else {
                Add(root->left, val);
            }

            if (!root->right) {
                root->right = new Node(val);
            }
            else {
                Add(root->right, val);
            }
    }

        void add(char val) {
        if (root) {
            this->Add(root, val);
        } else {
            root = new Node(val);
        }
    }

    void calculate(Node *root){
        if (!root){
            return;
        }
        if (root->right){
            calculate(root->right);
            if (root->value!='+'||root->value!='-'||root->value!='*'||root->value!='/')
                total=(root->right->value)-48;
            root->right=NULL;
        }
        if (root->left){
            calculate(root->left);
            second_value=(root->left->value)-48;
            root->left=NULL;
        }
        if (!root->left && !root->right){
            if (root->value=='+')
                total=second_value+total;
            else if (root->value=='-')
                total=second_value-total;
            else if (root->value=='*')
                total=second_value*total;
            else if (root->value=='/')
                total=second_value/total;
            return;
        }
        calculate(root);
    }
    void CalculateHelper(){
        calculate(this->root);
    }
};

int main (){
    BST *bst =new BST ();
    string expression;
    cout<<"The Expression : ";
    getline(cin,expression);
    while ((expression[0]!='/'&&expression[0]!='*'&&expression[0]!='+'&&expression[0]!='-')){
        cout<<"please enter a valid expression: ";
        getline(cin,expression);
    }
    for (unsigned int i=0;i<expression.length();i++){
            if (expression[i]!=' ')
                bst->add(expression[i]);
    }
    bst->CalculateHelper();
    cout<<"Evaluation : "<<bst->total<<endl;
    return 0;
}
