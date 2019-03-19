#include "../../Array/Array.h"
#include "../Measurement.h"

/// Klasa s³u¿¹ca do testowania wydajnoœci operacji na tablicy.
class ArrayTest
{
private:
	/// WskaŸnik na obiekt klasy tablicy.
    Array * array;
	/// Obiekt klasy s³u¿acej do wykonywania pomiarów.
    Measurement measurement;
	/// Wype³nia tablicê 'size' losowymi liczbami z przedzia³u [0, size - 1].
	/// \param size - wielkoœæ struktury.
    void populateArray(int size);
	/// Testuje wydajnoœæ dodawania elementu z przodu dla tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double addFrontTest(int size);
	/// Testuje wydajnoœæ dodawania elementu z ty³u dla tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double addBackTest(int size);
	/// Testuje wydajnoœæ dodawania elementu w losowym miejscu dla tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double addRandomTest(int size);
	/// Testuje wydajnoœæ usuwania elementu z przodu dla tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double removeFrontTest(int size);
	/// Testuje wydajnoœæ usuwania elementu z ty³u dla tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double removeBackTest(int size);
	/// Testuje wydajnoœæ usuwania elementu z losowego miejsca tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double removeRandomTest(int size);
	/// Testuje wydajnoœæ wyszukiwania elementu dla tablicy o 'size' elementach.
	/// \param size - wielkoœæ struktury.
    double findTest(int size);
public:
	/// Konstruktor klasy ArrayTest.
    ArrayTest();
	/// Destruktor klasy ArrayTest.
    ~ArrayTest();
	/// Przeprowadza testy dodania dla zdefiniowanych wielkoœci struktury.
    void addTestAverage();
	/// Przeprowadza testy usuniêcia dla zdefiniowanych wielkoœci struktury.
    void removeTestAverage();
	/// Przeprowadza testy wyszukania dla zdefiniowanych wielkoœci struktury.
    void findTestAverage();
};
