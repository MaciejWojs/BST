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
#include <vector>

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
    POSTORDER,  /**< \~english @brief Post-order traversal / \~polish @brief Przeglądanie w porządku "post-order". */
    ALL
};

/**
 * @startuml{Node.png}
 *  class Node {
 * + int value
 * + Node* right
 * + Node* left
 * + Node* parent
 * + Node()
 * + Node(int)
 * + ~Node()
 * }
 * @enduml
 *
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
 * @startuml{BST.png}
 * class BST {
 *   +BST()
 *   +~BST()
 *   +find(int value) : Node*
 *   +get_root() : Node*
 *   +get_biggest() : int
 *   +get_depth() : int
 *   +get_smallest() : int
 *   +add_node(int node_value) : void
 *   +delete_node(int value) : void
 *   +display(display_mode mode) : void
 *   +display_tree() : void
 *   +load_from_text_file(std::string path) : void
 *   +purge() : void
 *   +save() : void
 *   -find_helper(Node* node, int value) : Node*
 *   -root : Node*
 *   -get_biggest_helper(Node* node) : int
 *   -get_depth_helper(Node* node) : int
 *   -get_smallest_helper(Node* node) : int
 *   -add_node_helper(int node_value, Node* current_root, Node* temp) : void
 *   -display_inorder(Node* node) : void
 *   -display_postorder(Node* node) : void
 *   -display_preorder(Node* node) : void
 *   -display_tree_helper(Node* node, int depth, int left, int right, std::vector<std::vector<std::string>>& levels) : void
 *   -purge_helper(Node* node) : void
 * }
 *
 * class Node {
 * + int value
 * + Node* right
 * + Node* left
 * + Node* parent
 * + Node()
 * + Node(int)
 * + ~Node()
 * }
 *
 * BST "1" -- "*" Node
 *
 * @enduml
 *
 *
 *
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
     * @brief Helper method to calculate the depth of a subtree.
     *
     * @details This recursive function calculates the depth of a subtree by
     * traversing the tree and finding the longest path from the root to a leaf node.
     *
     * @param node Pointer to the root node of the subtree.
     * @return int The depth of the subtree.
     *
     * \~polish
     * @brief Funkcja pomocnicza do obliczania głębokości poddrzewa.
     *
     * @details Ta rekurencyjna funkcja oblicza głębokość poddrzewa, przeszukując drzewo
     * i znajdując najdłuższą ścieżkę od korzenia do liścia.
     *
     * @param node Wskaźnik na korzeń poddrzewa.
     * @return int Głębokość poddrzewa.
     */
    int get_depth_helper(Node* node);

    /**
     * \~english
     * @brief Helper method to find the biggest value in the subtree.
     *
     * @param node Pointer to the root of subtree.
     * @return int Biggest value in the subtree.
     *
     * \~polish
     * @brief Metoda pomocnicza do znalezienia największej wartości w poddrzewie.
     *
     * @param node Wskaźnik na korzeń poddrzewa.
     * @return int Największa wartość w poddrzewie.
     */
    Node* get_biggest_helper(Node* node);

    /**
     * \~english
     * @brief Helper method to find the smallest value in a subtree.
     *
     * @details This recursive function traverses the leftmost path of a subtree
     * to locate and return the smallest value.
     *
     * @param node Pointer to the root node of the subtree.
     * @return int The smallest value in the subtree.
     *
     * \~polish
     * @brief Funkcja pomocnicza do znalezienia najmniejszej wartości w poddrzewie.
     *
     * @details Ta rekurencyjna funkcja przeszukuje najbardziej lewy szlak poddrzewa,
     * aby znaleźć i zwrócić najmniejszą wartość.
     *
     * @param node Wskaźnik na korzeń poddrzewa.
     * @return int Najmniejsza wartość w poddrzewie.
     */
    Node* get_smallest_helper(Node* node);

    /**
     * \~english
     * @brief Helper method to find a node with a specific value in a subtree.
     *
     * @details This recursive function searches a subtree for a node with the
     * given value and returns a pointer to it. If the value is not found, the
     * function returns `nullptr`.
     *
     * @param node Pointer to the root node of the subtree.
     * @param value The value to search for.
     * @return Node* Pointer to the node containing the value, or `nullptr` if not found.
     *
     * \~polish
     * @brief Funkcja pomocnicza do wyszukiwania węzła o określonej wartości w poddrzewie.
     *
     * @details Ta rekurencyjna funkcja przeszukuje poddrzewo w celu znalezienia węzła
     * o podanej wartości i zwraca wskaźnik na ten węzeł. Jeśli wartość nie zostanie
     * znaleziona, funkcja zwraca `nullptr`.
     *
     * @param node Wskaźnik na korzeń poddrzewa.
     * @param value Wartość do wyszukania.
     * @return Node* Wskaźnik na węzeł zawierający wartość lub `nullptr`, jeśli nie znaleziono.
     */
    Node* find_helper(Node* node, int value);

    /**
     * \~english
     * @brief Helper function for displaying binary search tree in a graphical way
     * @details The function recursively traverses through the tree and fills vector of vectors with nodes' values
     * to represent the tree structure
     * @param node Current node being processed
     * @param depth Current depth level in the tree
     * @param left Left boundary of current node's position
     * @param right Right boundary of current node's position
     * @param levels Reference to vector of vectors storing nodes' values at each level
     *
     * \~polish
     * @brief Funkcja pomocnicza do graficznego wyświetlania drzewa BST
     * @details Funkcja rekurencyjnie przechodzi przez drzewo i wypełnia wektor wektorów wartościami węzłów,
     * aby reprezentować strukturę drzewa
     * @param node Aktualnie przetwarzany węzeł
     * @param depth Aktualny poziom głębokości w drzewie
     * @param left Lewa granica pozycji aktualnego węzła
     * @param right Prawa granica pozycji aktualnego węzła
     * @param levels Referencja do wektora wektorów przechowującego wartości węzłów na każdym poziomie
     */
    void display_tree_helper(Node* node, int depth, int left, int right, std::vector<std::vector<std::string>>& levels);
    void save_helper(Node* node, std::vector<int>& result);
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
     * @brief Deletes a node with the specified value from the BST.
     *
     * @details This method searches for a node with the given value in the binary
     * search tree. If found, the node is removed while preserving the BST properties.
     *
     * @param value The value of the node to be deleted.
     *
     * \~polish
     * @brief Usuwa węzeł o określonej wartości z drzewa BST.
     *
     * @details Metoda wyszukuje węzeł o podanej wartości w drzewie BST.
     * Jeśli węzeł zostanie znaleziony, jest on usuwany przy zachowaniu zasad BST.
     *
     * @param value Wartość węzła do usunięcia.
     */
    void delete_node(int value);


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
     * @brief Purges all nodes from the BST.
     *
     * \~polish
     * @brief Usuwa wszystkie węzły z drzewa BST.
     */
    void purge();

    /**
     * \~english
     * @brief Finds a node with the specified value in the BST.
     *
     * @param value The value to search for.
     * @return Node* Pointer to the node if found, nullptr otherwise.
     *
     * \~polish
     * @brief Wyszukuje węzeł o podanej wartości w drzewie BST.
     *
     * @param value Wartość do wyszukania.
     * @return Node* Wskaźnik na węzeł, jeśli znaleziono, nullptr w przeciwnym wypadku.
     */
    Node* find(int value);

    /**
     * \~english
     * @brief Saves the current state of the BST.
     *
     * \~polish
     * @brief Zapisuje aktualny stan drzewa BST.
     */
    void save();

    /**
     * \~english
     * @brief Loads the BST from a text file.
     *
     * @details This function reads node values from a text file and inserts them into the tree.
     * @note The file should contain one integer value per line.
     *
     * @param path The path to the text file containing node values.
     *
     * \~polish
     * @brief Ładuje drzewo BST z pliku tekstowego.
     *
     * @details Funkcja odczytuje wartości węzłów z pliku tekstowego i wstawia je do drzewa.
     * @note Plik powinien zawierać jedną wartość liczbową na linię.
     *
     * @param path Ścieżka do pliku tekstowego zawierającego wartości węzłów.
     */
    void load_from_text_file(std::string path);

    /**
     * \~english
     * @brief Retrieves the depth (height) of the BST.
     *
     * @details The depth is defined as the number of edges in the longest path
     * from the root node to a leaf node. An empty tree has a depth of 0.
     *
     * @return int The depth of the BST.
     *
     * \~polish
     * @brief Pobiera głębokość (wysokość) drzewa BST.
     *
     * @details Głębokość jest definiowana jako liczba krawędzi na najdłuższej ścieżce
     * od korzenia do liścia. Puste drzewo ma głębokość 0.
     *
     * @return int Głębokość drzewa BST.
     */
    int get_depth();

    /**
     * \~english
     * @brief Retrieves the largest value in the BST.
     *
     * @return int The largest value stored in the BST.
     *
     * \~polish
     * @brief Pobiera największą wartość w drzewie BST.
     *
     * @return int Największa wartość przechowywana w drzewie BST.
     */
    int get_biggest();

    /**
     * \~english
     * @brief Retrieves the smallest value in the BST.
     *
     * @return int The smallest value stored in the BST.
     *
     * \~polish
     * @brief Pobiera najmniejszą wartość w drzewie BST.
     *
     * @return int Najmniejsza wartość przechowywana w drzewie BST.
     */
    int get_smallest();

    /**
     * \~english
     * @brief Displays the BST in a graphical format.
     *
     * @details This method visualizes the structure of the binary search tree
     * by representing nodes and their hierarchy in a graphical manner. It uses
     * a helper function to recursively build and display the tree levels.
     *
     * \~polish
     * @brief Wyświetla drzewo BST w formacie graficznym.
     *
     * @details Ta metoda wizualizuje strukturę drzewa BST, reprezentując węzły
     * i ich hierarchię w sposób graficzny. Wykorzystuje funkcję pomocniczą do
     * rekurencyjnego budowania i wyświetlania poziomów drzewa.
     */
    void display_tree();

    void load_from_binary_file();

    void save_to_binary_file();
};

#endif /* BST_HPP */
