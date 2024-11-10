#include <iostream>
#include "BST.hpp"

int main() {
    std::cout << "HelloWorld\n";
    // Branch beta
    Node n;
    BST bst;

    bst.display(POSTORDER);
    bst.display(PREORDER);
    bst.display(INORDER);
}
