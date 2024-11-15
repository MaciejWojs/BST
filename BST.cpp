/**
 * \~english
 * @file BST.cpp
 * @brief Binary Search Tree (BST) implementation file.
 *
 * @details This file contains the implementation of the binary search tree (BST)
 * class and its node structure, as well as functions for managing the tree
 * and its traversal.
 *
 * \~polish
 * @file BST.cpp
 * @brief Plik implementacji drzewa BST.
 *
 * @details Zawiera implementację klasy drzewa wyszukiwania binarnego (BST)
 * oraz jego struktury węzłów i funkcji do zarządzania drzewem oraz jego przeglądaniem.
 */

#include "BST.hpp"
#include <iostream>
#include <string>
#include <fstream>

Node::Node() : Node({}) {}

Node::Node(int _value) : value(_value), right(nullptr), left(nullptr), parent(nullptr) {}

Node::~Node() {}

std::ostream& operator<<(std::ostream& output_stream, const Node* node) {
    output_stream << node->value;
    return output_stream;
}

BST::BST() : root(nullptr) {}

BST::~BST() {
    purge();
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

void BST::display_inorder(Node* node) {
    if (!node) {
        return;
    }

    display_inorder(node->left);
    std::cout << node << " ";
    display_inorder(node->right);
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
    if (!root) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    switch (mode) {
    case INORDER:
        std::cout << "IN-order: ";
        display_inorder(root);
        break;
    case POSTORDER:
        std::cout << "POST-order: ";
        display_postorder(root);
        break;
    case PREORDER:
        std::cout << "PRE-order: ";
        display_preorder(root);
        break;
    default:
        break;
    }
    std::cout << std::endl;
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

void BST::load_from_text_file(std::string path) {
    std::ifstream file(path.c_str(), std::ios::in);

    if (file) {
        std::cout << "Plik " << path << " istnieje!" << std::endl;
    } else {
        std::cout << "Plik nie istnieje!" << std::endl;
    }

    int buffer;
    while (file >> buffer) {
        add_node(buffer);
    }
}