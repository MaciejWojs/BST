#include <iostream>
#include "BST.hpp"
#include <string>

int main() {
    // Branch beta
    Node n;
    BST bst;

    std::string path = "a.txt";
    // bst.load_from_text_file(path);

    bst.add_node(10);
    bst.add_node(1000);
    bst.add_node(5);
    bst.add_node(1);
    bst.add_node(13);

    bst.display(POSTORDER);
    bst.display(PREORDER);
    bst.display(INORDER);

    bst.purge();
    bst.display(PREORDER);
}
