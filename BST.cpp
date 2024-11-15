#include "BST.hpp"
#include <iostream>

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
void BST::display_postorder(Node* node) {
    if (!node) {
        return;
    }

    display_postorder(node->left);
    display_postorder(node->right);
    std::cout << node << " ";
}

void BST::display_preorder(Node* node) {
    if (!node) {
        return;
    }
    std::cout << node << " ";
    display_preorder(node->left);
    display_preorder(node->right);
}

void BST::display(display_mode mode) {
    switch (mode) {
    case INORDER:

        break;
    case POSTORDER:
        std::cout << "POSTORDER: ";
        if (!root) {
            std::cout << "Empty tree" << std::endl;
            break;
        }
        display_postorder(root);
        std::cout << std::endl;
        break;
    case PREORDER:
        std::cout << "PREORDER: ";
        if (!root) {
            std::cout << "Empty tree" << std::endl;
            break;
        }
        display_preorder(root);
        std::cout << std::endl;
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
//#endif 