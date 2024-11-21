#include <iostream>
#include "BST.hpp"
#include <string>

int main() {
    Node n;
    BST bst;

    std::string path = "a.txt";
    int operation;

    while (true) {

        std::cout << "---Enter Operation Number---\n";
        std::cout << "1 - Add element\n";
        std::cout << "2 - Remove element\n";
        std::cout << "3 - Display tree\n";
        std::cout << "4 - Find element\n";
        std::cout << "5 - Find largest element\n";
        std::cout << "6 - Find smallest element\n";
        std::cout << "7 - Print tree\n";
        std::cout << "8 - Save to file\n";
        std::cout << "9 - Load tree from file\n";
        std::cout << "10 - Remove entire tree\n";
        std::cout << "0 - Exit program\n";
        std::cout << "Your choice: ";
        std::cin >> operation;

        switch (operation) {
        case 0:
            std::cout << "Closing the program.\n";
            return 0;

        case 1:
            {
                int value;
                std::cout << "\nEnter value: ";
                std::cin >> value;
                bst.add_node(value);
                std::cout << "Element added.\n";
                break;
            }

        case 2:
            {
                int value;
                std::cout << "\nEnter value to remove: ";
                std::cin >> value;
                bst.delete_node(value);
                std::cout << "Element removed.\n";
                break;
            }

        case 3:
            bst.display_tree();
            break;

        case 4:
            {
                int value;
                std::cout << "\nEnter value to search for: ";
                std::cin >> value;
                if (bst.find(value)) {
                    std::cout << "Found element: " << value << ".\n";
                } else {
                    std::cout << "Element not found: " << value << ".\n";
                }
                break;
            }

        case 5:
            std::cout << "The largest value is: " << bst.get_biggest() << ".\n";
            break;

        case 6:
            std::cout << "The smallest value is: " << bst.get_smallest() << ".\n";
            break;

        case 7:
            {
                int mode_choice;
                std::cout << "Choose tree display mode:\n";
                std::cout << "0 - In-order\n";
                std::cout << "1 - Pre-order\n";
                std::cout << "2 - Post-order\n";
                std::cout << "3 - All of the above\n";
                std::cout << "Your choice: ";
                std::cin >> mode_choice;

                if (mode_choice >= 0 && mode_choice <= 3) {
                    display_mode mode = static_cast<display_mode>(mode_choice);
                    bst.display(mode);
                } else {
                    std::cout << "Invalid choice! Try again.\n";
                }
                break;
            }

        case 8:
            // (Missing implementation for saving tree to file)
            break;

        case 9:
            bst.load_from_text_file(path);
            std::cout << "Tree loaded from file " << path << ".\n";
            break;

        case 10:
            {
                char choice;
                std::cout << "Are you sure you want to delete the entire tree? [y/n]: ";
                std::cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    bst.purge();
                    std::cout << "Entire tree removed.\n";
                } else if (choice == 'n' || choice == 'N') {
                    std::cout << "Tree not removed.\n";
                } else {
                    std::cout << "Invalid choice.\n";
                }
                break;
            }

        default:
            std::cout << "Invalid operation number! Try again.\n";
            break;
        }
        std::cout << "Press enter to continue\n";
        std::cin.get();std::cin.get();
    }
}
