#include "../../Tree/BST.h"
#include "../Measurement.h"

/// Klasa s³u¿¹ca do testowania wydajnoœci operacji na drzewie BST.
class BSTTest
{
private:
    /// WskaŸnik na obiekt klasy drzewa BST.
    BST * tree;
    /// Obiekt klasy s³u¿acej do wykonywania pomiarów.
    Measurement measurement;
    /// Wype³nia drzewo 'size' losowymi liczbami z przedzia³u [0, size - 1].
    /// \param size - wielkoœæ struktury.
    /// \return Losowy element, który znajdzie siê w drzewie.
    int populateTree(int size);
    /// Testuje wydajnoœæ dodawania elementu dla drzewa o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double addTest(int size);
    /// Testuje wydajnoœæ usuwania elementu dla drzewa o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double removeTest(int size);
    /// Testuje wydajnoœæ wyszukiwania elementu dla drzewa o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double findTest(int size);
public:
    /// Konstruktor klasy BSTTest.
    BSTTest();
    /// Destruktor klasy BSTTest.
    ~BSTTest();
    /// Przeprowadza testy dodania dla zdefiniowanych wielkoœci struktury.
    void addTestAverage();
    /// Przeprowadza testy usuniêcia dla zdefiniowanych wielkoœci struktury.
    void removeTestAverage();
    /// Przeprowadza testy wyszukania dla zdefiniowanych wielkoœci struktury.
    void findTestAverage();
};