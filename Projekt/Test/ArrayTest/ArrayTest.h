#include "../../Array/Array.h"
#include "../Measurement.h"

/// Klasa s�u��ca do testowania wydajno�ci operacji na tablicy.
class ArrayTest
{
private:
	/// Wska�nik na obiekt klasy tablicy.
    Array * array;
	/// Obiekt klasy s�u�acej do wykonywania pomiar�w.
    Measurement measurement;
	/// Wype�nia tablic� 'size' losowymi liczbami z przedzia�u [0, size - 1].
	/// \param size - wielko�� struktury.
    void populateArray(int size);
	/// Testuje wydajno�� dodawania elementu z przodu dla tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double addFrontTest(int size);
	/// Testuje wydajno�� dodawania elementu z ty�u dla tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double addBackTest(int size);
	/// Testuje wydajno�� dodawania elementu w losowym miejscu dla tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double addRandomTest(int size);
	/// Testuje wydajno�� usuwania elementu z przodu dla tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double removeFrontTest(int size);
	/// Testuje wydajno�� usuwania elementu z ty�u dla tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double removeBackTest(int size);
	/// Testuje wydajno�� usuwania elementu z losowego miejsca tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double removeRandomTest(int size);
	/// Testuje wydajno�� wyszukiwania elementu dla tablicy o 'size' elementach.
	/// \param size - wielko�� struktury.
    double findTest(int size);
public:
	/// Konstruktor klasy ArrayTest.
    ArrayTest();
	/// Destruktor klasy ArrayTest.
    ~ArrayTest();
	/// Przeprowadza testy dodania dla zdefiniowanych wielko�ci struktury.
    void addTestAverage();
	/// Przeprowadza testy usuni�cia dla zdefiniowanych wielko�ci struktury.
    void removeTestAverage();
	/// Przeprowadza testy wyszukania dla zdefiniowanych wielko�ci struktury.
    void findTestAverage();
};
