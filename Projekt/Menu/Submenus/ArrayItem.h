#include <iostream>
#include "../MenuItem.h"
#include "../../Array/Array.h"

/// Klasa submenu tablicy
class ArrayItem : public MenuItem
{
private:
    /// Wskaźnik na obiekt klasy tablicy.
    Array * array;
    /// Wyświetla dane submenu tablicy.
    void printMenu() override;
    /// Ładuje tablice z pliku.
    void loadFile();
    /// Usuwa element z tablicy.
    void deleteItem();
    /// Dodaje element do tablicy.
    void addItem();
    /// Wyszukuje element w tablicy.
    void findItem();
    /// Tworzy losową tablicę o wielkości podanej przez użytkownika.
    void createRandom();
    /// Wyświetla zawartość tablicy.
    void display();
    /// Testuje szybkości algorytmów.
    void test();
public:
    /// Konstruktor klasy submenu tablicy.
    ArrayItem();
    /// Obsługuje pętlę komend.
    void processInput() override;
};
