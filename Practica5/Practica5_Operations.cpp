//Operaciones de la Practica 5.
//


#include <iostream> 
#include <fstream>

std::fstream OpenFile(const char* _sFileName, std::ios_base::openmode _sMode)
{
	std::fstream pFile;
	pFile.open(_sFileName, _sMode);
	return pFile;
}

bool CloseFile(std::fstream& _pFile)
{
	if (_pFile.is_open()) {
		_pFile.close();
		return true;
	}
	return false;
}

unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile)
{
	unsigned int totalBytesRead = 0;

	while (!_pFile.eof()) {
		unsigned int bytesRead = 0;

		std::memset(_pBuffer, 0, _uSize);

		for (unsigned int i = 0; i < _uSize-1 && !_pFile.eof(); ++i) {
			char c;
			_pFile.get(c);
			if (_pFile.eof()) {
				break;
			}
			_pBuffer[i] = c;
			bytesRead++;
		}

		totalBytesRead += bytesRead;

		if (bytesRead < _uSize) {
			break;
		}
	}

	return totalBytesRead;
}

unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile)
{

	int iWriteCharsCount = 0;
	char str[13] = "Hello World!";

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