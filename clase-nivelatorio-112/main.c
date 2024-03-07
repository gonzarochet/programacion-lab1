#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

/**
* 14.- Determinar si la cantidad de elementos
    de la pila DADA es par.
    Si es par, pasar el elemento del tope de la
    pila DADA a la pila PAR y si es impar pasar
    el tope a la pila IMPAR (el ejercicio debe
    ser realizadoSIN contar los elementos)
**/

int main()
{

    srand(time(NULL));
    Pila dada, aux, aux1, par, impar;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux1);
    inicpila(&par);
    inicpila(&impar);

    int numero = 0;


    for(int i = 0; i < 8; i++)
    {
        numero = rand()%10+1;
        apilar(&dada,numero);
    }

    int topeDada = tope(&dada);

    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&impar,desapilar(&dada));

        if(!pilavacia(&dada))
        {
            apilar(&par,desapilar(&dada));
        }
    }


    while(!pilavacia(&par) && !pilavacia(&impar))
    {

        apilar(&aux,desapilar(&par));

        apilar(&aux,desapilar(&impar));
    }



    if(pilavacia(&par) && pilavacia(&impar))
    {
        printf("La cantidad de elementos en par");
        apilar(&par,topeDada);
        mostrar2(&par);
    }
    else
    {
        printf("La cantidad de elementos es impar");
        apilar(&impar,topeDada);
        mostrar2(&impar);

    }



    return 0;
}
