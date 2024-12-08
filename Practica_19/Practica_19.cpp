// Practica_11.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstring>
#include <string>
#include "TList.h"

int main()
{
    TList<int> intList;
    intList.Push(10);
    intList.Push(20);
    intList.Push(30);


    std::cout << "First: " << intList.First() << "\n";
    std::cout << "Last: " << intList.Last() << "\n"; 

    while (intList.Size() > 0) {
        std::cout << "Popped: " << intList.Pop() << "\n"; 
    }

    std::cout << "First: " << intList.First() << "\n";

    TList<std::string> stringList;
    stringList.Push("Hello");
    stringList.Push("World");

    std::cout << "Popped: " << stringList.Pop() << "\n";
    std::cout << "Popped: " << stringList.Pop() << "\n"; 
    std::cout << "First: " << stringList.First() << "\n";
}
