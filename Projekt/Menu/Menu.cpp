#include "Menu.h"

//Klasie menu wystarczy domyślny konstruktor.
Menu::Menu() = default;

Menu::~Menu()
{
    //Usuwamy każdy element menu.
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
    //Dla każdego submenu (w kolejności dodania) wyświetlamy jego opis.
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
    //Wczytujemy dane z konsoli do 'readConsole' i wykonujemy funkcję 'processInput()'
    //dla elementu menu, którego komenda zgadza się z podaną.
    std::string readConsole;
    quitTyped = false;
    while (!quitTyped)
    {
        printMenu();
        std::cin >> readConsole;
        unknownInput = true;
        //Jeśli komenda to 'quit' ustawiamy flagi aby umożliwić wyjście z pętli obsługi.
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