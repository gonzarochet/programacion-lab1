#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void dividers(int number);
void dados(int cantDados);


int main()
{
    //dividers();
    dados(2);
    return 0;
}

/// 2. Divisores: Escriba un programa que muestre todos los
///    divisores del número entero ingresado por el usuario:

void dividers(int number){
    for(int i = 1 ; i<=number;i++){
        if(number%i==0){
            printf("| %d ",i);
        }
    }
}

/// 3. Al tirar un dado tenemos ⅙ de probabilidades de sacar 6.
///    Si tiramos dos dados tenemos 1/36 probabilidades de sacar doble 6.
///    Al aumentar el número de dados la probabilidad de sacar todos 6 es cada vez menor.
///    Escriba un programa que calcule
///    la probabilidad de sacar todos los dados 6 siendo que
///    tiramos N dados (dato leído al usuario). */

void dados(int cantDados){
    float initProbability = 0.1666666;
    float total = 0.0;
    total = pow(initProbability,cantDados);
    printf("La probabilidad de que sacar %d veces el numero 6 es de: %f ", cantDados, total);
}



/// 4.

