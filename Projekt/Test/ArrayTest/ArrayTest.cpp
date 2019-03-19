#include "ArrayTest.h"

ArrayTest::ArrayTest()
{
    array = new Array();
}

ArrayTest::~ArrayTest()
{
    delete array;
}

void ArrayTest::populateArray(int size)
{
    //Dealokujemy tablicę i przydzielamy pamięć dla nowego obiektu.
    delete array;
    array = new Array();
    //Dodajemy 'size' liczb z przedziału [0, size - 1].
    for (int i = 0; i < size; i++) array->add(rand() % size);
}

void ArrayTest::addTestAverage()
{
    //Testy dodawania elementów z przodu tablicy.
    double results[3][5];
    results[0][0] = addFrontTest(1000);
    results[0][1] = addFrontTest(2000);
    results[0][2] = addFrontTest(5000);
    results[0][3] = addFrontTest(10000);
    results[0][4] = addFrontTest(20000);

    //Testy dodawania elementów z tyłu tablicy.
    results[1][0] = addBackTest(1000);
    results[1][1] = addBackTest(2000);
    results[1][2] = addBackTest(5000);
    results[1][3] = addBackTest(10000);
    results[1][4] = addBackTest(20000);

    //Testy dodawania elementów w losowym miejscu tablicy.
    results[2][0] = addRandomTest(1000);
    results[2][1] = addRandomTest(2000);
    results[2][2] = addRandomTest(5000);
    results[2][3] = addRandomTest(10000);
    results[2][4] = addRandomTest(20000);

    std::cout << "\nDodawanie front/back/random dla 1000, 2000, 5000, 10000, 20000 elementow: " << std::endl;
    for (auto &result : results)
    {
        for (double j : result) std::cout << j << " us" << std::endl;
        std::cout << std::endl;
    }
}

void ArrayTest::removeTestAverage()
{
    //Testy usuwania elementów z przodu tablicy.
    double results[3][5];
    results[0][0] = removeFrontTest(1000);
    results[0][1] = removeFrontTest(2000);
    results[0][2] = removeFrontTest(5000);
    results[0][3] = removeFrontTest(10000);
    results[0][4] = removeFrontTest(20000);

    //Testy usuwania elementów z tyłu tablicy.
    results[1][0] = removeBackTest(1000);
    results[1][1] = removeBackTest(2000);
    results[1][2] = removeBackTest(5000);
    results[1][3] = removeBackTest(10000);
    results[1][4] = removeBackTest(20000);

    //Testy usuwania elementów z losowego miejsca tablicy.
    results[2][0] = removeRandomTest(1000);
    results[2][1] = removeRandomTest(2000);
    results[2][2] = removeRandomTest(5000);
    results[2][3] = removeRandomTest(10000);
    results[2][4] = removeRandomTest(20000);

    std::cout << "Usuwanie front/back/random dla 1000, 2000, 5000, 10000, 20000 elementow: " << std::endl;
    for (auto &result : results)
    {
        for (double j : result) std::cout << j << " us" << std::endl;
        std::cout << std::endl;
    }
}

void ArrayTest::findTestAverage()
{
    //Testy wyszukiwania elementów dla różnych rozmiarów struktury.
    double results[5];
    results[0] = findTest(1000);
    results[1] = findTest(2000);
    results[2] = findTest(5000);
    results[3] = findTest(10000);
    results[4] = findTest(20000);

    std::cout << "Wyszukiwanie dla 1000, 2000, 5000, 10000, 20000 elementow:" << std::endl;
    for (double result : results)
    {
        std::cout << result << " us" << std::endl;
    }
}

double ArrayTest::addFrontTest(int size)
{
    //Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        int element = rand() % size;
        measurement.startTimer();
        array->addFront(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ArrayTest::addBackTest(int size)
{
    //Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        int element = rand() % size;
        measurement.startTimer();
        array->add(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ArrayTest::addRandomTest(int size)
{
    //Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        int element = rand() % size;
        measurement.startTimer();
        array->addRandom(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ArrayTest::removeFrontTest(int size)
{
    //Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        measurement.startTimer();
        array->remove(0);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ArrayTest::removeBackTest(int size)
{
    //Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        int index = size - 1;
        measurement.startTimer();
        array->remove(index);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ArrayTest::removeRandomTest(int size)
{
    //Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        measurement.startTimer();
        array->removeRandom();
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ArrayTest::findTest(int size)
{
    //Wynik to średnia ze 100 wyszukań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateArray(size);
        int element = array->get(rand() % array->getSize());
        measurement.startTimer();
        array->find(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}