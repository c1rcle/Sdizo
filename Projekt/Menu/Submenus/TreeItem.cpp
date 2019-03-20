#include "TreeItem.h"
#include "../../Test/TreeTest/BSTTest.h"

TreeItem::TreeItem()
{
    //Ustawiamy zmienne definiuj¹ce opis submenu.
    menuDescription = "Drzewo BST (tree)";
    menuCommand = "tree";
}

void TreeItem::printMenu()
{
    //Wypisanie menu dla kopca.
    std::cout << std::endl;
    std::cout << "Menu dla drzewa BST" << std::endl;
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

void TreeItem::processInput()
{
    //Tworzymy nowy obiekt klasy drzewa i wchodzimy do pêtli obs³ugi opcji.
    tree = new BST();
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
    //Po wyjœciu z pêtli dealokujemy drzewo.
    delete tree;
}

void TreeItem::loadFile()
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
        delete tree;
        tree = new BST();
        file >> count;
        for (int i = 0; i < count; i++)
        {
            file >> element;
            tree->add(element);
        }
        display();
    }
    else std::cout << "Podana nazwa pliku jest nieprawidlowa!" << std::endl;
    file.close();
}

void TreeItem::deleteItem()
{
    //Usuwanie dowolnego elementu.
    int element;
    std::cout << "\nPodaj wartosc elementu do dodania: ";
    std::cin >> element;
    try
    {
        tree->remove(element);
        display();
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void TreeItem::addItem()
{
    //Dodawanie elementu do drzewa.
    int element;
    std::cout << "\nPodaj wartosc elementu do dodania: ";
    std::cin >> element;
    tree->add(element);
    display();
}

void TreeItem::findItem()
{
    //Wyszukiwanie elementu w drzewie.
    int element;
    std::cout << "\nPodaj wartosc elementu: ";
    std::cin >> element;
    if (tree->find(element)) std::cout << "Znaleziono element o takiej wartosci!" << std::endl;
    else std::cout << "Nie znaleziono elementu o takiej wartosci!" << std::endl;
    display();
}

void TreeItem::createRandom()
{
    //Dealokujemy drzewo i alokujemy pamiêæ na nowy obiekt.
    delete tree;
    tree = new BST();
    int size;
    std::cout << "\nPodaj wielkosc drzewa: ";
    std::cin >> size;
    for (int i = 0; i < size; i++) tree->add(rand() % 50 + 1);
    display();
}

void TreeItem::display()
{
    //Wyœwietlamy wizualizacjê drzewa.
    std::cout << std::endl;
    tree->printTree();
}

void TreeItem::test()
{
    //Tworzymy obiekt klasy testu drzewa i uruchamiamy metody.
    auto * test = new BSTTest();
    test->addTestAverage();
    test->removeTestAverage();
    test->findTestAverage();
    //Usuwamy obiekt z zaalokowanym, osobnym drzewem.
    delete test;
}