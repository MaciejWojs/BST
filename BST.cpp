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
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

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

/**
 * \~english
 * @brief Displays the binary search tree in a visual, level-by-level format
 *
 * This function provides a visual representation of the BST structure by:
 * 1. First checking if the tree is empty
 * 2. If not empty, calculating the tree's depth and required display width
 * 3. Creating a 2D vector to store the tree's visual representation
 * 4. Using a helper function to populate the visualization matrix
 * 5. Finally printing the tree structure to console
 *
 * The visualization uses:
 * - Width calculation: 3 * 2^(depth-1) to ensure proper spacing
 * - A 2D vector where each row represents a tree level
 * - Each cell in the vector contains either a node value or empty space
 *
 * @note The function handles empty trees by displaying "Empty tree"
 * @note The width is calculated to ensure proper spacing between nodes
 *
 * Time Complexity: O(n) where n is the number of nodes
 * Space Complexity: O(2^h) where h is the height of the tree
 *
 * \~polish
 * @brief Wyświetla drzewo BST w formacie wizualnym, poziom po poziomie
 *
 * Funkcja zapewnia wizualną reprezentację struktury BST poprzez:
 * 1. Sprawdzenie czy drzewo jest puste
 * 2. Jeśli nie jest puste, obliczenie głębokości drzewa i wymaganej szerokości wyświetlania
 * 3. Utworzenie dwuwymiarowego wektora do przechowywania wizualnej reprezentacji drzewa
 * 4. Użycie funkcji pomocniczej do wypełnienia matrycy wizualizacji
 * 5. Końcowe wydrukowanie struktury drzewa na konsolę
 *
 * Wizualizacja wykorzystuje:
 * - Obliczenie szerokości: 3 * 2^(głębokość-1) dla zapewnienia odpowiednich odstępów
 * - Dwuwymiarowy wektor, gdzie każdy wiersz reprezentuje poziom drzewa
 * - Każda komórka w wektorze zawiera wartość węzła lub pustą przestrzeń
 *
 * @note Funkcja obsługuje puste drzewa wyświetlając "Empty tree"
 * @note Szerokość jest obliczana tak, aby zapewnić odpowiednie odstępy między węzłami
 *
 * Złożoność czasowa: O(n) gdzie n to liczba węzłów
 * Złożoność przestrzenna: O(2^h) gdzie h to wysokość drzewa
 */
void BST::display_tree() {
    // Sprawdzenie czy korzeń drzewa (root) nie jest nullem (czy drzewo jest puste)
    // Jeśli jest puste, wyświetl komunikat "Empty tree" i wyjdź z funkcji przez return
    if (!root) {
        std::cout << "Empty tree" << std::endl;
        return;
    }

    // Wywołanie metody get_depth() która zwraca głębokość drzewa (liczbę poziomów)
    int depth = get_depth();
    // Obliczenie szerokości potrzebnej do wyświetlenia drzewa używając wzoru 2^depth - 1
    // Na przykład: dla głębokości 3, szerokość = 2^3 - 1 = 8 - 1 = 7
    int width = std::pow(2, depth) - 1;
    // Znalezienie największej liczby w drzewie (get_biggest()), zamiana jej na string
    // i obliczenie ile znaków zajmuje ta liczba (to będzie szerokość wyświetlania każdej komórki)
    int int_width = (int)std::to_string(get_biggest()).length();
    // Utworzenie dwuwymiarowego wektora stringów o wymiarach [depth][width]
    // Każda komórka jest początkowo wypełniona pojedynczą spacją " "
    std::vector<std::vector<std::string>> levels(depth, std::vector<std::string>(width, " "));
    // Wywołanie funkcji pomocniczej która wypełni wektor levels wartościami węzłów
    // Parametry: root (korzeń), 0 (początkowa głębokość), 0 (lewy indeks), width (prawy indeks), levels (referencja do wektora)
    display_tree_helper(root, 0, 0, width, levels);
    int i = 0;
    // Pętla przez każdy poziom drzewa (każdy wiersz w wektorze levels)
    for (const auto& level : levels) {
        std::cout << "nr. " << std::setw(3) << std::left << ++i;
        // Pętla przez każdą komórkę w danym poziomie
        for (const auto& cell : level) {
            // Wyświetlenie wartości komórki z wyrównaniem do int_width znaków
            // std::setw(int_width) ustawia szerokość pola wyświetlania
            // std::cout << std::setw(int_width) << cell;
            std::cout << std::setw(3) << cell;

        }
        // Po wyświetleniu wszystkich komórek w poziomie, przejście do nowej linii
        std::cout << std::endl;
    }
}
void BST::display_tree_helper(Node* node, int depth, int left, int right, std::vector<std::vector<std::string>>& levels) {
    // Sprawdzenie czy węzeł istnieje - jeśli nie, kończymy rekurencję
    if (!node) {
        return;
    }

    // Obliczenie środka przedziału dla aktualnego węzła
    int mid = (left + right) / 2;

    // Umieszczenie wartości węzła w odpowiedniej pozycji w tablicy levels
    // Konwersja wartości liczbowej na string i zapisanie w odpowiednim miejscu
    levels[depth][mid] = std::to_string(node->value);

    // Jeśli istnieje lewe dziecko, rekurencyjne wywołanie dla lewego poddrzewa
    // Używamy lewej połowy przedziału (od left do mid)
    if (node->left) {
        display_tree_helper(node->left, depth + 1, left, mid, levels);
    }

    // Jeśli istnieje prawe dziecko, rekurencyjne wywołanie dla prawego poddrzewa
    // Używamy prawej połowy przedziału (od mid+1 do right)
    if (node->right) {
        display_tree_helper(node->right, depth + 1, mid + 1, right, levels);
    }
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
    case ALL:
        display(INORDER);
        display(POSTORDER);
        display(PREORDER);
        break;
    default:
        std::cout << "Unknown display method\n";
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
    std::ifstream file(path, std::ios::in);

    if (file) {
        std::cout << "Plik " << path << " istnieje!" << std::endl;
    } else {
        std::cout << "Plik nie istnieje!" << std::endl;
    }

    int buffer;
    while (file >> buffer) {
        add_node(buffer);
    }
    file.close();
}

Node* BST::find_helper(Node* node, int value) {
    if (!node) {
        return nullptr;
    }

    Node* result = nullptr;

    std::cout << node;
    if (value == node->value) {
        std::cout << std::endl;
        return node;
    } else if (value < node->value) {
        std::cout << " -> ";
        result = find_helper(node->left, value);
    } else {
        std::cout << " -> ";
        result = find_helper(node->right, value);
    }

    return result;

}

Node* BST::find(int value) {
    if (!root) {
        std::cout << "Cannot find value " << value << " in an empty tree" << std::endl;
        return nullptr;
    }

    std::cout << "Sciezka wyszukiwania wartosci " << value << ": ";

    Node* result = find_helper(root, value);
    if (result) {
        return result;
    }

    std::cout << "null" << std::endl;
    return nullptr;
}

int BST::get_depth() {
    return get_depth_helper(root);
}

int BST::get_depth_helper(Node* node) {
    if (!node) {
        return 0;
    }

    int left = get_depth_helper(node->left);
    int right = get_depth_helper(node->right);
    return std::max(left, right) + 1;
}

int BST::get_biggest() {
    return get_biggest_helper(root);
}

int BST::get_biggest_helper(Node* node) {
    if (!node->right) {
        return node->value;
    }

    return get_biggest_helper(node->right);
}


int BST::get_smallest() {
    return get_smallest_helper(root);
}

int BST::get_smallest_helper(Node* node) {
    if (!node->left) {
        return node->value;
    }

    return get_smallest_helper(node->left);
}


void BST::delete_node(int value) {
    Node* node = find(value);

    if (!node) {
        std::cout << "Value " << value << " is not present in the tree" << std::endl;
        return;
    }

    std::cout << "Deleting node " << value << std::endl;

    if (!node->left && !node->right) {
        Node* parent = node->parent;
        if (parent->left == node) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete node;
    }

}