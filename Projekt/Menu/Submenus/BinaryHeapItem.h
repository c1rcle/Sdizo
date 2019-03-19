#include <iostream>
#include "../MenuItem.h"
#include "../../Heap/BinaryHeap.h"

/// Klasa submenu kopca binarnego.
class BinaryHeapItem : public MenuItem
{
private:
    /// Wskaźnik na obiekt klasy kopca.
    BinaryHeap * heap;
    /// Wyświetla dane submenu kopca.
    void printMenu() override;
    /// Ładuje kopiec z pliku.
    void loadFile();
    /// Usuwa korzeń z kopca.
    void deleteItem();
    /// Dodaje element do kopca.
    void addItem();
    /// Wyszukuje element w kopcu.
    void findItem();
    /// Tworzy losowy kopiec o podanej ilości elementów.
    void createRandom();
    /// Wyświetla kopiec.
    void display();
    /// Testuje szybkości algorytmów.
    void test();
public:
    /// Konstruktor klasy submenu kopca binarnego.
    BinaryHeapItem();
    /// Obsługuje pętle komend.
    void processInput() override;
};
