#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

int insertOrder(char arrayString[][20],int cantElem,char stringToOrder[]);
void showArrayOfStrings(char arrayString[][20],int cantElem);
void insertionoSort(char arrayString[][20],int cantElem);
int findLowerPosition(char arrayString[][20],int cantElem,int posInit);
void selectionSort(char arrayString[][20],int cantElem);
void showArrayInt(int array[], int validos);
void cantBeneficiariosXDni(Pila pila, int arrayBeneficiarios[]);



int main()
{


    Pila pilita;
    inicpila(&pilita);

    apilar(&pilita,43592);
    apilar(&pilita,43593);
    apilar(&pilita,43594);
    apilar(&pilita,43595);
    apilar(&pilita,43596);
    apilar(&pilita,43597);
    apilar(&pilita,43598);
    apilar(&pilita,43599);
    apilar(&pilita,43566);
    apilar(&pilita,43592);
    apilar(&pilita,43593);
    apilar(&pilita,43595);

    int array[10] = {0};

    cantBeneficiariosXDni(pilita,array);
    showArrayInt(array,10);





    char arrayOfStrings [100][20];

    strcpy(arrayOfStrings[0],"Jorge");
    strcpy(arrayOfStrings[1],"Abel");
    strcpy(arrayOfStrings[2],"Rojas");
    strcpy(arrayOfStrings[3],"Pintos");
    strcpy(arrayOfStrings[4],"Sergio");
    strcpy(arrayOfStrings[5],"Gallegillo");
    strcpy(arrayOfStrings[6],"Chaquenio");
    strcpy(arrayOfStrings[7],"Palavecino");


    int values = 3;

//    char array[20];
//    strcpy(array,"Pintos");
//    values = insertOrder(arrayOfStrings,3,array);
    printf("\n Antes de la ordenacion\n");
    showArrayOfStrings(arrayOfStrings,8);
    printf("\nEl array de menor valor esta en la posicion:.... %d",findLowerPosition(arrayOfStrings,8,0));

    printf("\n Despues de la ordenacion\n");
    // insertionSort(arrayOfStrings,8);
    selectionSort(arrayOfStrings,8);
    showArrayOfStrings(arrayOfStrings,8);
    printf("\nEl array de menor valor esta en la posicion:.... %d",findLowerPosition(arrayOfStrings,8,0));







    return 0;
}

void showArrayInt(int array[], int validos)
{
    for(int i = 0; i<validos; i++)
    {
        printf(" %d |",array[i]);
    }


}


void showArrayOfStrings(char arrayString[][20],int cantElem)
{
    for(int i = 0; i<cantElem; i++)
    {
        printf("\n %s",arrayString[i]);

    }
    printf("\n----------------");
}

int insertOrder(char arrayString[][20],int cantElem,char stringToOrder[])
{
    int i = cantElem - 1;
    int flag = 0;
    while(i>=0 && (strcmp(arrayString[i],stringToOrder)>0))
    {
        strcpy(arrayString[i+1],arrayString[i]);
        i--;
    }
    strcpy(arrayString[i+1],stringToOrder);

    return cantElem+1;

}

void insertionSort(char arrayString[][20],int cantElem)
{
    char stringToOrder[20];
    for(int i = 1; i<cantElem; i++)
    {
        strcpy(stringToOrder, arrayString[i]);
        insertOrder(arrayString, i, stringToOrder);
    }
}

int findLowerPosition(char arrayString[][20],int cantElem,int posInit)
{

    int position = posInit;
    char aux[20];

    strcpy(aux,arrayString[position]);

    for(int i = posInit + 1; i <cantElem; i++)
    {
        if(strcmp(arrayString[i],aux)<0)
        {
            strcpy(aux,arrayString[i]);
            position = i;
        }
    }

    return position;

}


void selectionSort(char arrayString[][20],int cantElem)
{
    int i = 0;
    int posLower;
    char aux[20];
    while(i<cantElem-1)
    {
        posLower = findLowerPosition(arrayString,cantElem,i);
        strcpy(aux,arrayString[i]);
        strcpy(arrayString[i],arrayString[posLower]);
        strcpy(arrayString[posLower],aux);
        i++;
    }
}

void cantBeneficiariosXDni(Pila pila, int arrayBeneficiarios[])
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&pila))
    {
        int valor = tope(&pila)%10;
        arrayBeneficiarios[valor]++;
        apilar(&aux,desapilar(&pila));

    }
}






