#pragma once
#include <iostream>
#include <string>
#include "BSTNode.h"

/// Klasa dla drzewa BST.
class BST
{
private:
    /// Sta³a przechowuj¹ca opis wyj¹tku.
    const std::string EXCEPTION_DESC = "Nie znaleziono takiego elementu!";
    /// WskaŸnik na korzeñ drzewa.
    BSTNode * root;
    /// Znajduje wêze³ drzewa dla podanego klucza.
    /// \param data - klucz elementu do wyszukania.
    /// \return WskaŸnik na element z danych kluczem lub nullptr.
    BSTNode * findNode(int data);
    /// Znajduje nastêpnika podanego wêz³a.
    /// \param node - wêze³ dla którego ma zostaæ znaleziony nastêpnik.
    /// \return WskaŸnik na nastêpnika podanego wêz³a.
    BSTNode * findSuccessor(BSTNode * node);
    /// Dealokuje pamiêæ dla ka¿dego elementu drzewa (PostOrder).
    /// \param root - korzeñ drzewa.
    void deletePostOrder(BSTNode * root);
    /// Wypisuje graficzn¹ reprezentacjê drzewa do konsoli.
    /// \param prefix - prefiks danej linii.
    /// \param node - kolejny wêze³ w rekurencji (PreOrder).
    /// \param isLeft - mówi, czy nastêpny wierzcho³ek jest lewym dzieckiem.
    void printTree(std::string prefix, const BSTNode * node, bool isLeft);
public:
    /// Konstruktor klasy drzewa BST.
    BST();
    /// Destruktor klasy drzewa BST.
    ~BST();
    /// Dodaje nowy element do drzewa.
    /// \param element - element do dodania.
    void add(int element);
    /// Usuwa element z drzewa.
    /// \param element - element do usuniêcia.
    void remove(int element);
    /// Wyszukuje element w drzewie.
    /// \param element - element do wyszukania.
    /// \return true - jeœli element zosta³ znaleziony, false - jeœli nie.
    bool find(int element);
    /// Wyœwietla drzewo w konsoli.
    void printTree();
};