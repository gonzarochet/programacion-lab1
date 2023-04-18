#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int cargaElementosArreglos(int arreglo[],int dimension);
void cargaRandomArregloIntPunteros(int arreglo[], int * validos, int dim);
void recorrerArregloEnteros(int arreglo[], int validos);

int main()
{
    int dim = 7;
    int temp[dim];
    temp[0] = 45;
    temp[1] = 27;
    int validos = 2;

   validos = cargaElementosArreglos(temp,dim);

    //cargaRandomArregloIntPunteros(temp,&validos,dim);
    recorrerArregloEnteros(temp,validos);

    return 0;
}


int cargaElementosArreglos(int arreglo[],int validos,int dimension)
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

void cargaRandomArregloIntPunteros(int arreglo[], int * validos, int dim){

   srand(time(NULL));

   int i = *validos;

   while(i<dim){
        arreglo[i] = rand()%100+1;
        i++;
   }
   *validos = i;





}

void recorrerArregloEnteros(int arreglo[], int validos){
    for(int i = 0; i<validos;i++){
        printf(" %d |",arreglo[i]);
    }
}



