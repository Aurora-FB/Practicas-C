//Operaciones de la Practica 7.
//


#include <iostream> 
#include <fstream>
#include "Practica7_Header.h" 

std::fstream Basic_File::OpenFile(const char* _sFileName, std::ios_base::openmode _sMode)
{
	std::fstream pFile;
	pFile.open(_sFileName, _sMode);
	return pFile;
}

bool Basic_File::CloseFile(std::fstream& _pFile)
{
	if (_pFile.is_open()) {
		_pFile.close();
		return true;
	}
	return false;
}

unsigned int Basic_File::ReadFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile)
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

unsigned int Basic_File::WriteFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile)
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

unsigned int File_Operations::SearchString(char* _pBuffer, unsigned int _uSize, const char* _sString)
{
	unsigned int iCount = 0;
	unsigned int iLettersFound = 0;
	unsigned int iSearchStringLength = std::strlen(_sString);

	while (*_pBuffer != '\0')
	{
		if (*_pBuffer == *_sString)
		{
			iLettersFound++;

			char* tempBuffer = _pBuffer + 1; // Guardar la posici�n inicial en _pBuffer
			const char* tempString = _sString + 1;

			while (*tempString != '\0')
			{
				if (*tempBuffer == *tempString)
				{
					iLettersFound++;
					tempBuffer++;
				}
				else {
					iLettersFound = 0;
					break;
				}
				tempString++;
			}

			if (iLettersFound == iSearchStringLength)
			{
				iCount++;
				iLettersFound = 0;
			}
		}
		_pBuffer++;
	}

	return iCount;
}

unsigned int File_Operations::SumIntegers(char* _pBuffer, unsigned int _uSize)
{
	unsigned int iSum = 0;
	unsigned int iSizeCount = 0;
	char cNumberBuffer[10];
	int iIndex = 0;
	bool inNumber = false;

	while (*_pBuffer != '\0' && iSizeCount < _uSize)
	{

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
				iSum += std::atoi(cNumberBuffer);
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
		iSum += std::atoi(cNumberBuffer);
	}

	return iSum;
}