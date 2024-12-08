// Practica_20.cpp

#include <stdio.h> 
#include "consola.h" 
#include <list>

struct TEntity;
typedef void (*funcEntity)(TEntity*);

// *************************************************************************************** 
// ENTIDAD 
// *************************************************************************************** 
struct TEntity
{
	int m_life;
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y)
	{
		m_life = std::rand() % 10 + 1;
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

void EntityCollide(TEntity* _pEntity, std::list<TEntity*> _lEntity)
{
	for (TEntity* entity : _lEntity) {
		if (entity->m_ix == _pEntity->m_ix && entity->m_iy == _pEntity->m_iy && entity != _pEntity)
		{
			entity->m_life -= 1;
			_pEntity->m_life -= 1;
		}
	}
}

// *************************************************************************************** 
// MAIN 
// *************************************************************************************** 
unsigned int uKey;
int main(int argc, char* argv[])
{
	std::list<TEntity*> lMyEntities;

	funcEntity tDrawFuncs[4] = { &DrawA, &DrawB, &DrawC, &DrawD };
	funcEntity tMoveFuncs[4] = { &MoveRight, &MoveLeft, &MoveUp, &MoveDown };

	funcEntity tMisFunciones[2];

	while (true)
	{
		clear();
		std::list<TEntity*> lMyEntitiesForDelete;

		if (lMyEntities.size() < 5)
		{
			tMisFunciones[0] = tDrawFuncs[std::rand() % 4];
			tMisFunciones[1] = tMoveFuncs[std::rand() % 4];
			lMyEntities.push_front(new TEntity(tMisFunciones, std::rand() % 21, std::rand() % 11));
		}

		for (TEntity* entity : lMyEntities) {
			(*entity->m_funcs[0])(entity);
			(*entity->m_funcs[1])(entity);
			EntityCollide(entity, lMyEntities);
		}

		for (TEntity* entity : lMyEntities) {
			if (entity->m_life <= 0) {
				lMyEntitiesForDelete.push_front(entity);
			}
		}

		for (TEntity* entity : lMyEntitiesForDelete) {
			lMyEntities.remove(entity);
			delete entity;
		}

		lMyEntitiesForDelete.clear();

		hidecursor();
		Sleep(50);
	}

}
