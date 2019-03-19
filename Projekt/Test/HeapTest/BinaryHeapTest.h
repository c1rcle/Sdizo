#include "../../Heap/BinaryHeap.h"
#include "../Measurement.h"

/// Klasa s�u��ca do testowania wydajno�ci operacji na kopcu binarnym.
class BinaryHeapTest
{
private:
    /// Wska�nik na obiekt klasy kopca binarnego.
    BinaryHeap * heap;
    /// Obiekt klasy s�u�acej do wykonywania pomiar�w.
    Measurement measurement;
    /// Wype�nia kopiec 'size' losowymi liczbami z przedzia�u [0, size - 1].
    /// \param size - wielko�� struktury.
    void populateHeap(int size);
    /// Testuje wydajno�� dodawania elementu dla kopca o 'size' elementach.
    /// \param size - wielko�� struktury.
    double pushTest(int size);
    /// Testuje wydajno�� usuwania elementu dla kopca o 'size' elementach.
    /// \param size - wielko�� struktury.
    double popTest(int size);
    /// Testuje wydajno�� wyszukiwania elementu dla kopca o 'size' elementach.
    /// \param size - wielko�� struktury.
    double findTest(int size);
public:
    /// Konstruktor klasy BinaryHeapTest.
    BinaryHeapTest();
    /// Destruktor klasy BinaryHeapTest.
    ~BinaryHeapTest();
    /// Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void addTestAverage();
    /// Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void removeTestAverage();
    /// Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.
    void findTestAverage();
};