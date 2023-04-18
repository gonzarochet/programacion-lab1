#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "pila.h"


int cargaArregloVacio(int array [],int dimension);
int cargaArregloConDatosPrevios(int arreglo[],int validos,int dimension);
void cargaArregloRandomConPuntero(int arreglo[], int * validos, int dim);
void recorrerArregloEnteros(int arreglo[], int validos);
int pasajePilaToArray(Pila * p, int array[], int dim);
int pasajeArregloToPila(int array[],int validos, Pila * p);


int main()
{
    system("color BD");
    Pila pilita;
    inicpila(&pilita);

    int dim = 7;
    int temp[dim];
    int validos = 0;


    temp[0] = 45;
    temp[1] = 27;

    validos = 2;


    cargaArregloRandomConPuntero(temp,&validos,dim);

    printf("\n1. ARRAY CON DATOS CARGADO\n");
    recorrerArregloEnteros(temp,validos);
    system("pause");

    printf("\n2. PASAJE DE ARREGLO A LA PILA\n");
    validos = pasajeArregloToPila(temp,validos,&pilita);

    printf("\n La Pila con los datos del arreglo\n");
    mostrar2(&pilita);

    printf("\n El arreglo vacio \n");
    recorrerArregloEnteros(temp,validos);

    system("pause");

    printf("\n3. PASAJE DE LA PILA AL ARREGLO\n");

    validos = pasajePilaToArray(&pilita,temp,dim);

     printf("\n La Pila vacia \n");
    mostrar2(&pilita);

     printf("\n El arreglo con sus datos originales\n");
    recorrerArregloEnteros(temp,validos);



    return 0;
}
/** \brief Carga Arreglo vacio por usuario
 *
 * \param int array[] - El arreglo a cargar datos.
 * \param int dimension - El total de datos que puede contener ese array.
 * \return int validos - Retorna el valor de validos, es decir, los datos cargados array.
 *
 */
int cargaArregloVacio(int array[],int dimension){

    int validos = 0;
    char option= 's';

    while(option =='s' && validos<dimension)
    {
        printf("Ingrese un valor entero\n");
        scanf("%d",&array[validos]);

        printf("Quiere seguir cargando datos? Ingrese 's' para continuar\n");
        option = getch();
        validos++;

    }
    return validos;


}

/** \brief Carga Elementos en un array de enteros, por usuario, que puede o no tener datos antes.
 *
 * \param int array[] - El arreglo a cargar datos.
 * \param int validos - Los valores cargados previamente. Si el array esta vacio es 0.
 * \param int dimension - El total de datos que puede contener ese array.
 * \return int validos - Retorna el valor de validos, es decir, los datos cargados array.
 *
 */
int cargaArregloConDatosPrevios(int arreglo[],int validos,int dimension)
{

    char option= 's';

    while(option =='s' && validos<dimension)
    {
        printf("Ingrese un valor entero\n");
        scanf("%d",&arreglo[validos]);
        validos++;

        printf("Quiere seguir cargndo datos? Ingrese 's' para continuar\n");
        option = getch();

    }

    return validos;

}

/** \brief Carga Elementos en un array de enteros, de forma arbitraria, que puede o no tener datos antes.
 *
 * \param int array[] - El arreglo a cargar datos.
 * \param int  * validos - Recibe un puntero a un entero, en este caso a la variable que contiene la cantidad de datos cargados en el array.
 * \param int dimension - El total de datos que puede contener ese array.
 * \return void - no retorna validos porque se lo pasamos previamente por referencia
 *
 */
void cargaArregloRandomConPuntero(int arreglo[], int * validos, int dim){

   srand(time(NULL));

   int i; // La declaramos afuera del for para poder asignarsela después a la variable de tipo puntero que contiene los válidos.

   for (i = *validos; i<dim; i++){
        arreglo[i] = rand()%100+1;
   }
   *validos = i;

}

/** \brief Recorre un array de valores enteros
 *
 * \param int array[] - El arreglo a recorrer datos.
 * \param int validos - La cantidad de datos cargados que tiene el arreglo.
 * \return void - funcion de mostrar no retorna
 *
 */
void recorrerArregloEnteros(int arreglo[], int validos){
    printf("[");
    for(int i = 0; i<validos;i++){
        printf(" %d |",arreglo[i]);
    }
}

int pasajePilaToArray(Pila * p, int array[], int dim){

    int validos = 0;

    while(!pilavacia(p) && validos < dim){

        array[validos] = desapilar(p);
        validos++;
    }

    return validos;


}

int pasajeArregloToPila(int array[],int validos, Pila * p){

    int i;
    for(i = validos; i>0;i--){
        apilar(p,array[i-1]);
    }
    validos = i;

    return validos;
}


