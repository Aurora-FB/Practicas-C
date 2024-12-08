// Practica_4.cpp

#include <stdio.h> 
#include "consola.h" 

struct TEntity;
typedef void (*funcEntity)(TEntity*);

// *************************************************************************************** 
// ENTIDAD 
// *************************************************************************************** 
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = new funcEntity[2];
		m_funcs[0] = funcs[0];
		m_funcs[1] = funcs[1];
	}
};

// *************************************************************************************** 
// PINTADO
// *************************************************************************************** 
void DrawA(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("A");
}

void DrawB(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("B");
}

void DrawC(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("C");
}

void DrawD(TEntity* _pEntity)
{
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("D");
}


// *************************************************************************************** 
// POSICIÓN
// *************************************************************************************** 
void MoveRight(TEntity* _pEntity)
{
	if (_pEntity->m_ix == 20)
	{
		_pEntity->m_ix = 0;
	}
	else
	{
		_pEntity->m_ix += 1;
	}
}

void MoveLeft(TEntity* _pEntity)
{
	if (_pEntity->m_ix == 0)
	{
		_pEntity->m_ix = 20;
	}
	else
	{
		_pEntity->m_ix -= 1;
	}
}

void MoveUp(TEntity* _pEntity)
{
	if (_pEntity->m_iy == 10)
	{
		_pEntity->m_iy = 0;
	}
	else
	{
		_pEntity->m_iy += 1;
	}
}

void MoveDown(TEntity* _pEntity)
{
	if (_pEntity->m_iy == 0)
	{
		_pEntity->m_iy = 10;
	}
	else
	{
		_pEntity->m_iy -= 1;
	}
}

// *************************************************************************************** 
// MAIN 
// *************************************************************************************** 
unsigned int uKey;
int main(int argc, char* argv[])
{
	TEntity* aMisEntidades[4];
	funcEntity tMisFunciones[2];

	//Entidad 1: A
	tMisFunciones[0] = &DrawA;
	tMisFunciones[1] = &MoveRight;
	aMisEntidades[0] = new TEntity(tMisFunciones, 1, 4);

	//Entidad 2: B
	tMisFunciones[0] = &DrawB;
	tMisFunciones[1] = &MoveLeft;
	aMisEntidades[1] = new TEntity(tMisFunciones, 5, 6);

	//Entidad 2: C
	tMisFunciones[0] = &DrawC;
	tMisFunciones[1] = &MoveUp;
	aMisEntidades[2] = new TEntity(tMisFunciones, 16, 2);

	//Entidad 2: D
	tMisFunciones[0] = &DrawD;
	tMisFunciones[1] = &MoveDown;
	aMisEntidades[3] = new TEntity(tMisFunciones, 9, 1);

	while (true)
	{
		clear();
		(*aMisEntidades[0]->m_funcs[0])(aMisEntidades[0]);
		(*aMisEntidades[0]->m_funcs[1])(aMisEntidades[0]);

		(*aMisEntidades[1]->m_funcs[0])(aMisEntidades[1]);
		(*aMisEntidades[1]->m_funcs[1])(aMisEntidades[1]);

		(*aMisEntidades[2]->m_funcs[0])(aMisEntidades[2]);
		(*aMisEntidades[2]->m_funcs[1])(aMisEntidades[2]);

		(*aMisEntidades[3]->m_funcs[0])(aMisEntidades[3]);
		(*aMisEntidades[3]->m_funcs[1])(aMisEntidades[3]);
		hidecursor();
		Sleep(50);
	}

}
