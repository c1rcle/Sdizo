#include "BSTTest.h"

BSTTest::BSTTest()
{
    tree = new BST();
}

BSTTest::~BSTTest()
{
    delete tree;
}

int BSTTest::populateTree(int size)
{
    //Dealokujemy drzewo i przydzielamy pamiêæ dla nowego obiektu.
    delete tree;
    tree = new BST();
    //Wyznaczamy losowy indeks w celu zwrócenia losowego elementu,
    //który na pewno bêdzie znajdowa³ siê w drzewie.
    int randomIndex = rand() % size;
    int returnElement = 0;
    //Wype³niamy drzewo 'size' liczbami z przedzia³u [0, size - 1] 
    //i zapisujemy wartoœæ losowego elementu do testów usuwania/znajdowania.
    for (int i = 0; i < size; i++)
    {
        int element = rand() % size;
        if (i == randomIndex) returnElement = element;
        tree->add(element);
    }
    return returnElement;
}

void BSTTest::addTestAverage()
{
    //Testy dodawania elementów dla ró¿nych wielkoœci struktury.
    double results[5];
    results[0] = addTest(1000);
    results[1] = addTest(2000);
    results[2] = addTest(5000);
    results[3] = addTest(10000);
    results[4] = addTest(20000);

    std::cout << "\nDodawanie dla 1000, 2000, 5000, 10000, 20000 elementow: " << std::endl;
    for (double result : results)
    {
        std::cout << result << " us" << std::endl;
    }
}

void BSTTest::removeTestAverage()
{
    //Testy usuwania elementów dla ró¿nych wielkoœci struktury.
    double results[5];
    results[0] = removeTest(1000);
    results[1] = removeTest(2000);
    results[2] = removeTest(5000);
    results[3] = removeTest(10000);
    results[4] = removeTest(20000);

    std::cout << "Usuwanie dla 1000, 2000, 5000, 10000, 20000 elementow: " << std::endl;
    for (double result : results)
    {
        std::cout << result << " us" << std::endl;
    }
}

void BSTTest::findTestAverage()
{
    //Testy wyszukiwania elementów dla ró¿nych wielkoœci struktury.
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

double BSTTest::addTest(int size)
{
    //Wynik to œrednia ze 100 dodañ ze zmienionym za ka¿dym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateTree(size);
        int element = rand() % size;
        measurement.startTimer();
        tree->add(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double BSTTest::removeTest(int size)
{
    //Wynik to œrednia ze 100 usuniêæ ze zmienionym za ka¿dym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        int element = populateTree(size);
        measurement.startTimer();
        tree->remove(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double BSTTest::findTest(int size)
{
    //Wynik to œrednia ze 100 wyszukañ ze zmienionym za ka¿dym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        int element = populateTree(size);
        measurement.startTimer();
        tree->find(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}