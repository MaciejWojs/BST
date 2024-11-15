/**
 * \~english
 * @file BST.hpp
 * @brief Binary Search Tree (BST) implementation header file.
 *
 * @details This file contains the declaration of the binary search tree (BST)
 * class and its node structure, as well as functions for managing the tree
 * and its traversal.
 *
 * \~polish
 * @file BST.hpp
 * @brief Plik nagłówkowy implementacji drzewa BST.
 *
 * @details Zawiera deklarację klasy drzewa wyszukiwania binarnego (BST)
 * oraz jego struktury węzłów i funkcji do zarządzania drzewem oraz jego przeglądaniem.
 */

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>

 /**
  * \~english
  * @enum display_mode
  * @brief Enum representing traversal order.
  *
  * @details This enumeration is used to specify the order for displaying
  * the binary search tree.
  *
  * \~polish
  * @enum display_mode
  * @brief Enum reprezentujący kolejność przeglądania.
  *
  * @details Enum służy do określenia kolejności wyświetlania drzewa BST.
  */
enum display_mode {
    INORDER,   /**< \~english @brief In-order traversal / \~polish @brief Przeglądanie w porządku "in-order". */
    PREORDER,  /**< \~english @brief Pre-order traversal / \~polish @brief Przeglądanie w porządku "pre-order". */
    POSTORDER  /**< \~english @brief Post-order traversal / \~polish @brief Przeglądanie w porządku "post-order". */
};

/**
 * \~english
 * @struct Node
 * @brief Represents a single node in a binary search tree.
 *
 * @details This structure holds the value of the node and pointers
 * to its left, right, and parent nodes.
 *
 * \~polish
 * @struct Node
 * @brief Reprezentuje pojedynczy węzeł w drzewie BST.
 *
 * @details Struktura przechowująca wartość węzła oraz wskaźniki na jego
 * lewe, prawe dziecko i rodzica.
 */
struct Node {
    int value;          /**< \~english @brief Value of the node / \~polish @brief Wartość węzła. */
    Node* right;        /**< \~english @brief Pointer to the right child / \~polish @brief Wskaźnik na prawe dziecko. */
    Node* left;         /**< \~english @brief Pointer to the left child / \~polish @brief Wskaźnik na lewe dziecko. */
    Node* parent;       /**< \~english @brief Pointer to the parent node / \~polish @brief Wskaźnik na rodzica. */

    /**
     * \~english
     * @brief Default constructor for Node.
     *
     * \~polish
     * @brief Domyślny konstruktor dla węzła.
     */
    Node();

    /**
     * \~english
     * @brief Constructor initializing Node with a specific value.
     *
     * @param _value Value to assign to the node.
     *
     * \~polish
     * @brief Konstruktor inicjalizujący węzeł z określoną wartością.
     *
     * @param _value Wartość przypisana do węzła.
     */
    Node(int _value);

    /**
     * \~english
     * @brief Destructor for Node.
     *
     * \~polish
     * @brief Destruktor dla węzła.
     */
    ~Node();

    /**
     * \~english
     * @brief Overloaded stream insertion operator for Node.
     *
     * This operator allows the Node object to be output to an output stream.
     *
     * @param stream The output stream to write to.
     * @param node The Node object to output.
     * @return std::ostream& The output stream after writing the Node.
     *
     * \~polish
     * @brief Przeciążony operator wstawiania strumienia dla węzła.
     *
     * Ten operator pozwala na wypisanie obiektu Node do strumienia wyjściowego.
     *
     * @param stream Strumień wyjściowy do zapisu.
     * @param node Obiekt Node do wypisania.
     * @return std::ostream& Strumień wyjściowy po zapisie obiektu Node.
     */
    friend std::ostream& operator<<(std::ostream& stream, const Node* node);
};

/**
 * \~english
 * @class BST
 * @brief Binary Search Tree class.
 *
 * @details This class provides methods for managing a binary search tree,
 * including adding, deleting, displaying nodes, and saving the tree.
 *
 * \~polish
 * @class BST
 * @brief Klasa reprezentująca drzewo BST.
 *
 * @details Klasa ta oferuje metody zarządzania drzewem wyszukiwania binarnego,
 * w tym dodawanie, usuwanie, wyświetlanie węzłów oraz zapisywanie drzewa.
 */
class BST {
    private:
    Node* root; /**< \~english @brief Pointer to the root node / \~polish @brief Wskaźnik na korzeń drzewa. */

    /**
     * \~english
     * @brief Helper function to recursively add a node to the BST.
     *
     * @details This function is used internally to traverse the tree and insert
     * a new node in the correct location according to BST rules.
     *
     * @param node_value The value of the new node to add.
     * @param current_root Pointer to the current root being processed.
     * @param temp Temporary pointer for node manipulation.
     *
     * \~polish
     * @brief Funkcja pomocnicza do rekurencyjnego dodawania węzła do drzewa BST.
     *
     * @details Funkcja ta jest używana wewnętrznie do przeglądania drzewa i wstawiania
     * nowego węzła w odpowiednim miejscu zgodnie z zasadami BST.
     *
     * @param node_value Wartość nowego węzła do dodania.
     * @param current_root Wskaźnik na aktualnie przetwarzany korzeń.
     * @param temp Tymczasowy wskaźnik do manipulacji węzłami.
     */
    void add_node_helper(int node_value, Node* current_root, Node* temp);

    /**
     * \~english
     * @brief Helper function to recursively delete all nodes in the subtree.
     *
     * @details This function is used internally to traverse the subtree rooted at the given node
     * and delete all nodes to free up memory.
     *
     * @param node Pointer to the root node of the subtree to be deleted.
     *
     * \~polish
     * @brief Funkcja pomocnicza do rekurencyjnego usuwania wszystkich węzłów w poddrzewie.
     *
     * @details Funkcja ta jest używana wewnętrznie do przeglądania poddrzewa zakorzenionego w danym węźle
     * i usuwania wszystkich węzłów w celu zwolnienia pamięci.
     *
     * @param node Wskaźnik na korzeń poddrzewa do usunięcia.
     */
    void purge_helper(Node* node);

    /**
     * \~english
     * @brief Helper function for in-order traversal and display.
     *
     * @param node Pointer to the current node being processed.
     *
     * \~polish
     * @brief Funkcja pomocnicza dla przeglądania i wyświetlania w porządku in-order.
     *
     * @param node Wskaźnik na aktualnie przetwarzany węzeł.
     */
    void display_inorder(Node* node);

    void display_helper(Node* node);

    public:
    /**
     * \~english
     * @brief Retrieves the root node of the BST.
     *
     * @return Node* Pointer to the root node.
     *
     * \~polish
     * @brief Pobiera korzeń drzewa BST.
     *
     * @return Node* Wskaźnik na korzeń drzewa.
     */
    Node* get_root() {
        return root;
    }

    /**
     * \~english
     * @brief Default constructor for BST.
     *
     * \~polish
     * @brief Domyślny konstruktor dla drzewa BST.
     */
    BST();

    /**
     * \~english
     * @brief Destructor for BST.
     *
     * \~polish
     * @brief Destruktor dla drzewa BST.
     */
    ~BST();

    /**
     * \~english
     * @brief Adds a new node to the BST.
     *
     * @param node_value The value of the new node to add.
     *
     * \~polish
     * @brief Dodaje nowy węzeł do drzewa BST.
     *
     * @param node_value Wartość nowego węzła do dodania.
     */
    void add_node(int node_value);

    /**
     * \~english
     * @brief Deletes a node from the BST.
     *
     * \~polish
     * @brief Usuwa węzeł z drzewa BST.
     */
    void delete_node();

    /**
     * \~english
     * @brief Displays the BST in a specified order.
     *
     * @param mode The display mode to use (INORDER, PREORDER, POSTORDER).
     *
     * \~polish
     * @brief Wyświetla drzewo BST w określonej kolejności.
     *
     * @param mode Tryb wyświetlania (INORDER, PREORDER, POSTORDER).
     */
    void display(display_mode mode);

    /**
     * \~english
     * @brief Helper function for pre-order traversal and display.
     *
     * @param node Pointer to the current node being processed.
     *
     * \~polish
     * @brief Funkcja pomocnicza dla przeglądania i wyświetlania w porządku pre-order.
     *
     * @param node Wskaźnik na aktualnie przetwarzany węzeł.
     */
    void display_preorder(Node* node);

    /**
     * \~english
     * @brief Helper function for post-order traversal and display.
     *
     * @param node Pointer to the current node being processed.
     *
     * \~polish
     * @brief Funkcja pomocnicza dla przeglądania i wyświetlania w porządku post-order.
     *
     * @param node Wskaźnik na aktualnie przetwarzany węzeł.
     */
    void display_postorder(Node* node);

    /**
     * \~english
     * @brief Purges all nodes from the BST.
     *
     * \~polish
     * @brief Usuwa wszystkie węzły z drzewa BST.
     */
    void purge();

    /**
     * \~english
     * @brief Saves the current state of the BST.
     *
     * \~polish
     * @brief Zapisuje aktualny stan drzewa BST.
     */
    void save();

    void load_from_text_file(std::string path);
};

#endif /* BST_HPP */
