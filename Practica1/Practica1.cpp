// Practica_1.cpp

#include <iostream> 

#define MASK_GETBALAS 0xFF; 
#define MASK_ADDBALAS 0xFF0000; 

int GetNumBalas(unsigned int iInfo)
{
    unsigned int iNumBalas = 0;
    iNumBalas = (iInfo >> 16) & MASK_GETBALAS;
    return iNumBalas;

}

unsigned int AddNumBalas(unsigned int iInfo, int numBalas)
{
    unsigned int iNumBalas = 0;
    unsigned int addBalas = 7 + numBalas;

    iNumBalas = iInfo | MASK_ADDBALAS;
    iNumBalas ^= MASK_ADDBALAS;

    iNumBalas |= addBalas << 16;
    iNumBalas = (iNumBalas >> 16) & MASK_GETBALAS;

    return iNumBalas;
}

bool GetBalasInfinitas(unsigned int info)
{
    bool bBalasInfinitas = false;
    bBalasInfinitas = (info >> 1) & 1;
    return bBalasInfinitas;

}

unsigned int SetBalasInfinitas(unsigned int iInfo)
{
    unsigned int newInfo = iInfo ^ 2;
    bool bBalasInfinitas = false;
    bBalasInfinitas = (newInfo >> 1) & 1;
    return bBalasInfinitas;
}

int main()
{
    // VIDA -> 137 -> 89 
    // NUM. bALAS -> 13 -> 0D 
    // NUM COMP -> 7 -> 7 
    // INVULNERABLE ->  
    // BERSERKER -> TRUE 
    // ESCUDO -> TRUE 
    // BALAS INFINITAS -> FALSE 
    // INVULNERABILIDAD -> FALSE 
    // 10001001 00001101 0111 00000000 1 1 0 0 

    unsigned int info = 0x890D700C;
    
    int uNumBalas = GetNumBalas(info);
    unsigned int uNumBalasNuevas = AddNumBalas(info, uNumBalas);
    bool bBalasInfinitas = GetBalasInfinitas(info);
    unsigned int iNewInfo = SetBalasInfinitas(info);

    printf("El numero de balas actual es: %d\n", uNumBalas);
    printf("Agregandole 7 balas mas tendriamos: %u\n", uNumBalasNuevas);
    printf("Balas Infinitas activadas: %d\n", bBalasInfinitas);
    printf("Activar o desactivar balas infinitas deja: %u\n", iNewInfo);
}

