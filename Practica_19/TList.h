
#include <string>

template <typename T>
class TListNode {
public:
	T pData;
	TListNode* pNext;
	TListNode* pPrev;

	TListNode(T data)
	{
		pData = data;
		pNext = nullptr;
		pPrev = nullptr;
	};
	TListNode(const TListNode& other) 
	{
		pData = other.pData;
		pNext = other.pNext;
		pPrev = other.pPrev;
	};
};

template <typename T>
class TList
{
private:
	TListNode<T>* pFirst;
	TListNode<T>* pLast;
	TListNode<T>* pCurrent;
	int iSize;

public:

	TList()
	{
		pFirst = nullptr;
		pLast = nullptr;;
		pCurrent = nullptr;
		iSize = 0;
	};

	TList(const TList& other)
	{
		pFirst = nullptr;
		pLast = nullptr;
		pCurrent = nullptr;
		iSize = 0;

		TListNode* currentNode = other.pLast;

		while (currentNode) {
			Push(currentNode->pData);
			currentNode = currentNode->pPrev;
		}
	};

	int Size() 
	{
		return iSize;
	};

	void Push(T data)
	{
		TListNode<T>* nuevoNodo = new TListNode<T>(data);
		if (iSize == 0)
		{
			pLast = nuevoNodo;
		}
		else
		{
			pFirst->pPrev = nuevoNodo;
			nuevoNodo->pNext = pFirst;
		}
		pFirst = nuevoNodo;
		iSize++;
	};

	T First()
	{
		if (pFirst)
		{
			return pFirst->pData;
		}
		return T();
	};

	T Last()
	{
		if (pLast)
		{
			return pLast->pData;
		}
		return T();
	};

	T Next()
	{
		if (!pCurrent || !pCurrent->pNext) {
			return T();
		}
		pCurrent = pCurrent->pNext;
		return pCurrent->pData;
	}; 

	T Prev()
	{
		if (!pCurrent || !pCurrent->pPrev) {
			return T();
		}
		pCurrent = pCurrent->pPrev;
		return pCurrent->pData;
	}; 

T Pop()
	{
		if (!pFirst) {
			return T();
		}

		TListNode<T>* nodoAEliminar = pFirst;
		T element = nodoAEliminar->pData;

		if (pFirst == pLast) {
			pFirst = pLast = nullptr;
		}
		else
		{
			pFirst = pFirst->pNext;
			pFirst->pPrev = nullptr;
		}

		delete nodoAEliminar;
		iSize--;

		return element;
	};

	void Reset()
	{

		TListNode<T>* nodoAEliminar = pFirst;

		while (nodoAEliminar != nullptr) {
			TListNode* nodoSiguiente = nodoAEliminar->pNext;
			delete nodoAEliminar;
			nodoAEliminar = nodoSiguiente;
		}
		pFirst = pLast = nullptr;
		pCurrent = nullptr;
		iSize = 0;
	};

	TList GetReverseList()
	{
		TList reverseList;

		pCurrent = pFirst;

		while (pCurrent)
		{
			reverseList.Push(pCurrent->pData);
			pCurrent = pCurrent->pNext;
		}
		return reverseList;
	};

};


