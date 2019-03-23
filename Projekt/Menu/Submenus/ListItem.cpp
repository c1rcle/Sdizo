#include "ListItem.h"
#include "../../Test/ListTest/ListTest.h"

ListItem::ListItem()
{
    //Ustawiamy zmienne definiujące opis submenu.
    menuDescription = "Lista (list)";
    menuCommand = "list";
}

void ListItem::printMenu()
{
    //Wypisanie menu dla listy.
    std::cout << std::endl;
    std::cout << "Menu dla listy" << std::endl;
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

void ListItem::processInput()
{
    //Tworzymy nowy obiekt klasy listy i wchodzimy do pętli obsługi opcji.
    list = new List();
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
    //Po wyjściu z pętli dealokujemy listę.
    delete list;
}

void ListItem::loadFile()
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
        delete list;
        list = new List();
        file >> count;
        for (int i = 0; i < count; i++)
        {
            file >> element;
            list->pushBack(element);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidlowa!" << std::endl;
    file.close();
}

void ListItem::deleteItem()
{
    //Usuwanie elementu dla danej wartości.
    int element;
    std::cout << "\nPodaj wartosc elementu do usuniecia: ";
    std::cin >> element;
    if (!list->removeValue(element))
        std::cout << "Nie znaleziono takiego elementu!" << std::endl;
    display();
}

void ListItem::addItem()
{
    //Dodawanie elementu dla danego indeksu.
    int index;
    int element;
    std::cout << "\nPodaj index elementu do dodania: ";
    std::cin >> index;
    std::cout << "Podaj wartosc elementu: ";
    std::cin >> element;
    try
    {
        if (index == 0) list->pushFront(element);
        else list->addAfter(index - 1, element);
        display();
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ListItem::findItem()
{
    //Wyszukiwanie elementu.
    int element;
    std::cout << "\nPodaj wartosc elementu: ";
    std::cin >> element;
    if (list->find(element)) std::cout << "Znaleziono element o takiej wartosci!" << std::endl;
    else std::cout << "Nie znaleziono elementu o takiej wartosci!" << std::endl;
    display();
}

void ListItem::createRandom()
{
    //Dealokujemy listę i rezerwujemy pamięć na nowy obiekt.
    delete list;
    list = new List();
    int size;
    std::cout << "\nPodaj wielkosc listy: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) list->pushBack(rand() % 50 + 1);
    display();
}

void ListItem::display()
{
    //Wyświetlamy zawartość listy (przód, tył).
    std::cout << "\nZawartosc listy: ";
    for (int i = 0; i < list->getSize(); i++) std::cout << list->get(i) << " ";
    std::cout << std::endl;
    for (int i = list->getSize() - 1; i > -1; i--) std::cout << list->get(i) << " ";
    std::cout << std::endl;
}

void ListItem::test()
{
    //Tworzymy obiekt klasy testu listy i uruchamiamy metody.
    auto * test = new ListTest();
    test->addTestAverage();
    test->removeTestAverage();
    test->findTestAverage();
    //Usuwamy obiekt z zaalokowaną, osobną listą.
    delete test;
}