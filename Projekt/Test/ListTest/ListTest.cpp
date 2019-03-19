#include "ListTest.h"

ListTest::ListTest()
{
    list = new List();
}

ListTest::~ListTest()
{
    delete list;
}

void ListTest::populateList(int size)
{
	//Dealokujemy listę i przydzielamy pamięć dla nowego obiektu.
    delete list;
    list = new List();
	//Dodajemy 'size' liczb z przedziału [0, size - 1].
    for (int i = 0; i < size; i++) list->pushBack(rand() % size);
}

void ListTest::addTestAverage()
{
	//Testy dodawania elementów z przodu listy.
    double results[3][5];
    results[0][0] = addFrontTest(1000);
    results[0][1] = addFrontTest(2000);
    results[0][2] = addFrontTest(5000);
    results[0][3] = addFrontTest(10000);
    results[0][4] = addFrontTest(20000);

	//Testy dodawania elementów z tyłu listy.
    results[1][0] = addBackTest(1000);
    results[1][1] = addBackTest(2000);
    results[1][2] = addBackTest(5000);
    results[1][3] = addBackTest(10000);
    results[1][4] = addBackTest(20000);

	//Testy dodawania elementów w losowym miejscu listy.
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

void ListTest::removeTestAverage()
{
	//Testy usuwania elementów z przodu listy.
    double results[3][5];
    results[0][0] = removeFrontTest(1000);
    results[0][1] = removeFrontTest(2000);
    results[0][2] = removeFrontTest(5000);
    results[0][3] = removeFrontTest(10000);
    results[0][4] = removeFrontTest(20000);

	//Testy usuwania elementów z tyłu listy.
    results[1][0] = removeBackTest(1000);
    results[1][1] = removeBackTest(2000);
    results[1][2] = removeBackTest(5000);
    results[1][3] = removeBackTest(10000);
    results[1][4] = removeBackTest(20000);

	//Testy usuwania elementów w losowym miejscu listy.
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

void ListTest::findTestAverage()
{
	//Testy wyszukiwania elementów listy.
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

double ListTest::addFrontTest(int size)
{
	//Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        int element = rand() % size;
        measurement.startTimer();
        list->pushFront(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ListTest::addBackTest(int size)
{
	//Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        int element = rand() % size;
        measurement.startTimer();
        list->pushBack(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ListTest::addRandomTest(int size)
{
	//Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        int element = rand() % size;
        measurement.startTimer();
        list->addRandom(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ListTest::removeFrontTest(int size)
{
	//Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        measurement.startTimer();
        list->popFront();
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ListTest::removeBackTest(int size)
{
	//Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        measurement.startTimer();
        list->popBack();
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ListTest::removeRandomTest(int size)
{
	//Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        measurement.startTimer();
        list->removeRandom();
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double ListTest::findTest(int size)
{
	//Wynik to średnia ze 100 wyszukań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateList(size);
        int element = list->get(rand() % list->getSize());
        measurement.startTimer();
        list->find(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}