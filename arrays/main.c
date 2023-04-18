#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


int cargaArregloVacio(int array [],int dimension);
int cargaArregloConDatosPrevios(int arreglo[],int validos,int dimension);
void cargaArregloRandomConPuntero(int arreglo[], int * validos, int dim);
void recorrerArregloEnteros(int arreglo[], int validos);


int main()
{
    int dim = 7;
    int temp[dim];
    int validos = 0;

    temp[0] = 45;
    temp[1] = 27;

    validos = 2;

    cargaArregloRandomConPuntero(temp,&validos,dim);
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



