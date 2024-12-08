// Practica_14.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

class CPrueba
{
public:
    CPrueba() {}
    ~CPrueba() {}
    int i = 1;
};

class CPruebaV
{
public:
    CPruebaV() { Hola(); }
    ~CPruebaV() {}
    int i = 0;
    virtual void Hola() { printf("HOLA BASE\n"); }
    void Adios() {}
};

class CPruebaV1 : public CPruebaV
{
public:
    CPruebaV1() {}
    ~CPruebaV1() {}
    int i = 0;
    virtual void Hola() { printf("HOLA DERIVADA\n"); }
};

int main()
{
    CPruebaV* oPruebaV = new CPruebaV();
    CPrueba* oPrueba = new CPrueba();

    unsigned int iCprueba_Size = sizeof(CPrueba);
    unsigned int iCpruebaV_Size = sizeof(CPruebaV);
    /*a. ¿Cuanto espacio ocupa la tabla de funciones virtuales?
            La tabla de funciones virtuales en CPruebaV ocupa 8 y se le añade un padding que ocupa 4 para completarlo por lo que da 16 bytes en total,
            mientras que con CPrueba solo de 4 bytes.*/
    printf("a. \n");
    printf("  %d\n", iCprueba_Size);
    printf("  %d\n", iCpruebaV_Size);

    /*b. ¿Donde está situada la tabla de funcioens virtuales?
            La tabla de funciones virtuales se almacena en un area global,
            en el objeto que tiene esta misma tabla solo se guarda un puntero con su dirección.
            A continuación se puede ver que la vTable, como tal, no esta almacenada en el propio objeto
            pues su dirección no coincide con la de la clase:*/
    printf("b. \n");
    printf("  Direccion de CPruebaV: %p\n", (void*)oPruebaV);
    printf("  Direccion de la vtable de CPruebaV: %p\n", *(void**)oPruebaV);

    /*c. ¿Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?
            El tamaño adicional ocupado por un objeto que tiene funciones virtuales es el tamaño del puntero a la vtable(4 o 8 bytes) más cualquier padding que se requiera.
            En el caso de arriba, el tamaño adicional de CPruebaV respecto a CPrueba es de 12 bytes. 8 por el vptr y 4 el padding.*/

            /*d. ¿Qué pasa si llamo a un método virtual desde el constructor?
                    Durante la ejecución de un constructor, la vtable no está completamente configurada para la clase derivada
                    (si estás en una jerarquía de herencia). En su lugar, las funciones virtuales se resuelven según la clase
                    de la que se está ejecutando el constructor, no según la clase final del objeto.
                    Basicamente, el mayor problemas escon el tema de la herencia, cuando se llama a el constructor de la clase CPruebaV1, estamos llamando al de CPruebaV y se ejecutará su funcion hola con su texto
                    pues no se ha configurado para que sea de otra forma, entonces siempre que se construya CPruebaV1 se llamara a una frase que no es suya.*/
    printf("d. \n");
    CPruebaV1* oPruebaV1 = new CPruebaV1();


    /*e. Comparar la llamada a una función virtual con la llamada a una función no virtual.
        ¿Cuántos pasos adicionales tienen que realizarse para llamar a una función cuando esta es virtual?
            Para el caso de la función virtual se tiene que acceder a la vtable, buscar la funcion deseada y llamarla
            para funciones no virtuales es simplemente buscar la funcion en la memoria y ya.*/
    printf("e. \n");
    oPruebaV1->Hola();
    oPruebaV->Adios();

    delete oPruebaV;
    delete oPruebaV1;
    delete oPrueba;

}
