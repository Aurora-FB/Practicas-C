
struct TFile
{
	std::fstream OpenFile(const char* _sFileName, std::ios_base::openmode _sMode);
	bool CloseFile(std::fstream& _pFile);
	unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile);
	unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, std::fstream& _pFile);
};
