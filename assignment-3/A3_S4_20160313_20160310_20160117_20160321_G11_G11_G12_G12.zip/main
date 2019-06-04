#include <iostream>
#include "AVLBST.h"
#include "Node.h"

using namespace std;

int main()
{
    AVLBST avlTree;

    avlTree.insertNode(57);
    avlTree.insertNode(78);
    avlTree.insertNode(63);
    avlTree.insertNode(42);
    avlTree.insertNode(85);
    avlTree.insertNode(60);
    avlTree.insertNode(72);
    avlTree.insertNode(49);
    avlTree.insertNode(45);
    avlTree.insertNode(25);
    avlTree.insertNode(30);
    avlTree.insertNode(36);
    avlTree.insertNode(17);

    cout<<avlTree.isBalanced()<<endl;
    cout<<endl;
    avlTree.inOrder();
    cout<<endl;
    avlTree.insertNode(61);
    cout<<endl;
    avlTree.inOrder();
    cout<<endl;
    cout<<avlTree.isBalanced()<<endl;

    avlTree.deleteNode(60);

    cout<<endl;
    avlTree.inOrder();
    cout<<endl;

    avlTree.deleteNode(78);

    cout<<endl;
    avlTree.inOrder();
    cout<<endl;

    avlTree.deleteNode(42);

    avlTree.preOrder();
    cout<<endl;
    avlTree.inOrder();
    cout<<endl;
    avlTree.postOrder();
    return 0;

}


