// Practica_2.cpp

#include <iostream> 
#include <vector> 

int main()

{
	//apartado A: Obtener cada byte que forma el entero

	int iEntero = 4;
	unsigned char* cEntero_Char = reinterpret_cast<unsigned char*>(&iEntero);
	for (unsigned int i = 0; i < sizeof(iEntero); i++)
	{
		printf("%02hhx\n", *(cEntero_Char + i));
	}

	//apartado B 
	int tabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };
	const unsigned int iTableSize = sizeof(tabla) / sizeof(int);
	int iMayor = INT_MIN;
	int* pTabla = tabla;
	for (unsigned int i = 0; i < iTableSize; ++i)
	{
		if (iMayor < *(pTabla + i))
		{
			iMayor = *(pTabla + i);
		}
	}

	printf("El mayor es: %d\n", iMayor);

	//apartado C 
	iMayor = INT_MIN;
	pTabla = tabla;
	for (unsigned int i = 0; i < iTableSize; ++i)
	{
		int ix = *(pTabla + i);
		unsigned char* cChar = reinterpret_cast<unsigned char*>(&ix);

		for (unsigned int j = 0; j < sizeof(iEntero); j++)
		{
			printf("%02hhx\n", *(cChar + j));
			if (iMayor < *(cChar + j))
			{
				iMayor = *(cChar + j);
			}
		}
	}

	printf("El byte mayor es: %d\n", iMayor);

	//apartado D 
	char miCadena[] = "Hola"; //darle la vuelta. 
	char* p = miCadena;
	char* p2 = miCadena;
	int longitud = sizeof(miCadena) - 2;

	p2 = (p2 + longitud);

	unsigned int index = 0u;

	while (p < p2)
	{
		char h = *p;
		*p = *p2;
		*p2 = h;
		p = (p + 1);
		p2 = (p2 - 1);
	}

	printf("%s", miCadena);

}

