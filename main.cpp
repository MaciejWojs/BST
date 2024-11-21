#include <iostream>
#include "BST.hpp"
#include <string>

int main() {
    Node n;
    BST bst;

    std::string path = "a.txt";
    int operation;

    while (true) {

        std::cout << "---Podaj Numer Operacji---\n";
        std::cout << "1 - Dodaj element\n";
        std::cout << "2 - Usun element\n";
        std::cout << "3 - Wyswietl drzewo\n";
        std::cout << "4 - Znajdz element\n";
        std::cout << "5 - Znajdz najwiekszy\n";
        std::cout << "6 - Znajdz najmniejszy\n";
        std::cout << "7 - Wypisz drzewo\n";
        std::cout << "8 - Zapisz do pliku\n";
        std::cout << "9 - Wczytaj drzewo z pliku\n";
        std::cout << "10 - Usun cale drzewo\n";
        std::cout << "0 - Zakoncz program\n";
        std::cout << "Twoj wybor: ";
        std::cin >> operation;

        switch (operation) {
        case 0:
            std::cout << "Zamykanie programu.\n";
            return 0;

        case 1:
            {
                int value;
                std::cout << "\nPodaj wartosc: ";
                std::cin >> value;
                bst.add_node(value);
                std::cout << "Dodano element.\n";
                break;
            }

        case 2:
            {
                int value;
                std::cout << "\nPodaj wartosc do usuniecia: ";
                std::cin >> value;
                bst.delete_node(value);
                std::cout << "Usunieto element.\n";
                break;
            }

        case 3:
            bst.display_tree();
            break;

        case 4:
            {
                int value;
                std::cout << "\nPodaj szukana wartosc: ";
                std::cin >> value;
                if (bst.find(value)) {
                    std::cout << "Znaleziono element: " << value << ".\n";
                } else {
                    std::cout << "Nie znaleziono elementu: " << value << ".\n";
                }
                break;
            }

        case 5:
            std::cout << "Najwieksza wartosc to: " << bst.get_biggest() << ".\n";
            break;

        case 6:
            std::cout << "Najmniejsza wartosc to: " << bst.get_smallest() << ".\n";
            break;

        case 7:
            {
                int mode_choice;
                std::cout << "Wybierz tryb wypisywania drzewa:\n";
                std::cout << "0 - In-order\n";
                std::cout << "1 - Pre-order\n";
                std::cout << "2 - Post-order\n";
                std::cout << "Twoj wybor: ";
                std::cin >> mode_choice;

                if (mode_choice >= 0 && mode_choice <= 2) {
                    display_mode mode = static_cast<display_mode>(mode_choice);
                    bst.display(mode); // Funkcja wypisujaca drzewo w wybranym porzadku.
                } else {
                    std::cout << "Bledny wybor! Sprobuj ponownie.\n";
                }
                break;
            }

        case 8:
            //

        case 9:
            bst.load_from_text_file(path); // Funkcja wczytujaca drzewo z pliku.
            std::cout << "Drzewo wczytano z pliku " << path << ".\n";
            break;

        case 10:
            {
                char choice;
                std::cout << "Czy na pewno chcesz usunac cale drzewo? [y/n]: ";
                std::cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    bst.purge(); // Funkcja usuwajaca cale drzewo.
                    std::cout << "Usunieto cale drzewo.\n";
                } else if (choice == 'n' || choice == 'N') {
                    std::cout << "Nie usunieto drzewa.\n";
                } else {
                    std::cout << "Nieprawidlowy wybor.\n";
                }
                break;
            }

        default:
            std::cout << "Bledny numer operacji! Sprobuj ponownie.\n";
            break;
        }
    }
}