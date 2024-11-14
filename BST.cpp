#include "BST.hpp"
#include <iostream>

Node::Node() : Node({}) {}

Node::Node(int _value) : value(_value), right(nullptr), left(nullptr), parent(nullptr) {}

Node::~Node() {}

void Node::set_value(int a) {
    value = a;
}

int Node::get_value() {
    return value;
}


BST::BST() : root(nullptr) {}

BST::~BST() {
}
#ifndef DEBUG
void BST::display(display_mode mode) {
    switch (mode) {
    case INORDER:
        /* code */
        std::cout << INORDER;
        break;
    case POSTORDER:
        std::cout << POSTORDER;
        /* code */
        break;
    case PREORDER:
        std::cout << PREORDER;
        /* code */
        break;

    default:
        break;
    }

}
void BST::purge() {
    purge_helper(root);
    root = nullptr;
}

void BST::purge_helper(Node* node) {
    if (node == nullptr) {
        return;
    }


    purge_helper(node->left);
    purge_helper(node->right);


    delete node;
}
#endif 