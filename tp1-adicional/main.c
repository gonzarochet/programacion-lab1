#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void dividers(int number);
void dados(int cantDados);
void amountValues();
void range();


int main()
{
    //dividers(200);
    //dados(2);
    //amountValues();
   // range();
    random();

    return 0;
}

/// 2. Divisores: Escriba un programa que muestre todos los
///    divisores del número entero ingresado por el usuario:

void dividers(int number)
{
    for(int i = 1 ; i<=number; i++)
    {
        if(number%i==0)
        {
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

void dados(int cantDados)
{
    float initProbability = 0.1666666;
    float total = 0.0;
    total = pow(initProbability,cantDados);
    printf("La probabilidad de que sacar %d veces el numero 6 es de: %f ", cantDados, total);
}


/// 4. Cantidad de elementos
/// Leer valores del usuario hasta que introduzca un 0.
/// Contar la cantidad de valores introducidos y al finalizar informarlo por pantalla:

void amountValues()
{

    int value = 0;
    int quantity = 0;
    do
    {
        printf("Ingrese un valor. Si no desea continuar ingrese 0 \n");
        scanf("%d",&value);
        if(value!=0)
        {
            quantity++;
        }
    }
    while(value!=0);

    printf("La cantidad de valores ingresados es: %d", quantity);

}


///5.



///7. Entregar el rango númerico de un conjunto de datos.
void range()
{

    float value;
    float min;
    float max;
    int quantity;
    float avg;


    printf("Ingrese la cantidad de numeros de su conjunto de datos\n");
    scanf("%d",&quantity);

    for(int i = 0; i<quantity; i++)
    {
        printf("Ingrese un valor: \n");
        scanf("%f",&value);
        printf("Valor %d: %f\n",i,value);

        if(i==0)
        {
            min = value;
            max = value;
        }
        else
        {
            if(value<min)
            {
                min = value;
            }
            else
            {

                if(value>max)
                {
                    max = value;
                }
            }

        }

    }

    avg = max - min;
    printf("El rango entre el mayor numero %.2f y el menor %.2f es: %.2f",max,min,avg);

}

/// 8.  Definir un algoritmo que permita adivinar un número entre 1 y 100.
void random()
{
    int value;
    int numberUser;

    srand(time(0));

    value = rand()%100+1;
    printf(" El valor a adivinar: %d \n",value);
    do
    {
        printf("<<<Este es el juego adivinador. Ingrese un numero entre 1 y 100.>>>>>\n");
        scanf("%d",&numberUser);

        if(numberUser> value)
        {
            printf("El numero ingresado es mayor al valor a adivinar\n");
        }
        else
        {
            if(numberUser<value)
            {
                printf("El numero ingresado es menor al valor ingresado\n");
            }
            else
            {
                printf("Felicitaciones adivinaste el numero\n");
            }

        }

    }
    while(numberUser!=value);





}





