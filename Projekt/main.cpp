#include <iostream>
#include <ctime>
#include "Menu/Menu.h"

int main()
{
	//Mo¿liwoœæ wyœwietlania znaków UTF-8 w konsoli Windows.
	std::system("@chcp 65001 >nul");
    std::srand(std::time(nullptr));
    auto * menu = new Menu();
    auto * array = new ArrayItem();
    auto * list = new ListItem();
    auto * heap = new BinaryHeapItem();
    menu->addMenuItem(array);
    menu->addMenuItem(list);
    menu->addMenuItem(heap);
    menu->processInput();
    delete menu;
    return 0;
}