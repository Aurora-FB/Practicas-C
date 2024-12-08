// Practica_17.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#define COLOR_ENUM(_CALL)\
	_CALL(Azul) \
	_CALL(Morado) \
	_CALL(Naranja)

#define DECLARE_ENUM_VALUE(_ENUM) _ENUM,

#define DECLARE_AS_STRING(_PARAM) \
		case _PARAM: \
			return #_PARAM; 

#define DECLARE_AS_ENUM(_PARAM) \
		if(strcmp(_sEnum, #_PARAM) == 0) \
		{ \
			return _PARAM; \
		}

class CEnum
{
public:

	enum Enum
	{
		COLOR_ENUM(DECLARE_ENUM_VALUE)
	};

	static const char *AsStr(Enum _eEnum){
			
		switch (_eEnum)
		{
		COLOR_ENUM(DECLARE_AS_STRING)
		default:
			break;
		}
	}

	static Enum AsEnum(const char* _sEnum){
		COLOR_ENUM(DECLARE_AS_ENUM)
	}
};

int main()
{
	CEnum::Enum eColor = CEnum::AsEnum("Morado");

	printf("%s\n", CEnum::AsStr(eColor));
	printf("%s\n", CEnum::AsStr(CEnum::Naranja));
}

