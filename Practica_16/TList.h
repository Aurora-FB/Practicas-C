
#include <string>

class IElement {
public:
	virtual ~IElement() {}
	virtual void Print() const = 0;  // Método común, cada clase hija lo implementa
	virtual IElement* Clone() const = 0;  // Método para clonar objetos, si lo necesitas
};

class SElement : public IElement {
private:
	const char* value;
public:
	SElement(const char* str) : value(str) {}

	void Print() const override {
		printf("%s", value);
	}

	IElement* Clone() const override {
		return new SElement(value);
	}
};

class IntElement : public IElement {
private:
	int value;
public:
	IntElement(int val) : value(val) {}

	void Print() const override {
		printf("%i", value);
	}

	IElement* Clone() const override {
		return new IntElement(value);
	}
};

class TListNode {
public:
	IElement* pData;
	TListNode* pNext;
	TListNode* pPrev;

	TListNode(IElement* pData);
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
	int Push(IElement* pData); // Añade la cadena a la lista
	const IElement* First();// Retorna el primer elemento de la lista.
	const IElement* Last();// Retorna el ultimo elemento de la lista.
	const IElement* Next(); // Retorna el siguiente elemento de la lista.
	const IElement* Prev(); // Retorna el anterior elemento de la lista.
	const IElement* Pop(); // Elimina y retorna el primer elemento de la lista.
	void Reset(); // Elimina todos los elementos de la lista.
	TList GetReverseList();

};


