#include "BST.h"

BST::BST()
{
    //Ustawiamy korzeń na nullptr.
    root = nullptr;
}

BST::~BST()
{
    //Usuwamy kolejno wszystkie elementy w przejściu PostOrder.
    deletePostOrder(root);
}

void BST::add(int element)
{
    //Tworzymy nowy węzeł i wypełniamy jego pola.
    BSTNode * node = new BSTNode();
    node->data = element;
    node->left = nullptr;
    node->right = nullptr;

    //Jeśli drzewo jest puste to nowy węzeł staje się jego korzeniem.
    if (root == nullptr) root = node;
    else
    {
        //Zgodnie ze strukturą drzewa, idziemy do ostatniego węzła.
        BSTNode * next = root;
        BSTNode * lastNode = nullptr;
        while (next != nullptr)
        {
            lastNode = next;
            if (node->data < next->data) next = next->left;
            else next = next->right;
        }
        //Nowy węzeł, w zależności od wielkości klucza,
        //staje się lewym bądź prawym liściem ostatniego węzła.
        if (node->data < lastNode->data) lastNode->left = node;
        else lastNode->right = node;
        node->parent = lastNode;
    }
}

void BST::remove(int element)
{
    //Znajdujemy wskaźnik na element o poszukiwanym kluczu.
    BSTNode * removeNode = findNode(element);
    //Jeśli element nie został znaleziony, to rzucamy wyjątek.
    if (removeNode == nullptr) throw std::invalid_argument(EXCEPTION_DESC);
    //Pierwszy przypadek - usuwany wierzchołek jest liściem.
    if (removeNode->left == nullptr && removeNode->right == nullptr)
    {
        //W tym przypadku wierzchołek zostaje po prostu usunięty.
        if (removeNode->parent != nullptr)
        {
            BSTNode * parent = removeNode->parent;
            //Ustawiamy wskazanie rodzica na ten wierzchołek na nullptr.
            if (parent->data > removeNode->data) parent->left = nullptr;
            else parent->right = nullptr;
        }
        else root = nullptr;
        delete removeNode;
    }
    //Drugi przypadek - usuwany wierzchołek ma jedno dziecko (lewe).
    else if (removeNode->left != nullptr && removeNode->right == nullptr)
    {
        //Zamiana wierzchołków.
        BSTNode * child = removeNode->left;
        removeNode->data = child->data;
        removeNode->left = child->left;
        removeNode->right = child->right;
        delete child;
    }
    //Trzeci przypadek - usuwany wierzchołek ma jedno dziecko (prawe).
    else if (removeNode->left == nullptr && removeNode->right != nullptr)
    {
        //Zamiana wierzchołków.
        BSTNode * child = removeNode->right;
        removeNode->data = child->data;
        removeNode->left = child->left;
        removeNode->right = child->right;
        delete child;
    }
    //Czwarty przypadek - usuwany wierzchołek ma dwoje dzieci.
    else
    {
        //Znajdujemy następnika danego węzła.
        BSTNode * successor = findSuccessor(removeNode);
        //Zamieniamy dane i przypisujemy prawe poddrzewo następnika jego rodzicowi.
        removeNode->data = successor->data;
        BSTNode * successorRightSubtree = successor->right;
        if (successor->data < successor->parent->data) successor->parent->left = successorRightSubtree;
        else successor->parent->right = successorRightSubtree;
        if (successorRightSubtree != nullptr) successorRightSubtree->parent = successor->parent;
        delete successor;
    }
}

bool BST::find(int element)
{
    //Zgodnie ze strukturą drzewa, idziemy do ostatniego węzła.
    BSTNode * next = root;
    while (next != nullptr)
    {
        //Jeśli element zostanie odnaleziony, kończymy wykonywanie.
        if (element == next->data) return true;
        if (element < next->data) next = next->left;
        else next = next->right;
    }
    return false;
}

void BST::printTree()
{
    //Jeśli drzewo jest puste, wyświetlamy tą informację.
    if (root == nullptr)
    {
        std::cout << "Drzewo jest puste!" << std::endl;
        return;
    }
    printTree("", root, false);
}

BSTNode * BST::findNode(int data)
{
    //Zgodnie ze strukturą drzewa, idziemy do ostatniego węzła.
    BSTNode * next = root;
    while (next != nullptr)
    {
        //Jeśli element zostanie odnaleziony, kończymy wykonywanie.
        if (data == next->data) return next;
        if (data < next->data) next = next->left;
        else next = next->right;
    }
    return next;
}

BSTNode * BST::findSuccessor(BSTNode * node)
{
    //Następnik jest najmniejszym elementem prawego poddrzewa danego węzła.
    node = node->right;
    BSTNode * lastNode = nullptr;
    while (node != nullptr)
    {
        lastNode = node;
        node = node->left;
    }
    return lastNode;
}

void BST::deletePostOrder(BSTNode * root)
{
    //Przejście drzewa PostOrder.
    if (root != nullptr)
    {
        deletePostOrder(root->left);
        deletePostOrder(root->right);
        delete root;
    }
}

void BST::printTree(std::string prefix, const BSTNode * node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->data << std::endl;

        printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}