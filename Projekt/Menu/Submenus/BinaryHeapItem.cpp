#include "BinaryHeapItem.h"
#include "../../Test/HeapTest/BinaryHeapTest.h"

BinaryHeapItem::BinaryHeapItem()
{
	//Ustawaimy zmienne definiuj¹ce opis submenu.
    menuDescription = "Kopiec binarny (heap)";
    menuCommand = "heap";
}

void BinaryHeapItem::printMenu()
{
	//Wypisanie menu dla kopca.
	std::cout << std::endl;
    std::cout << "Menu dla kopca binarnego" << std::endl;
    std::cout << "1. Wczytaj z pliku (load)" << std::endl;
    std::cout << "2. Usun (delete)" << std::endl;
    std::cout << "3. Dodaj (add)" << std::endl;
    std::cout << "4. Znajdz (find)" << std::endl;
    std::cout << "5. Utworz losowo (rand)" << std::endl;
    std::cout << "6. Wyswietl (disp)" << std::endl;
    std::cout << "7. Testuj (test)" << std::endl;
    std::cout << "7. Wroc (back)" << std::endl;
    std::cout << "Wybierz opcje: ";
}

void BinaryHeapItem::processInput()
{
	//Tworzymy nowy obiekt klasy kopca i wchodzimy do pêtli obs³ugi opcji.
    heap = new BinaryHeap();
    std::string readConsole;
    backTyped = false;
    while (!backTyped)
    {
        printMenu();
        std::cin >> readConsole;
        if (readConsole == "load") loadFile();
        else if (readConsole == "delete") deleteItem();
        else if (readConsole == "add") addItem();
        else if (readConsole == "find") findItem();
        else if (readConsole == "rand") createRandom();
        else if (readConsole == "disp") display();
        else if (readConsole == "test") test();
        else if (readConsole == "back") backTyped = true;
        else std::cout << "Nieznane polecenie!" << std::endl;
    }
	//Po wyjœciu z pêtli dealokujemy kopiec.
    delete heap;
}

void BinaryHeapItem::loadFile()
{
	//Standardowe wczytywanie z pliku.
    std::string fileName;
    int count, element;
    std::cout << "\nPodaj nazwe pliku: ";
    std::cin >> fileName;
    std::ifstream file;
    file.open(fileName);
    if (file.is_open())
    {
        delete heap;
        heap = new BinaryHeap();
        file >> count;
        for (int i = 0; i < count; i++)
        {
            file >> element;
            heap->push(element);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidlowa!" << std::endl;
    file.close();
}

void BinaryHeapItem::deleteItem()
{
	//Usuwanie korzenia.
    try
    {
        heap->pop();
        display();
    }
    catch (std::length_error& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void BinaryHeapItem::addItem()
{
	//Dodawanie elementu do kopca.
    int element;
    std::cout << "\nPodaj wartosc elementu do dodania: ";
    std::cin >> element;
    heap->push(element);
    display();
}

void BinaryHeapItem::findItem()
{
	//Wyszukiwanie elementu w kopcu.
    int element;
    std::cout << "\nPodaj wartosc elementu: ";
    std::cin >> element;
    if (heap->find(element)) std::cout << "Znaleziono element o takiej wartosci!" << std::endl;
    else std::cout << "Nie znaleziono elementu o takiej wartosci!" << std::endl;
    display();
}

void BinaryHeapItem::createRandom()
{
	//Dealokujemy tablicê i alokujemy pamiêæ na nowy obiekt.
    delete heap;
    heap = new BinaryHeap();
    int size;
    std::cout << "\nPodaj wielkosc kopca: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) heap->push(rand() % 50 + 1);
    display();
}

void BinaryHeapItem::display()
{
	//Wyœwietlamy wizualizacjê drzewa.
	std::cout << std::endl;
    heap->printTree();
}

void BinaryHeapItem::test()
{
	//Tworzymy obiekt klasy testu kopca i uruchamiamy metody.
    auto * test = new BinaryHeapTest();
    test->addTestAverage();
    test->removeTestAverage();
    test->findTestAverage();
	//Usuwamy obiekt z zaalokowanym, osobnym kopcem.
    delete test;
}