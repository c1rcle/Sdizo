#include "../../Heap/BinaryHeap.h"
#include "../Measurement.h"

/// Klasa s³u¿¹ca do testowania wydajnoœci operacji na kopcu binarnym.
class BinaryHeapTest
{
private:
    /// WskaŸnik na obiekt klasy kopca binarnego.
    BinaryHeap * heap;
    /// Obiekt klasy s³u¿acej do wykonywania pomiarów.
    Measurement measurement;
    /// Wype³nia kopiec 'size' losowymi liczbami z przedzia³u [0, size - 1].
    /// \param size - wielkoœæ struktury.
    void populateHeap(int size);
    /// Testuje wydajnoœæ dodawania elementu dla kopca o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double pushTest(int size);
    /// Testuje wydajnoœæ usuwania elementu dla kopca o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double popTest(int size);
    /// Testuje wydajnoœæ wyszukiwania elementu dla kopca o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double findTest(int size);
public:
    /// Konstruktor klasy BinaryHeapTest.
    BinaryHeapTest();
    /// Destruktor klasy BinaryHeapTest.
    ~BinaryHeapTest();
    /// Przeprowadza testy dodania dla zdefiniowanych wielkoœci struktury.
    void addTestAverage();
    /// Przeprowadza testy usuniêcia dla zdefiniowanych wielkoœci struktury.
    void removeTestAverage();
    /// Przeprowadza testy wyszukania dla zdefiniowanych wielkoœci struktury.
    void findTestAverage();
};