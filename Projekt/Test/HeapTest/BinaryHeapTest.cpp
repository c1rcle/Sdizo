#include "BinaryHeapTest.h"

BinaryHeapTest::BinaryHeapTest()
{
    heap = new BinaryHeap();
}

BinaryHeapTest::~BinaryHeapTest()
{
    delete heap;
}

void BinaryHeapTest::populateHeap(int size)
{
    //Dealokujemy kopiec i przydzielamy pamięć dla nowego obiektu.
    delete heap;
    heap = new BinaryHeap();
    //Wypełniamy kopiec 'size' liczbami z przedziału [0, size - 1] 
    for (int i = 0; i < size; i++) heap->push(rand() % size);
}

void BinaryHeapTest::addTestAverage()
{
    //Testy dodawania elementów dla różnych wielkości struktury.
    double results[5];
    results[0] = pushTest(1000);
    results[1] = pushTest(2000);
    results[2] = pushTest(5000);
    results[3] = pushTest(10000);
    results[4] = pushTest(20000);

    std::cout << "\nDodawanie dla 1000, 2000, 5000, 10000, 20000 elementow: " << std::endl;
    for (double result : results)
    {
        std::cout << result << " us" << std::endl;
    }
}

void BinaryHeapTest::removeTestAverage()
{
    //Testy usuwania elementów dla różnych wielkości struktury.
    double results[5];
    results[0] = popTest(1000);
    results[1] = popTest(2000);
    results[2] = popTest(5000);
    results[3] = popTest(10000);
    results[4] = popTest(20000);

    std::cout << "\nUsuwanie korzenia dla 1000, 2000, 5000, 10000, 20000 elementow: " << std::endl;
    for (double result : results)
    {
        std::cout << result << " us" << std::endl;
    }
}

void BinaryHeapTest::findTestAverage()
{
    //Testy wyszukiwania elementów dla różnych wielkości struktury.
    double results[5];
    results[0] = findTest(1000);
    results[1] = findTest(2000);
    results[2] = findTest(5000);
    results[3] = findTest(10000);
    results[4] = findTest(20000);

    std::cout << "\nWyszukiwanie dla 1000, 2000, 5000, 10000, 20000 elementow:" << std::endl;
    for (double result : results)
    {
        std::cout << result << " us" << std::endl;
    }
}

double BinaryHeapTest::pushTest(int size)
{
    //Wynik to średnia ze 100 dodań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateHeap(size);
        int element = rand() % size;
        measurement.startTimer();
        heap->push(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double BinaryHeapTest::popTest(int size)
{
    //Wynik to średnia ze 100 usunięć ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateHeap(size);
        measurement.startTimer();
        heap->pop();
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}

double BinaryHeapTest::findTest(int size)
{
    //Wynik to średnia ze 100 wyszukań ze zmienionym za każdym razem datasetem.
    double average = 0;
    for (int i = 0; i < 100; i++)
    {
        populateHeap(size);
        int element = heap->getElement(rand() % heap->getCount());
        measurement.startTimer();
        heap->find(element);
        measurement.stopTimer();
        average += measurement.getDuration();
    }
    return average / 100;
}