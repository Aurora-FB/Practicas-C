
class TListNode
{
public:
	const char* sCadena;
	TListNode* pNext;

	TListNode(const char* cadena);
};

class TList
{
public:
	TListNode* pFirst;
	TListNode* pCurrent;
	int iSize;

	TList();
	int Size(); // Retorna el numero de elementos
	int Push(const char* psz); // Añade la cadena a la lista
	const char* First();// Retorna el primer elemento de la lista.
	const char* Next(); // Retorna el siguiente elemento de la lista.
	const char* Pop(); // Elimina y retorna el primer elemento de la lista.
	void Reset(); // Elimina todos los elementos de la lista.

};
