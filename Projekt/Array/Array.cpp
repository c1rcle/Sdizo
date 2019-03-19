#include "Array.h"

Array::Array()
{
    //Ustawiamy wielkość tablicy równą 0.
    this->size = 0;
}

Array::~Array()
{
    //Jeśli tablica ma zalokowaną pamięć, usuwamy ją.
    if (size > 0) delete[] base;
}

void Array::add(int element)
{
    //Osobno obsługujemy dodanie pierwszego elementu (ponieważ nie wymaga kopiowania).
    if (size > 0)
    {
        //Kopiujemy zawartość tablicy do tymczasowej tablicy.
        int * tempArray = new int[size];
        copyArray(base, tempArray, size);
        delete[] base;
        size++;

        //Rozszerzamy rozmiar tablicy o jeden i przywracamy kopię elementów.
        base = new int[size];
        copyArray(tempArray, base, size - 1);
        //Na koniec tablicy wrzucamy nowy element.
        base[size - 1] = element;
        delete[] tempArray;
    }
    else
    {
        size++;
        base = new int[size];
        base[size - 1] = element;
    }
}

void Array::add(int index, int element)
{
    //Obsługa dodania elementów dla warunków brzegowych (w celu ułatwienia implementacji menu).
    if (size == 0 && index == 0)
    {
        add(element);
        return;
    }
    else if (index == size && index > 0)
    {
        add(element);
        return;
    }

    //Sprawdzamy czy index nowego elementu nie wybiega poza tablicę.
    //Jeśli nie to kopiujemy jej zawartość do tymczasowej tablicy.
    checkIndex(index);
    int * tempArray = new int[size];
    copyArray(base, tempArray, size);
    delete[] base;
    size++;

    //Rozszerzamy tablicę i dodajemy element rozsuwając ją.
    base = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i < index) base[i] = tempArray[i];
        else if (i == index) base[i] = element;
        else base[i] = tempArray[i - 1];
    }
    delete[] tempArray;
}

void Array::addFront(int element)
{
    //Dodajemy nowy element na początku tablicy.
    add(0, element);
}

void Array::addRandom(int element)
{
    //Dodajemy nowy element w losowym dostępnym miejscu tablicy.
    add(rand() % (size + 1), element);
}

int Array::get(int index)
{
    //Sprawdzamy czy index nie wybiega poza tablicę i zwracamy wartość wybranego elementu.
    checkIndex(index);
    return base[index];
}

bool Array::find(int element)
{
    //Iterujemy przez całą tablicę w poszukiwaniu danego elementu. true - jeśli został znaleziony.
    for (int i = 0; i < size; i++)
    {
        if (base[i] == element) return true;
    }
    return false;
}

void Array::remove(int index)
{
    //Sprawdzamy czy index elementu do usunięcia nie wybiega poza tablicę.
    checkIndex(index);
    //Jeśli rozmiar tablicy wynosi 1, zwalniamy miejsce.
    if (size == 1)
    {
        delete[] base;
        size--;
    }
    else
    {
        //Kopiujemy zawartość tablicy do tymczasowego bufora.
        int * tempArray = new int[size];
        copyArray(base, tempArray, size);
        delete[] base;
        size--;
        //Zmniejszamy tablicę i zsuwamy elementy.
        base = new int[size];
        for (int i = 0; i < size + 1; i++)
        {
            if (i < index) base[i] = tempArray[i];
            else if (i > index) base[i - 1] = tempArray[i];
        }
        delete[] tempArray;
    }
}

void Array::removeRandom()
{
    //Jeśli rozmiar tablicy jest większy od zera, usuwamy losowy element.
    if (size > 0) remove(rand() % size);
}

int Array::getSize()
{
    return size;
}

void Array::checkIndex(int index)
{
    //Jeśli podany index jest mniejszy od zera lub większy od wielkości tablicy, rzucamy wyjątek.
    if (index < 0 || index > (size - 1))
        throw std::out_of_range(EXCEPTION_DESC);
}

void Array::copyArray(int * source, int * destination, int size)
{
    //Kopiujemy 'size' elementów z tablicy do tablicy.
    for (int i = 0; i < size; i++) destination[i] = source[i];
}