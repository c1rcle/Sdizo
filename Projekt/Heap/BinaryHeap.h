#pragma once
#include <iostream>
#include <cmath>
#include <string>

/// Klasa dla kopca binarnego.
class BinaryHeap
{
private:
    /// Stała przechowująca ilość miejsc drzewa przy utworzeniu nowego obiektu.
    unsigned const int START_SPACE = 10;
    /// Stała przechowująca minimalną ilość wolnego miejsca w kopcu.
    unsigned const int MIN_FREE_SPACE = 5;
    /// Stała przechowująca maksymalną ilość wolnego miejsca w kopcu.
    unsigned const int MAX_FREE_SPACE = 15;
    /// Stała przechowująca opis wyjątku.
    const std::string EXCEPTION_DESC = "Nieprawidlowy index!";
    /// Stała przechowująca opis wyjątku.
    const std::string EXCEPTION_LENGTH_DESC = "Kopiec jest pusty!";
    /// Wskaźnik na pierwszy element tablicy, w której znajduje się struktura kopca.
    int * base;
    /// Zmienna przechowująca ilość wierzchołków kopca.
    unsigned int vertices;
    /// Zmienna przechowująca ilość miejsc w tablicy.
    unsigned int size;
    /// Naprawia strukturę kopca w górę.
    /// \param index - indeks elementu od którego zaczynamy naprawę.
    /// \param lastVertex - wartość ostatniego elementu kopca.
    void fixHeapUp(int index, int lastVertex);
    /// Naprawia strukturę kopca w dół.
    /// \param index - indeks elementu od którego zaczynamy naprawę.
    /// \param lastVertex - wartość ostatniego elementu kopca.
    void fixHeapDown(int index, int lastVertex);
    /// Znajduje indeks podanego elementu.
    /// \param element - element do wyszukania.
    /// \return Indeks elementu lub -1 jeśli nie zostanie odnaleziony.
    int findElementIndex(int element);
    /// Kopiuje daną ilość elementów z tablicy źródłowej do docelowej.
    /// \param source - wskaźnik na pierwszy element tablicy źródłowej.
    /// \param destination - wskaźnik na pierwszy element tablicy docelowej.
    /// \param size - ilość elementów do przekopiowania.
    void copyArray(int * source, int * destination, int size);
public:
    /// Konstruktor klasy kopca binarnego
    BinaryHeap();
    /// Destruktor klasy kopca binarnego
    ~BinaryHeap();
    /// Dodaje nowy element do kopca.
    /// \param element - wartość dodawanego elementu.
    void push(int element);
    /// Usuwa korzeń kopca i naprawia go.
    /// \return Wartość korzenia.
    int pop();
    /// Usuwa pierwsze wystąpienie elementu w kopcu i naprawia go.
    /// \param element - wartość elementu do wyszukania.
    /// \return true - jeśli element został usunięty, false - jeśli nie.
    bool remove(int element);
    /// Sprawdza czy element o podanej wartości występuje w kopcu.
    /// \param element - wartość elementu do wyszukania.
    /// \return true - jeśli element został znaleziony, false - jeśli nie.
    bool find(int element);
    /// Zwraca element dla podanego miejsca w tablicy, zawierającej informację o drzewie.
    /// \param index - miejsce w tablicy, dla którego zwracamy element.
    /// \return Element dla podanego miejsca w tablicy.
    int getElement(int index);
    /// Wypisuje graficzną reprezentację drzewa do konsoli.
    /// \param prefix - (opcjonalny) prefiks danej linii.
    /// \param index - (opcjonalny) miejsce rozpoczęcia rysowania.
    /// \param isLeft - (opcjonalny) mówi, czy następny wierzchołek jest lewym dzieckiem.
    void printTree(std::string prefix = "", unsigned int index = 0, bool isLeft = false);
    /// Zwraca ilość wierzchołków kopca.
    int getCount();
};