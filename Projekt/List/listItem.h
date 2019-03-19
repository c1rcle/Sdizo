/// Struktura dla elementu listy.
struct listItem
{
    /// Wartość danego elementu listy.
    int data;
    /// Wskaźnik na następny element listy.
    listItem * next;
    /// Wskaźnik na poprzedni element listy.
    listItem * previous;
};