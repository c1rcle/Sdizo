#include "../../Tree/BST.h"
#include "../Measurement.h"

/// Klasa s�u��ca do testowania wydajno�ci operacji na drzewie BST.
class BSTTest
{
private:
    /// Wska�nik na obiekt klasy drzewa BST.
    BST * tree;
    /// Obiekt klasy s�u�acej do wykonywania pomiar�w.
    Measurement measurement;
    /// Wype�nia drzewo 'size' losowymi liczbami z przedzia�u [0, size - 1].
    /// \param size - wielko�� struktury.
    /// \return Losowy element, kt�ry znajdzie si� w drzewie.
    int populateTree(int size);
    /// Testuje wydajno�� dodawania elementu dla drzewa o 'size' elementach.
    /// \param size - wielko�� struktury.
    double addTest(int size);
    /// Testuje wydajno�� usuwania elementu dla drzewa o 'size' elementach.
    /// \param size - wielko�� struktury.
    double removeTest(int size);
    /// Testuje wydajno�� wyszukiwania elementu dla drzewa o 'size' elementach.
    /// \param size - wielko�� struktury.
    double findTest(int size);
public:
    /// Konstruktor klasy BSTTest.
    BSTTest();
    /// Destruktor klasy BSTTest.
    ~BSTTest();
    /// Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void addTestAverage();
    /// Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void removeTestAverage();
    /// Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.
    void findTestAverage();
};