// Practica5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <fstream>
#include "Practica5_Header.h" 

int main()
{
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];
	std::memset(sBuffer, 0, uBufferSize);

	unsigned int uReadChars = 0;
	unsigned int uWriteChars = 0;
	bool bCloseFile = true;

	std::fstream pFile = OpenFile("Practica5_Texto.txt", std::ios::in);
	bCloseFile = false;

	if (pFile.is_open()) {  // Verificar si el archivo se abrió correctamente

		uReadChars = ReadFile(sBuffer, uBufferSize, pFile);
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

	
	pFile = OpenFile("Practica5_Texto.txt", std::ios::out|std::ios::app);
	bCloseFile = false;

	uWriteChars = WriteFile(sBuffer, uReadChars, pFile);
	bCloseFile = CloseFile(pFile);
}

