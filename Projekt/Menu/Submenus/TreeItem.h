#include <iostream>
#include "../MenuItem.h"
#include "../../Tree/BST.h"

/// Klasa submenu drzewa BST.
class TreeItem : public MenuItem
{
private:
    /// Wska�nik na obiekt klasy drzewa.
    BST * tree;
    /// Wy�wietla dane submenu drzewa.
    void printMenu() override;
    /// �aduje drzewo z pliku.
    void loadFile();
    /// Usuwa dany element z drzewa.
    void deleteItem();
    /// Dodaje element do drzewa.
    void addItem();
    /// Wyszukuje element w drzewie.
    void findItem();
    /// Tworzy losowe drzewo o podanej ilo�ci element�w.
    void createRandom();
    /// Wy�wietla drzewo.
    void display();
    /// Testuje szybko�ci algorytm�w.
    void test();
public:
    /// Konstruktor klasy submenu drzewa BST.
    TreeItem();
    /// Obs�uguje p�tle komend.
    void processInput() override;
};