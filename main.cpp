#include <iostream>
#include "BST.hpp"

int main() {
    // Branch beta
    Node n;
    BST bst;

    bst.add_node(10);
    bst.add_node(1000);
    bst.add_node(5);
    bst.add_node(1);
    bst.add_node(13);
    bst.add_node(14);
    bst.add_node(534);
    bst.add_node(22);

    bst.display(POSTORDER);
    bst.display(PREORDER);
    bst.display(INORDER);

    bst.find(1);
    bst.find(7);
    bst.purge();
    bst.display(PREORDER);
}
