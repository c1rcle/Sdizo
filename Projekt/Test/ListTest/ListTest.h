#include "../../List/List.h"
#include "../Measurement.h"

/// Klasa s³u¿¹ca do testowania wydajnoœci operacji na liœcie.
class ListTest
{
private:
    /// WskaŸnik na obiekt klasy listy.
    List * list;
    /// Obiekt klasy s³u¿¹cej do wykonywania pomiarów.
    Measurement measurement;
    /// Wype³nia listê 'size' losowymi liczbami z przedzia³u [0, size - 1].
    /// \param size - wielkoœæ struktury.
    void populateList(int size);
    /// Testuje wydajnoœæ dodawania elementu z przodu dla listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double addFrontTest(int size);
    /// Testuje wydajnoœæ dodawania elementu z ty³u dla listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double addBackTest(int size);
    /// Testuje wydajnoœæ dodawania elementu w losowym miejscu dla listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double addRandomTest(int size);
    /// Testuje wydajnoœæ usuwania elementu z przodu dla listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double removeFrontTest(int size);
    /// Testuje wydajnoœæ usuwania elementu z ty³u dla listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double removeBackTest(int size);
    /// Testuje wydajnoœæ usuwania elementu z losowego miejsca listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double removeRandomTest(int size);
    /// Testuje wydajnoœæ wyszukiwania elementu dla listy o 'size' elementach.
    /// \param size - wielkoœæ struktury.
    double findTest(int size);
public:
    /// Konstruktor klasy ListTest.
    ListTest();
    /// Destruktor klasy ListTest.
    ~ListTest();
    /// Przeprowadza testy dodania dla zdefiniowanych wielkoœci struktury.
    void addTestAverage();
    /// Przeprowadza testy usuniêcia dla zdefiniowanych wielkoœci struktury.
    void removeTestAverage();
    /// Przeprowadza testy wyszukania dla zdefiniowanych wielkoœci struktury.
    void findTestAverage();
};
