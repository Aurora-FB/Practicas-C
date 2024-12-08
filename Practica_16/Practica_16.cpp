// Practica_11.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "TList.h"

int main()
{
    TList oList;

    oList.Push(new SElement("Hello"));
    oList.Push(new IntElement(42));

    oList.pCurrent = oList.pFirst;

    const IElement* firstElement = oList.First();
    firstElement->Print();
    const IElement* nextElement = oList.Next();
    nextElement->Print();
    const IElement* poppedElement = oList.Pop();
    if (poppedElement) {
        poppedElement->Print();
        delete poppedElement;
    }

    oList.Reset();

    firstElement = oList.First();
    if (firstElement) {
        firstElement->Print();
    }
    else {
        printf("Lista Vacia");
    }
}
