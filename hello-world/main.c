#include <stdio.h>
#include <stdlib.h>
#include "pila.h"



int main()
{
    /*
    int num = 0;
    printf("Ingrese un numero: \n");
    scanf("%d", &num);
    printf("El numero ingresado es: %d \n", num);
    */

    Pila pilita;

    inicpila(&pilita);

    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);


    mostrar2(&pilita);
    mostrar(&pilita);



    return 0;
}
