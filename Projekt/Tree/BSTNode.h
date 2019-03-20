/// Struktura dla wêz³a BST.
struct BSTNode
{
    /// Klucz wêz³a.
    int data;
    /// WskaŸnik na ojca wêz³a.
    BSTNode * parent;
    /// WskaŸnik na lewe dziecko wêz³a.
    BSTNode * left;
    /// WskaŸnik na prawe dziecko wêz³a.
    BSTNode * right;
};