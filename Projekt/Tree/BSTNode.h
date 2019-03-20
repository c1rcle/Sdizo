/// Struktura dla w�z�a BST.
struct BSTNode
{
    /// Klucz w�z�a.
    int data;
    /// Wska�nik na ojca w�z�a.
    BSTNode * parent;
    /// Wska�nik na lewe dziecko w�z�a.
    BSTNode * left;
    /// Wska�nik na prawe dziecko w�z�a.
    BSTNode * right;
};