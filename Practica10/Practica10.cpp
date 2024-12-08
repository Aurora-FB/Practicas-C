// Practica_10.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <fstream>
#include <iostream>
#include "TList.h"

int main()
{
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uReadChars = 0;
	bool bCloseFile = true;

	std::fstream pFile = Utilities::OpenFile("Practica10_Texto.txt", std::ios::in);
	bCloseFile = false;

	if (pFile.is_open()) {
		uReadChars = Utilities::ReadFile(sBuffer, uBufferSize, pFile);
		bCloseFile = Utilities::CloseFile(pFile);
	}
	else {
		printf("No se pudo abrir el archivo.\n");
	}

	TList newList;

	Utilities::ReturnNumbers(sBuffer, uBufferSize, newList, uReadChars);

	newList.pCurrent = newList.pFirst;
	printf("Primer elemento de la lista: %s\n", newList.First());
	printf("Siguiente elemento de la lista: %s\n", newList.Next());
	printf("Siguiente elemento de la lista: %s\n", newList.Next());
	printf("Siguiente elemento de la lista: %s\n", newList.Next());

	newList.Reset();
}
