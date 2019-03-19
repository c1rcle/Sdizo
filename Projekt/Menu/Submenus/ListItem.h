#include <iostream>
#include "../MenuItem.h"
#include "../../List/List.h"

/// Klasa dla submenu listy.
class ListItem : public MenuItem
{
private:
    /// Wskaźnik na obiekt klasy listy.
    List * list;
    /// Wyświetla dane submenu listy.
    void printMenu() override;
    /// Ładuje listę z pliku.
    void loadFile();
    /// Usuwa element listy.
    void deleteItem();
    /// Dodaje element do listy.
    void addItem();
    /// Wyszukuje element w liście.
    void findItem();
    /// Tworzy losową listę o podanym rozmiarze.
    void createRandom();
    /// Wyświetla listę.
    void display();
    /// Testuje szybkości algorytmów.
    void test();
public:
    /// Konstruktor klasy submenu listy.
    ListItem();
    /// Obsługuje pętlę komend.
    void processInput() override;
};