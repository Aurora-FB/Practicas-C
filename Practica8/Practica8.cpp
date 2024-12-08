// Practica8.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <fstream>
#include "Practica8_Header.h" 

int main()
{
	TFile oMiFichero;
	unsigned int const uBufferSize = 128;
	char sBuffer[uBufferSize];
	std::memset(sBuffer, 0, uBufferSize);

	unsigned int uReadChars = 0;
	unsigned int uWriteChars = 0;
	bool bCloseFile = true;

	std::fstream pFile = oMiFichero.OpenFile("Practica8_Texto.txt", std::ios::in);
	bCloseFile = false;

	if (pFile.is_open()) {  // Verificar si el archivo se abrió correctamente

		uReadChars = oMiFichero.ReadFile(sBuffer, uBufferSize, pFile);
		bCloseFile = oMiFichero.CloseFile(pFile);
	}
	else {
		printf("No se pudo abrir el archivo.\n");  // Manejo de errores al abrir el archivo
	}

	for (unsigned int uIndex = 0; uIndex < uReadChars; uIndex++)
	{
		printf("%c", sBuffer[uIndex]);
	}
	printf("\n");


	pFile = oMiFichero.OpenFile("Practica8_Texto.txt", std::ios::out | std::ios::app);
	bCloseFile = false;

	uWriteChars = oMiFichero.WriteFile(sBuffer, uReadChars, pFile);
	bCloseFile = oMiFichero.CloseFile(pFile);
}

