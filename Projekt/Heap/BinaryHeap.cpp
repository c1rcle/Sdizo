#include "BinaryHeap.h"

BinaryHeap::BinaryHeap()
{
    //Ustawiamy rozmiar tablicy na rozmiar początkowy.
    size = START_SPACE;
    vertices = 0;
    base = new int[START_SPACE];
}

BinaryHeap::~BinaryHeap()
{
    //Dealokujemy tablicę.
    delete[] base;
}

void BinaryHeap::push(int element)
{
    //Zapamiętujemy index dla następnego pustego miejsca w tablicy.
    int index = vertices;
    vertices++;
    //Jeśli rozmiar tablicy przekracza minimalny, rozszerzamy ją.
    if (size - vertices < MIN_FREE_SPACE)
    {
        //Kopiujemy zawartość tablicy do bufora, alokujemy nowy rozmiar i przywracamy elementy.
        int * tempArray = new int[vertices];
        copyArray(base, tempArray, vertices - 1);
        delete[] base;
        size += MIN_FREE_SPACE;
        base = new int[size];
        copyArray(tempArray, base, vertices - 1);
        delete[] tempArray;
    }

    //Obliczamy wartość indexu rodzica dla nowego liścia.
    int parentIndex = (index - 1) / 2;
    //Dopóki nie będzie spełniony warunek kopca zamieniamy potomka z jego rodzicem.
    while (index > 0 && base[parentIndex] < element)
    {
        base[index] = base[parentIndex];
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
    base[index] = element;
}

int BinaryHeap::pop()
{
    //Jeśli kopiec jest pusty rzucamy wyjątek.
    if (vertices == 0) throw std::length_error(EXCEPTION_LENGTH_DESC);
    vertices--;
    //Jeśli rozmiar tablicy jest większy niż maksymalny, zmniejszamy ją.
    if (size - vertices > MAX_FREE_SPACE)
    {
        //Kopiujemy zawartość tablicy do bufora, alokujemy nowy rozmiar i przywracamy elementy.
        int * tempArray = new int[vertices];
        copyArray(base, tempArray, vertices);
        delete[] base;
        size -= MIN_FREE_SPACE;
        base = new int[size];
        copyArray(tempArray, base, vertices);
        delete[] tempArray;
    }

    //Zapamiętujemy index ostatniego wierzchołka oraz wartość korzenia.
    int lastVertex = base[vertices];
    int rootValue = base[0];
    //Zmienna index przechowuje index rodzica dla algorytmu naprawy drzewa od góry.
    //Zmienna greaterChildren wskazuje na większego potomka.
    unsigned int index = 0;
    unsigned int greaterChildren = 1;
    //Dopóki nie osiągniemy końca kopca, znajdujemy większego potomka.
    //Jeśli potomkowie są mniejsi od rodzica, to kończymy wykonywanie pętli, ponieważ spełniony jest warunek kopca.
    //W przeciwnym wypadku zamieniamy wierzchołek rodzica z potomkiem i powtarzamy proces.
    while (greaterChildren < vertices)
    {
        if (greaterChildren + 1 < vertices && base[greaterChildren] < base[greaterChildren + 1]) greaterChildren++;
        if (lastVertex >= base[greaterChildren]) break;
        base[index] = base[greaterChildren];
        index = greaterChildren;
        greaterChildren = 2 * greaterChildren + 1;
    }
    //Ustawiamy wartość wyliczonego wierzchołka na ostatni wierzchołek kopca przed usunięciem korzenia.
    base[index] = lastVertex;
    return rootValue;
}

bool BinaryHeap::find(int element)
{
    //Iterujemy przez całą tablicę. true - jeśli element zostanie znaleziony.
    for (int i = 0; i < vertices; i++)
    {
        if (base[i] == element) return true;
    }
    return false;
}

int BinaryHeap::getElement(int index)
{
    if (index < 0 || index > vertices - 1) throw std::out_of_range(EXCEPTION_DESC);
    return base[index];
}

void BinaryHeap::copyArray(int * source, int * destination, int size)
{
    //Kopiujemy 'size' elementów z tablicy do tablicy.
    for (int i = 0; i < size; i++) destination[i] = source[i];
}

void BinaryHeap::printTree(std::string prefix, unsigned int index, bool isLeft)
{
    if (vertices == 0)
    {
        std::cout << "Kopiec jest pusty!" << std::endl;
        return;
    }
    std::cout << prefix;
    std::cout << "└──";
    std::cout << base[index] << std::endl;

    index = 2 * index + 1;
    if (index < vertices)
    {
        printTree(prefix + (isLeft ? "|   " : "    "), index, true);
    }
    if (++index < vertices)
    {
        printTree(prefix + (isLeft ? "|   " : "    "), index, false);
    }
}

int BinaryHeap::getCount()
{
    return vertices;
}
