#include <cstring>

//Cambiamos el modelo de la lista a una lista doblemente enlazada para una mejor optimización:
class TListNode
{
public:
	const char* sCadena;
	TListNode* pNext;
	TListNode* pPrev;

	TListNode(const char* cadena);

	TListNode(const TListNode& other);
};

class TList
{
public:
	TListNode* pFirst;
	TListNode* pLast;
	TListNode* pCurrent;
	int iSize;

	TList();

	TList(const TList& other);

	int Size(); // Retorna el numero de elementos
	int Push(const char* psz); // Añade la cadena a la lista
	const char* First();// Retorna el primer elemento de la lista.
	const char* Last();// Retorna el ultimo elemento de la lista.
	const char* Next(); // Retorna el siguiente elemento de la lista.
	const char* Prev(); // Retorna el anterior elemento de la lista.
	const char* Pop(); // Elimina y retorna el primer elemento de la lista.
	void Reset(); // Elimina todos los elementos de la lista.
	TList GetReverseList();

};
