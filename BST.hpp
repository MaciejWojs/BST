#ifndef BST_HPP
#define BST_HPP
enum display_mode {
    INORDER,
    PREORDER,
    POSTORDER
};
struct Node {
    int value;
    Node* right;
    Node* left;
    Node* parent;

    Node();
    Node(int _value);
    ~Node();

    void set_value(int a);
    int get_value();
};


class BST {
    private:
    Node* root;
    public:
    BST();
    ~BST();
    void add_node();
    void delete_node();
    void purge();
    void display(display_mode mode);
    void save();
};



#endif /* BST_HPP */
