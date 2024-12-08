
#include "TList.h"
#include <memory>

TListNode::TListNode(const char* cadena) {
    sCadena = cadena;
    pNext = nullptr;
    pPrev = nullptr;
}

TListNode::TListNode(const TListNode& other) {
    sCadena = new char[strlen(other.sCadena) + 1];
    strcpy_s(const_cast<char*>(sCadena), strlen(other.sCadena) + 1, other.sCadena);
    pNext = other.pNext;
    pPrev = other.pPrev;
}

TList::TList()
{
    pFirst = nullptr;
    pLast = nullptr;;
    pCurrent = nullptr;
    iSize = 0;
}

TList::TList(const TList& other)
{
    pFirst = nullptr;
    pLast = nullptr;
    pCurrent = nullptr;
    iSize = 0;

    TListNode* currentNode = other.pLast;

    while (currentNode) {
        Push(currentNode->sCadena);
        currentNode = currentNode->pPrev;
    }
}

int TList::Size() {
    return iSize;
}

int TList::Push(const char* _sString) {
    TListNode* nuevoNodo = new TListNode(_sString);
    if (iSize == 0)
    {
        pLast = nuevoNodo;
    } 
    else
    {
        pFirst->pPrev = nuevoNodo;
    }
    nuevoNodo->pNext = pFirst;
    pFirst = nuevoNodo;
    iSize++;
    return 1;
}

const char* TList::First() {
    if (!pFirst) {
        return "Lista Vacia";
    }
    return pFirst->sCadena;
}

const char* TList::Last() {
    if (!pLast) {
        return "Lista Vacia";
    }
    return pLast->sCadena;
}

const char* TList::Next() {
    if (!pCurrent || !pCurrent->pNext) {
        return nullptr;
    }
    pCurrent = pCurrent->pNext;
    return pCurrent->sCadena;
}

const char* TList::Prev() {
    if (!pCurrent || !pCurrent->pPrev) {
        return nullptr;
    }
    pCurrent = pCurrent->pPrev;
    return pCurrent->sCadena;
}

const char* TList::Pop() {
    if (!pFirst) {
        return nullptr;
    }

    TListNode* nodoAEliminar = pFirst;
    
    if (pFirst == pLast) {
        pFirst = pLast = nullptr;
    }
    else
    {
        pFirst = pFirst->pNext;
        pFirst->pPrev = nullptr;
    }

    const char* cadena = nodoAEliminar->sCadena;
    delete nodoAEliminar;
    iSize--;
    return cadena;
}

void TList::Reset() {

    TListNode* nodoAEliminar = pFirst;

    while (nodoAEliminar != nullptr) {
        TListNode* nodoSiguiente = nodoAEliminar->pNext;
        delete nodoAEliminar; 
        nodoAEliminar = nodoSiguiente;
    }
    pFirst = pLast = nullptr;
    pCurrent = nullptr;
    iSize = 0;
}

TList TList::GetReverseList()
{
    TList reverseList;

    pCurrent = pFirst;

    while (pCurrent)
    {
        reverseList.Push(pCurrent->sCadena);
        pCurrent = pCurrent->pNext;
    }
    return reverseList;
}