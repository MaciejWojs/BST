#include <iostream>
#include "BST.hpp"
#include <string>

int main() {
    Node n;
    BST bst;

    std::string path = "a.txt";
    bst.load_from_text_file(path);

    // bst.add_node(10);
    // bst.add_node(1000);
    // bst.add_node(5);
    // bst.add_node(1);
    // bst.add_node(13);
    // bst.add_node(14);
    // bst.add_node(534);
    // bst.add_node(22);

    bst.display_tree();

    // bst.display(POSTORDER);
    // bst.display(PREORDER);
    // bst.display(INORDER);

    // std::cout << bst.get_depth() << '\n';
    // std::cout << bst.get_biggest() << '\n';
    // std::cout << bst.get_smallest() << '\n';

    // bst.display_tree();

    bst.find(1);
    bst.find(18);
    bst.purge();
    bst.display(PREORDER);
}
