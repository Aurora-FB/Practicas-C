
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

namespace Utilities
{
	std::fstream OpenFile(const char* _sFileName, std::ios_base::openmode _sMode);
	bool CloseFile(std::fstream& _pFile);
	unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile);
	unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile);
	TList ReturnNumbers(char* _pBuffer, unsigned int _uSize, TList& tLista, unsigned int uReadChars);
}
