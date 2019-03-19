#include "ArrayItem.h"
#include "../../Test/ArrayTest/ArrayTest.h"

ArrayItem::ArrayItem()
{
    //Ustawiamy zmienne definiujące opis submenu.
    menuDescription = "Tablica (array)";
    menuCommand = "array";
}

void ArrayItem::printMenu()
{
    //Wypisane menu dla tablicy.
    std::cout << std::endl;
    std::cout << "Menu dla tablicy" << std::endl;
    std::cout << "1. Wczytaj z pliku (load)" << std::endl;
    std::cout << "2. Usun (delete)" << std::endl;
    std::cout << "3. Dodaj (add)" << std::endl;
    std::cout << "4. Znajdz (find)" << std::endl;
    std::cout << "5. Utworz losowo (rand)" << std::endl;
    std::cout << "6. Wyswietl (disp)" << std::endl;
    std::cout << "7. Testuj (test)" << std::endl;
    std::cout << "8. Wroc (back)" << std::endl;
    std::cout << "Wybierz opcje: ";
}

void ArrayItem::processInput()
{
    //Tworzymy nowy obiekt klasy Array i wchodzimy do pętli obsługi opcji.
    array = new Array();
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
    //Po wyjściu z pętli dealokujemy tablicę.
    delete array;
}

void ArrayItem::loadFile()
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
        delete array;
        array = new Array();
        file >> count;
        for (int i = 0; i < count; i++)
        {
            file >> element;
            array->add(element);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidlowa!" << std::endl;
    file.close();
}

void ArrayItem::deleteItem()
{
    //Usuwanie elementu dla danego indexu.
    int index;
    std::cout << "\nPodaj index elementu do usuniecia: ";
    std::cin >> index;
    try
    {
        array->remove(index);
        display();
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ArrayItem::addItem()
{
    //Dodawanie elementu dla danego indexu.
    int index;
    int element;
    std::cout << "\nPodaj index elementu do dodania: ";
    std::cin >> index;
    std::cout << "Podaj wartosc elementu: ";
    std::cin >> element;
    try
    {
        array->add(index, element);
        display();
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ArrayItem::findItem()
{
    //Wyszukiwanie elementu.
    int element;
    std::cout << "\nPodaj wartosc elementu: ";
    std::cin >> element;
    if (array->find(element)) std::cout << "Znaleziono element o takiej wartosci!" << std::endl;
    else std::cout << "Nie znaleziono elementu o takiej wartosci!" << std::endl;
    display();
}

void ArrayItem::createRandom()
{
    //Dealokujemy tablicę i alokujemy pamięć na nowy obiekt.
    delete array;
    array = new Array();
    int size;
    std::cout << "\nPodaj wielkosc tablicy: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) array->add(rand() % 50 + 1);
    display();
}

void ArrayItem::display()
{
    //Wyświetlamy zawartość tablicy.
    std::cout << "\nZawartosc tablicy: ";
    for (int i = 0; i < array->getSize(); i++) std::cout << array->get(i) << " ";
    std::cout << std::endl;
}

void ArrayItem::test()
{
    //Tworzymy obiekt klasy testu tablicy i uruchamiamy metody.
    auto * test = new ArrayTest();
    test->addTestAverage();
    test->removeTestAverage();
    test->findTestAverage();
    //Usuwamy obiekt z zaalokowaną, osobną tablicą.
    delete test;
}