#include "BST.hpp"
#include <iostream>
#include <stack>

Node::Node() : Node({}) {}

Node::Node(int _value) : value(_value), right(nullptr), left(nullptr), parent(nullptr) {}

Node::~Node() {}

std::ostream& operator<<(std::ostream& output_stream, const Node* node) {
    output_stream << node->value;
    return output_stream;
}

void Node::set_value(int a) {
    value = a;
}

int Node::get_value() {
    return value;
}


BST::BST() : root(nullptr) {}

BST::~BST() {
}

void BST::add_node_helper(int node_value, Node* current_root, Node* temp) {
    if (node_value > current_root->value) {
        if (!current_root->right) {
            current_root->right = temp;
            temp->parent = current_root;
            return;
        } else {
            add_node_helper(node_value, current_root->right, temp);
            return;
        }
    } else {
        if (!current_root->left) {
            current_root->left = temp;
            temp->parent = current_root;
        } else {
            add_node_helper(node_value, current_root->left, temp);
        }
    }
}

void BST::add_node(int node_value) {
    Node* temp = new Node(node_value);
    if (!root) {
        root = temp;
        return;
    }

    Node* current_root = root;
    add_node_helper(node_value, current_root, temp);
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