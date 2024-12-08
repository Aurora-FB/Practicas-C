// Practica6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <fstream>
#include "Practica6_Header.h" 

int main()
{
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uReadChars = 0;
	unsigned int uWriteChars = 0;
	unsigned int iSumIntegers = 0;
	unsigned int iSearchString = 0;
	bool bCloseFile = true;

	std::fstream pFile = OpenFile("Practica6_Texto.txt", std::ios::in);
	bCloseFile = false;

	if (pFile.is_open()) {  // Verificar si el archivo se abrió correctamente

		uReadChars = ReadFile(sBuffer, uBufferSize, pFile);
		iSearchString = SearchString(sBuffer, uReadChars, "Hello");
		iSumIntegers = SumIntegers(sBuffer, uReadChars);
		bCloseFile = CloseFile(pFile);
	}
	else {
		printf("No se pudo abrir el archivo.\n");  // Manejo de errores al abrir el archivo
	}

	for (unsigned int uIndex = 0; uIndex < uReadChars; uIndex++)
	{
		printf("%c", sBuffer[uIndex]);
	}
	printf("\n");
	printf("Suma de integers: %i\n", iSumIntegers);
	printf("Numero de veces encontrado 'Hello': %i\n", iSearchString);
}

