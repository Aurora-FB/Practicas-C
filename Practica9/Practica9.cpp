// Practica_9.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "TList.h"

int main()
{
	TList oLista;

	oLista.Push("Primer elemento");
	oLista.Push("Segundo elemento");
	oLista.Push("Tercer elemento");

	printf("Size actual de la lista: %i\n", oLista.Size());

	printf("Primer elemento de la lista: %s\n", oLista.First());

	oLista.pCurrent = oLista.pFirst;

	printf("Siguiente elemento de la lista: %s\n", oLista.Next());
	printf("Siguiente elemento de la lista: %s\n", oLista.Next());

	printf("Eliminar elemento de la lista: %s\n", oLista.Pop());
	printf("Primer elemento de la lista: %s\n", oLista.First());

	oLista.Reset();

	printf("Primer elemento de la lista: %s\n", oLista.First());
	printf("Siguiente elemento de la lista: %s\n", oLista.Next());

}
