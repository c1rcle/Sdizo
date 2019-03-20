#pragma once
#include <iostream>
#include <string>
#include "BSTNode.h"

/// Klasa dla drzewa BST.
class BST
{
private:
    /// Sta�a przechowuj�ca opis wyj�tku.
    const std::string EXCEPTION_DESC = "Nie znaleziono takiego elementu!";
    /// Wska�nik na korze� drzewa.
    BSTNode * root;
    /// Znajduje w�ze� drzewa dla podanego klucza.
    /// \param data - klucz elementu do wyszukania.
    /// \return Wska�nik na element z danych kluczem lub nullptr.
    BSTNode * findNode(int data);
    /// Znajduje nast�pnika podanego w�z�a.
    /// \param node - w�ze� dla kt�rego ma zosta� znaleziony nast�pnik.
    /// \return Wska�nik na nast�pnika podanego w�z�a.
    BSTNode * findSuccessor(BSTNode * node);
    /// Dealokuje pami�� dla ka�dego elementu drzewa (PostOrder).
    /// \param root - korze� drzewa.
    void deletePostOrder(BSTNode * root);
    /// Wypisuje graficzn� reprezentacj� drzewa do konsoli.
    /// \param prefix - prefiks danej linii.
    /// \param node - kolejny w�ze� w rekurencji (PreOrder).
    /// \param isLeft - m�wi, czy nast�pny wierzcho�ek jest lewym dzieckiem.
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
    /// \param element - element do usuni�cia.
    void remove(int element);
    /// Wyszukuje element w drzewie.
    /// \param element - element do wyszukania.
    /// \return true - je�li element zosta� znaleziony, false - je�li nie.
    bool find(int element);
    /// Wy�wietla drzewo w konsoli.
    void printTree();
};