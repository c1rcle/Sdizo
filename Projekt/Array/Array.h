#pragma once
#include <iostream>
#include <string>

/// Klasa dla tablicy.
class Array
{
private:
    /// Stała przechowująca opis wyjątku.
    const std::string EXCEPTION_DESC = "Nieprawidlowy index!";
    /// Wskaźnik na początek tablicy.
    int * base;
    /// Zmienna przechowująca ilość elementów w tablicy.
    int size;
    /// Sprawdza czy dane miejsce nie wykracza poza szerokość tablicy.
    /// \param index - miejsce w tablicy.
    void checkIndex(int index);
    /// Kopiuje daną ilość elementów z tablicy źródłowej do docelowej.
    /// \param source - wskaźnik na pierwszy element tablicy źródłowej.
    /// \param destination - wskaźnik na pierwszy element tablicy docelowej.
    /// \param size - ilość elementów do przekopiowania.
    void copyArray(int * source, int * destination, int size);
public:
    /// Konstruktor klasy tablicy
    Array();
    ///Destruktor klasy tablicy
    ~Array();
    /// Zwraca wartość elementu znajdującego się w podanym miejscu.
    /// \param index - miejsce w tablicy, z którego ma zostać pobrany element.
    /// \return Wartość elementu dla podanego miejsca.
    int get(int index);
    /// Sprawdza czy element o podanej wartości występuje w tablicy.
    /// \param element - wartość elementu do wyszukania.
    /// \return true - jeśli element został znaleziony, false - jeśli nie.
    bool find(int element);
    /// Dodaje nowy element na koniec tablicy.
    /// \param element - wartość nowego elementu.
    void add(int element);
    /// Dodaje nowy element do tablicy w podanym miejscu.
    /// \param index - miejsce w tablicy, w którym znajdzie się nowy element.
    /// \param element - wartość nowego elementu.
    void add(int index, int element);
    /// Dodaje nowy element na początku tablicy.
    /// \param element - wartość nowego elementu.
    void addFront(int element);
    /// Dodaje losowy element do tablicy w losowym miejscu.
    void addRandom(int element);
    /// Usuwa element z tablicy w podanym miejscu.
    /// \param index - miejsce, z którego powinien zostać usunięty element.
    void remove(int index);
    /// Usuwa losowy element z tablicy.
    void removeRandom();
    /// Zwraca ilość elementów tablicy.
    /// \return Ilość elementów tablicy.
    int getSize();
};