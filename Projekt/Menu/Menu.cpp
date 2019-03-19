#include "Menu.h"

//Klasie menu wystarczy domy�lny konstruktor.
Menu::Menu() = default;

Menu::~Menu()
{
    //Usuwamy ka�dy element menu.
    for (auto item : items)
    {
        delete item;
    }
}

void Menu::addMenuItem(MenuItem *item)
{
    //Dodajemy submenu.
    items.push_back(item);
}

void Menu::printMenu()
{
    //Dla ka�dego submenu (w kolejno�ci dodania) wy�wietlamy jego opis.
    std::cout << std::endl;
    std::cout << "Menu aplikacji" << std::endl;
    int i = 1;
    for (MenuItem * item : items)
    {
        std::cout << i << ". " << item->getMenuDescription() << std::endl;
        i++;
    }
    std::cout << i << ". " << "Wyjdz (quit)" << std::endl;
    std::cout << "Wybierz opcje: ";
}

void Menu::processInput()
{
    //Wczytujemy dane z konsoli do 'readConsole' i wykonujemy funkcj� 'processInput()'
    //dla elementu menu, kt�rego komenda zgadza si� z podan�.
    std::string readConsole;
    quitTyped = false;
    while (!quitTyped)
    {
        printMenu();
        std::cin >> readConsole;
        unknownInput = true;
        //Je�li komenda to 'quit' ustawiamy flagi aby umo�liwi� wyj�cie z p�tli obs�ugi.
        if (readConsole == "quit")
        {
            quitTyped = true;
            unknownInput = false;
        }

        for (MenuItem * item : items)
        {
            if (readConsole == item->getMenuCommand())
            {
                item->processInput();
                unknownInput = false;
            }
        }
        if (unknownInput) std::cout << "Nieznane polecenie!" << std::endl;
    }
}