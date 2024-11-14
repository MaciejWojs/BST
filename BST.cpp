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

void BST::add_node(int node_value) {
    Node* temp = new Node(node_value);
    if (!root) {
        root = temp;
        return;
    }

    Node* current_root = root;

    while (true) {
        if (node_value > current_root->value) {
            if (!current_root->right) {
                current_root->right = temp;
                temp->parent = current_root;
                break;
            } else {
                current_root = current_root->right;
                continue;
            }
        }

        if (node_value < current_root->value) {
            if (!current_root->left) {

                current_root->left = temp;
                temp->parent = current_root;
                break;
            } else {
                current_root = current_root->left;
                continue;
            }
        }
    }
}

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
