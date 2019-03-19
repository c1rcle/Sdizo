#pragma once
#include <iostream>
#include <string>
#include "listItem.h"

class List
{
private:
    /// Stała przechowująca opis wyjątku.
    const std::string EXCEPTION_RANGE_DESC = "Nieprawidlowy index!";
    /// Stała przechowująca opis wyjątku.
    const std::string EXCEPTION_LENGTH_DESC = "List jest pusta!";
    /// Wskaźnik na głowę listy.
    listItem * head;
    /// Wskaźnik na ogon listy.
    listItem * tail;
    /// Zmienna przechowująca ilość elementów listy.
    int size;
    /// Zwraca element listy dla podanego miejsca.
    /// \param index - miejsce w liście dla którego ma zostać zwrócony element.
    /// \return Wskaźnik na element znajdujący się na podanym miejscu.
    listItem * getItem(int index);
    /// Sprawdza czy dane miejsce nie wykracza poza szerokość listy.
    /// \param index - miejsce w liście.
    void checkIndex(int index);
public:
    /// Konstruktor klasy listy.
    List();
    /// Destruktor klasy listy.
    ~List();
    /// Dodaje nowy element z przodu listy.
    /// \param element - wartość elementu do dodania.
    void pushFront(int element);
    /// Dodaje nowy element z tyłu listy.
    /// \param element - wartość elementu do dodania
    void pushBack(int element);
    /// Dodaje nowy element za istniejącym, znajdującym się w podanym miejscu.
    /// \param index - miejsce elementu za którym zostanie dodany nowy element.
    /// \param element - wartość elementu do dodania.
    void addAfter(int index, int element);
    /// Dodaje nowy element do listy w losowym miejscu.
    void addRandom(int element);
    /// Usuwa element z przodu listy.
    void popFront();
    /// Usuwa element z tyłu listy.
    void popBack();
    /// Zwraca wartość elementu listy dla podanego miejsca.
    /// \param index - miejsce elementu, którego wartość zwracamy.
    /// \return Wartość elementu dla podanego miejsca.
    int get(int index);
    /// Sprawdza czy element o podanej wartości występuje w liście.
    /// \param element - wartość elementu do wyszukania.
    /// \return true - jeśli element został znaleziony, false - jeśli nie.
    bool find(int element);
    /// Usuwa pierwszy element od strony głowy, którego wartość równa jest podanej.
    /// \param element - wartość elementu do usunięcia.
    /// \return true - jeśli element został usunięty, false - jeśli nie znaleziono elementu.
    bool removeValue(int element);
    /// Usuwa element z podanego miejsca w liście.
    /// \param index - miejsce listy, z którego usuwamy element.
    void remove(int index);
    /// Usuwa losowy element z tablicy.
    void removeRandom();
    /// Zwraca ilość elementów listy.
    /// \return Ilość elementów listy.
    int getSize();
};
