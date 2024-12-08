#include <iostream> 
#include "Image_Header.h" 

//main 
int main()
{

	//Practica 13 Part 2: 
	CImage* pTImages[5];
	pTImages[0] = new CJpg();
	pTImages[1] = new CPng();
	pTImages[2] = new CImage();
	pTImages[3] = new CPng();
	pTImages[4] = new CJpg();

	int pTImages_Lenght = sizeof(pTImages) / sizeof(pTImages[0]);

	for (int index = 0; index < pTImages_Lenght; index++ )
	{

		if (pTImages[index]->m_eType == CImage::EType::PNG)
		{
			CPng* pPng = static_cast<CPng*>(pTImages[index]);
			pPng->DeleteAlphaChanel();
		}

		delete pTImages[index];
		pTImages[index] = nullptr;
	}
	return 0;
}