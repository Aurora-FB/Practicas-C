// Practica_15.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include "CStream_Header.h" 

int main()
{
    const char* file = "File.txt";
    CFile *oFile = new CFile(file);

    const char* comp = "Comp.txt";
    CComp* oComp = new CComp(comp);

    const char* address = "Adress";
    int port = 1234;
    CTcp* oTcp = new CTcp(address, port);

    oFile->Open_Stream();
    oComp->Open_Stream();
    oTcp->Write_Stream();
}
