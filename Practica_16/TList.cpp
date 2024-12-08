
#include "TList.h"
#include <memory>

TListNode::TListNode(IElement* data) {
    pData = data;
    pNext = nullptr;
    pPrev = nullptr;
}

TListNode::TListNode(const TListNode& other) {
    pData = other.pData->Clone();
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
        Push(currentNode->pData);
        currentNode = currentNode->pPrev;
    }
}

int TList::Size() {
    return iSize;
}

int TList::Push(IElement* pData) {
    TListNode* nuevoNodo = new TListNode(pData);
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

const IElement* TList::First(){
    if (pFirst) 
    {
        return pFirst->pData;
    }
    return nullptr;
}

const IElement* TList::Last() {
    if (pLast)
    {
        return pLast->pData;
    }
    return nullptr;
}

const IElement* TList::Next() {
    if (!pCurrent || !pCurrent->pNext) {
        return nullptr;
    }
    pCurrent = pCurrent->pNext;
    return pCurrent->pData;
}

const IElement* TList::Prev() {
    if (!pCurrent || !pCurrent->pPrev) {
        return nullptr;
    }
    pCurrent = pCurrent->pPrev;
    return pCurrent->pData;
}

const IElement* TList::Pop() {
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

    const IElement* element = nodoAEliminar->pData;
    delete nodoAEliminar;
    iSize--;
    return element;
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
        reverseList.Push(pCurrent->pData);
        pCurrent = pCurrent->pNext;
    }
    return reverseList;
}