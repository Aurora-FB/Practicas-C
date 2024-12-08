
#include <iostream> 
#include <fstream>
#include "TList.h"
#include <memory>

TListNode::TListNode(const char* cadena) {
    sCadena = _strdup(cadena);;
    pNext = nullptr;
}

TList::TList() 
{
	pFirst=nullptr;
	pCurrent=nullptr;
	iSize=0;
}
int TList::Size() {
    return iSize;
}

int TList::Push(const char* _sString) {
    TListNode* nuevoNodo = new TListNode(_sString);
    nuevoNodo->pNext = pFirst;
    pFirst = nuevoNodo;
    iSize++;
    return 1;
    //añadir setters
}

const char* TList::First() {
    if (!pFirst) {
        return "Lista Vacia";
    }
    return pFirst->sCadena;
}

const char* TList::Next() {
    if (!pCurrent || !pCurrent->pNext) {
        return nullptr;
    }
    pCurrent = pCurrent->pNext;
    return pCurrent->sCadena;
}

const char* TList::Pop() {
    if (!pFirst) {
        return nullptr;
    }

    TListNode* nodoAEliminar = pFirst;
    pFirst = pFirst->pNext;
    const char* cadena = nodoAEliminar->sCadena;
    delete nodoAEliminar;
    iSize--;
    return cadena;
}

void TList::Reset() {
    while (pFirst) {
        TListNode* nodoAEliminar = pFirst;
        pFirst = pFirst->pNext;
        delete nodoAEliminar;
    }
    iSize = 0;
    pCurrent = nullptr;
}

std::fstream Utilities::OpenFile(const char* _sFileName, std::ios_base::openmode _sMode)
{
	std::fstream pFile;
	pFile.open(_sFileName, _sMode);
	return pFile;
}

bool Utilities::CloseFile(std::fstream& _pFile)
{
	if (_pFile.is_open()) {
		_pFile.close();
		return true;
	}
	return false;
}

unsigned int Utilities::ReadFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile)
{
	unsigned int totalBytesRead = 0;

	while (!_pFile.eof()) {
		_pFile.read(_pBuffer, _uSize);
		unsigned int bytesRead = _pFile.gcount();
		totalBytesRead += bytesRead;

		if (bytesRead < _uSize) {
			break;
		}
	}

	return totalBytesRead;
}

unsigned int Utilities::WriteFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile)
{

	int iWriteCharsCount = 0;
	char str[20] = "Hello World!";

	_pFile.put('\n');
	iWriteCharsCount++;

	for (unsigned int i = 0; i < _uSize && i < strlen(_pBuffer); i++)
	{
		_pFile.put(_pBuffer[i]);
		iWriteCharsCount++;
	}

	for (unsigned int i = 0; i < strlen(str); i++)
	{
		_pFile.put(str[i]);
		iWriteCharsCount++;
	}

	_pFile.put('\n');
	iWriteCharsCount++;

	return iWriteCharsCount;
}

TList Utilities::ReturnNumbers(char* _pBuffer, unsigned int _uSize, TList& tLista, unsigned int uReadChars)
{
	unsigned int iSizeCount = 0;
	char cNumberBuffer[10];
	int iIndex = 0;
	bool inNumber = false;

	while (*_pBuffer != '\0' && iSizeCount < _uSize)
	{
		if (iSizeCount>=uReadChars)
		{
			break;
		}

		iSizeCount++;

		if (std::isdigit(*_pBuffer))
		{
			if (!inNumber) {
				inNumber = true;
			}
			cNumberBuffer[iIndex++] = *_pBuffer;
		}
		else if (*_pBuffer == ',' || *_pBuffer == '\n')
		{
			if (inNumber) {
				cNumberBuffer[iIndex] = '\0';
				tLista.Push(cNumberBuffer);
				inNumber = false;
				iIndex = 0;
			}
		}
		else
		{
			if (inNumber)
			{
				inNumber = false;
				iIndex = 0;
			}
		}
		_pBuffer++;
	}

	if (inNumber) {
		cNumberBuffer[iIndex] = '\0';
		tLista.Push(cNumberBuffer);
	}

	return tLista;
}
