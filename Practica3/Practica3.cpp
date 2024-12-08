// Practica_3.cpp

#include <iostream> 

const char* sTablaDeCadenas[]
{
	"Uno",
	"dos",
	"tres",
	"cuatro"
};

const char* GetCadena(unsigned int _uIndex)
{
	int sizeOfTabla = sizeof(sTablaDeCadenas) / sizeof(const char*);
	if (_uIndex < sizeOfTabla)
	{
		return sTablaDeCadenas[_uIndex];
	}
	return nullptr;
}

char* GetCadenaInvertida(unsigned int _uIndex)
{
	const char* sCadenaOriginal = GetCadena(_uIndex);
	if (sCadenaOriginal != nullptr)
	{
		unsigned int uSize = strlen(sCadenaOriginal);
		char* sNuevaCadena = new char[uSize + 1];
		sNuevaCadena[uSize] = '\0';
		for (unsigned int i = 0; i < uSize; i++)
		{
			sNuevaCadena[uSize - 1 - i] = sCadenaOriginal[i];
		}
		return sNuevaCadena;
	}
	return nullptr;
}



int main()
{
	printf("%s\n", GetCadena(1));
	char* sCadena = GetCadenaInvertida(1);
	printf("%s\n", sCadena);
	delete sCadena;
}