
#include "TList.h"
#include <memory>

TListNode::TListNode(const char* cadena) {
    sCadena = cadena;
    pNext = nullptr;
}

TList::TList()
{
    pFirst = nullptr;
    pCurrent = nullptr;
    iSize = 0;
}

int TList::Size() {
    return iSize;
}

int TList::Push(const char* _sString) {
    TListNode* nuevoNodo = new TListNode(_sString);
    nuevoNodo->pNext = pFirst;
    pFirst = nuevoNodo;
    iSize++;
    return 1;
    //añadir setters
}

const char* TList::First() {
    if (!pFirst) {
        return "Lista Vacia";
    }
    return pFirst->sCadena;
}

const char* TList::Next() {
    if (!pCurrent || !pCurrent->pNext) {
        return nullptr;
    }
    pCurrent = pCurrent->pNext;
    return pCurrent->sCadena;
}

const char* TList::Pop() {
    if (!pFirst) {
        return nullptr;
    }

    TListNode* nodoAEliminar = pFirst;
    pFirst = pFirst->pNext;
    const char* cadena = nodoAEliminar->sCadena;
    delete nodoAEliminar;
    iSize--;
    return cadena;
}

void TList::Reset() {
    while (pFirst) {
        TListNode* nodoAEliminar = pFirst;
        pFirst = pFirst->pNext;
        delete nodoAEliminar;
    }
    iSize = 0;
    pCurrent = nullptr;
}
