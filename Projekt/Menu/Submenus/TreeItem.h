#include <iostream>
#include "../MenuItem.h"
#include "../../Tree/BST.h"

/// Klasa submenu drzewa BST.
class TreeItem : public MenuItem
{
private:
    /// WskaŸnik na obiekt klasy drzewa.
    BST * tree;
    /// Wyœwietla dane submenu drzewa.
    void printMenu() override;
    /// £aduje drzewo z pliku.
    void loadFile();
    /// Usuwa dany element z drzewa.
    void deleteItem();
    /// Dodaje element do drzewa.
    void addItem();
    /// Wyszukuje element w drzewie.
    void findItem();
    /// Tworzy losowe drzewo o podanej iloœci elementów.
    void createRandom();
    /// Wyœwietla drzewo.
    void display();
    /// Testuje szybkoœci algorytmów.
    void test();
public:
    /// Konstruktor klasy submenu drzewa BST.
    TreeItem();
    /// Obs³uguje pêtle komend.
    void processInput() override;
};