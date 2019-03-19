#include "List.h"

List::List()
{
    //Ustawiamy początkową ilość elementów listy. Wskaźniki na głowę oraz ogon pokazują NULL.
    size = 0;
    head = nullptr;
    tail = nullptr;
}

List::~List()
{
    //Dealokujemy pamięć dla kolejnych elementów listy przechodząc po niej od głowy do ogona.
    listItem * next;
    while (head != nullptr)
    {
        next = head->next;
        delete head;
        head = next;
    }
}

void List::pushFront(int element)
{
    //Ustawiamy dane nowego elementu.
    auto * newItem = new listItem();
    newItem->data = element;

    //Nowy element staje się teraz głową.
    newItem->previous = nullptr;
    newItem->next = head;
    head = newItem;
    //Jeśli w liście znajdował się kolejny element to zmieniamy jego wskaźnik 'previous' na nową głowę.
    if (head->next != nullptr) head->next->previous = newItem;
    //W przeciwnym wypadku ogon również wskazuje na nowy element (jednoelementowa).
    else tail = newItem;
    size++;
}

void List::pushBack(int element)
{
    //Ustawiamy dane nowego elementu.
    auto * newItem = new listItem();
    newItem->data = element;

    //Nowy element staje się teraz ogonem.
    newItem->next = nullptr;
    newItem->previous = tail;
    tail = newItem;
    //Jeśli w liście znajdował się poprzedni element to zmieniamy jego wskaźnik 'next' na nowy ogon.
    if (tail->previous != nullptr) tail->previous->next = newItem;
    //W przeciwnym wypadku głowa również wskazuje na nowy element (jednoelementowa).
    else head = newItem;
    size++;
}

void List::addAfter(int index, int element)
{
    //Sprawdzamy poprawność indexu dla dodawanego elementu i ustawiamy dane nowego elementu.
    checkIndex(index);
    auto * newItem = new listItem();
    newItem->data = element;

    //Znajdujemy element, który będzie poprzedzającym nowego.
    listItem * previousItem = getItem(index);
    listItem * nextItem = nullptr;

    //Jeśli wybrany index jest końcem listy lub lista jest pusta, wrzucamy go na koniec listy.
    if (previousItem == tail || previousItem == nullptr) pushBack(element);
    else
    {
        //Znajdujemy element, który będzie następnikiem nowego.
        nextItem = previousItem->next;
        //Wskaźnik 'next' elementu poprzedzającego ustawiamy na nowy element.
        //Wskaźnik 'previous' elementu następującego ustawiamy na nowy element.
        previousItem->next = newItem;
        nextItem->previous = newItem;

        //Na koniec ustawiamy odpowiednie wskaźniki nowego elementu i zwiększamy rozmiar listy.
        newItem->next = nextItem;
        newItem->previous = previousItem;
        size++;
    }
}

void List::addRandom(int element)
{
    //Dodajemy element w losowym miejscu 'index'.
    int index = rand() % (size + 1);
    if (index == 0) pushFront(element);
    else addAfter(index - 1, element);
}

void List::popFront()
{
    //Usuwamy głowę listy, jeśli lista nie jest pusta.
    if (size != 0) remove(0);
    else throw std::length_error(EXCEPTION_LENGTH_DESC);
}

void List::popBack()
{
    //Usuwamy ogon listy, jeśli lista nie jest pusta.
    if (size != 0) remove(size - 1);
    else throw std::length_error(EXCEPTION_LENGTH_DESC);
}

int List::get(int index)
{
    //Sprawdzamy czy index nie wybiega poza listę i wyszukujemy element w podanym miejscu.
    checkIndex(index);
    listItem * searchItem = getItem(index);
    //Zwracamy dane wybranego elementu.
    return searchItem->data;
}

bool List::find(int element)
{
    //Przechodząc od głowy do ogona szukamy danego elementu. true - jeśli element zostanie znaleziony.
    listItem * finder = head;
    while (finder != nullptr)
    {
        if (finder->data == element) return true;
        finder = finder->next;
    }
    return false;
}

bool List::removeValue(int element)
{
    //Przechodząc od głowy do ogona szukamy indexu danego elementu, a następnie go usuwamy.
    //true - jeśli element został usunięty, false - w przeciwnym wypadku.
    listItem * finder = head;
    int index = 0;
    while (finder != nullptr)
    {
        if (finder->data == element)
        {
            remove(index);
            return true;
        }
        finder = finder->next;
        index++;
    }
    return false;
}


void List::remove(int index)
{
    //Sprawdzamy czy index nie wybiega poza listę i znajdujemy dany element.
    checkIndex(index);
    listItem * removeItem = getItem(index);

    //Jeśli element do usunięcia jest ogonem, ustawiamy ogon na jego poprzednika.
    if (removeItem->next == nullptr) tail = removeItem->previous;
    //W przeciwnym wypadku ustawiamy wskaźnik 'previous' następnika usuwanego elementu na poprzednika usuwanego elementu.
    else removeItem->next->previous = removeItem->previous;
    //Jeśli element do usunięcia jest głową, ustawiamy głowę na jego następnika.
    if (removeItem->previous == nullptr) head = removeItem->next;
    //W przeciwnym wypadku ustawiamy wskaźnik 'next' poprzednika usuwanego elementu na następnika usuwanego elementu.
    else removeItem->previous->next = removeItem->next;
    size--;
    //Dealokujemy pamięć dla usuwanego elementu.
    delete removeItem;
}

void List::removeRandom()
{
    //Usuwamy losowy element tablicy, jeśli nie jest pusta.
    if (size > 0) remove(rand() % size);
}

void List::checkIndex(int index)
{
    //Jeśli podany index jest mniejszy od zera lub większy od wielkości listy, rzucamy wyjątek.
    if (index < 0 || index > (size - 1))
        throw std::out_of_range(EXCEPTION_RANGE_DESC);
}

listItem * List::getItem(int index)
{
    //Wyszukiwane elementu rozpoczynamy od ustalenia czy znajduje się bliżej głowy lub ogona.
    listItem * startItem;
    int currentIndex = 0;
    if ((size - 1) - index >= index)
    {
        //Jeśli element znajduje się bliżej głowy, przechodzimy listę od głowy do podanego indexu.
        startItem = head;
        while (currentIndex != index)
        {
            startItem = startItem->next;
            currentIndex++;
        }
    }
    else
    {
        //Jeśli element znajduje się bliżej ogona, przechodzimy listę od ogona do podanego indexu.
        startItem = tail;
        currentIndex = size - 1;
        while (currentIndex != index)
        {
            startItem = startItem->previous;
            currentIndex--;
        }
    }
    return startItem;
}

int List::getSize()
{
    return size;
}