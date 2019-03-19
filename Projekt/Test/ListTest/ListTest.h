#include "../../List/List.h"
#include "../Measurement.h"

/// Klasa s�u��ca do testowania wydajno�ci operacji na li�cie.
class ListTest
{
private:
    /// Wska�nik na obiekt klasy listy.
    List * list;
    /// Obiekt klasy s�u��cej do wykonywania pomiar�w.
    Measurement measurement;
    /// Wype�nia list� 'size' losowymi liczbami z przedzia�u [0, size - 1].
    /// \param size - wielko�� struktury.
    void populateList(int size);
    /// Testuje wydajno�� dodawania elementu z przodu dla listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double addFrontTest(int size);
    /// Testuje wydajno�� dodawania elementu z ty�u dla listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double addBackTest(int size);
    /// Testuje wydajno�� dodawania elementu w losowym miejscu dla listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double addRandomTest(int size);
    /// Testuje wydajno�� usuwania elementu z przodu dla listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double removeFrontTest(int size);
    /// Testuje wydajno�� usuwania elementu z ty�u dla listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double removeBackTest(int size);
    /// Testuje wydajno�� usuwania elementu z losowego miejsca listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double removeRandomTest(int size);
    /// Testuje wydajno�� wyszukiwania elementu dla listy o 'size' elementach.
    /// \param size - wielko�� struktury.
    double findTest(int size);
public:
    /// Konstruktor klasy ListTest.
    ListTest();
    /// Destruktor klasy ListTest.
    ~ListTest();
    /// Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void addTestAverage();
    /// Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void removeTestAverage();
    /// Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.
    void findTestAverage();
};
