#include <iostream>
#include <string>

#include "BSTFCI.h"
#include "BSTNode.h"
using namespace std;

int main()
{
    BSTFCI tree1;

    tree1.insert(20);
    tree1.insert(50);
    tree1.insert(25);
    tree1.insert(60);
    tree1.insert(55);
    tree1.insert(70);
    tree1.insert(10);
    tree1.insert(15);
    tree1.insert(5);


    BSTFCI tree2;

    tree2.insert(10);
    tree2.insert(15);
    tree2.insert(5);

    cout<<tree1.isSubTree(tree1,tree2)<<endl;

    tree1.printRange(30,65);

    tree1.printInOrder();
    tree1.deleteNode(25);
    cout<<endl;
    tree1.printInOrder();
    return 0;
}
