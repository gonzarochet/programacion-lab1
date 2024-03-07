#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int main()
{

    srand(time(NULL)); // semilla

    Pila modelo, dada, aux, basura,auxModelo;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);
    inicpila(&auxModelo);

    int numero = 0;

    for(int i = 0; i < 5; i++)
    {
        numero = rand()%10 ;
        apilar(&modelo,numero);
    }


    for(int i = 0; i < 10; i++)
    {
        numero = rand()%10 ;
        apilar(&dada,numero);
    }

    printf("La pila modelo");
    mostrar(&modelo);

    printf("La pila dada antes");
    mostrar(&dada);


    while(!pilavacia(&modelo))
    {

        while(!pilavacia(&dada))
        {

            if(tope(&modelo) == tope(&dada))
            {
                apilar(&basura,desapilar(&dada));
            }
            else
            {
                apilar(&aux,desapilar(&dada));

            }
        }

        while(!pilavacia(&aux))
        {
            apilar(&dada,desapilar(&aux));
        }

        apilar(&auxModelo, desapilar(&modelo));

    }


    while(!pilavacia(&auxModelo)){
        apilar(&modelo,desapilar(&auxModelo));
    }



    printf("La pila dada despues");
    mostrar(&dada);



    return 0;
}
