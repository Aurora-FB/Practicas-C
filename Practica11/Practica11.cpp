// Practica_11.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "TList.h"

int main()
{
	TList oLista;

	oLista.Push("Primer elemento");
	oLista.Push("Segundo elemento");
	oLista.Push("Tercer elemento");

	oLista.pCurrent = oLista.pFirst;

	printf("Primer elemento de la lista: %s\n", oLista.First());
	printf("Siguiente elemento de la lista: %s\n", oLista.Next());
	printf("Siguiente elemento de la lista: %s\n", oLista.Next());

	TList oListaCopia = oLista;

	oListaCopia.pCurrent = oListaCopia.pFirst;

	printf("Primer elemento de la lista: %s\n", oListaCopia.First());
	printf("Siguiente elemento de la lista: %s\n", oListaCopia.Next());
	printf("Siguiente elemento de la lista: %s\n", oListaCopia.Next());

	TList oReverseList = oLista.GetReverseList();

	oReverseList.pCurrent = oReverseList.pFirst;

	printf("Primer elemento de la lista: %s\n", oReverseList.First());
	printf("Siguiente elemento de la lista: %s\n", oReverseList.Next());
	printf("Siguiente elemento de la lista: %s\n", oReverseList.Next());

	oLista.Reset();
	oListaCopia.Reset();
	oReverseList.Reset();
}
