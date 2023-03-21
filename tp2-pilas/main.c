#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    printf("Hello world!\n");
    return 0;
}

/// 1. Cargar desde el teclado una pila DADA con 5 elementos.
///    Pasar los tres primeros elementos a la pila AUX1 y los dos
///    restantes a la pila AUX2, ambas pilas inicializadas en vacío.


void ejercicio1()
{

    Pila dada,aux1,aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char control;
    int i=0;

    //bucle de cargar pila carga
    do
    {
        leer(&dada);

        printf("Desea continuar? s/n");
        fflush (stdin);
        scanf("%c", &control);

    }
    while (control=='s');

    //Mostrar la cantidad de elementos que hay en dada

    printf("dada");
    mostrar(&dada);


    //desapilar 3 elementos y apilar en aux1
    while(!pilavacia(&dada)&& i<3)
    {
        apilar(&aux1,desapilar(&dada));

        i++;

    }
    i=0;
    //paso 2 elementos a aux1
    while(!pilavacia(&dada) && i<2)
    {
        apilar(&aux2,desapilar(&dada));
    }
    printf("dada");
    mostrar(&dada);
    printf("aux1");
    mostrar(&aux1);
    printf("aux2");
    mostrar(&aux2);

}

//2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
//Pasar todos los elementos de la pila ORIGEN a la pila DESTINO//
void ejercicio2()
{
    Pila origen,destino;
    inicpila(&origen); // en vacio ambas
    inicpila(&destino);

    char control;

    //bucle de carga

    do
    {
        leer(&origen);
        printf("Desea continuar? s/n");
        //fflush(stdin);
        scanf("%c",&control);
    }
    while (control == 's');

    printf("Origen");
    mostrar(&origen);

//Primer pasada de pilas
    while(!pilavacia(&origen))
    {
        apilar(&destino,desapilar(&origen));
    }
    printf("Origen");
    mostrar(&origen);
    printf("Destino");
    mostrar(&destino);

//Segunda pasada de pila
    while (!pilavacia(&destino))
    {
        apilar(&origen,desapilar(&destino));
    }

    printf("Destino");
    mostrar(&destino);
    printf("Origen");
    mostrar(&origen);

}


// 3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.

void ejercicio3()
{
    Pila dada,distinto,aux;

    inicpila(&dada);
    inicpila(&distinto);
    inicpila(&aux);

    char control;

    //ciclo de carga de la pila
    do
    {
        leer(&dada);
        printf("Desea continuar? [s/n] \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    while(control=='s');

    printf("Dada");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux,desapilar(&dada));
    }
    while(!pilavacia(&aux))
    {
        if(tope(&aux) == 8)
        {
            apilar(&dada,desapilar(&aux));
        }
        else
        {
            apilar(&distinto,desapilar(&aux));
        }
    }
    printf("Pila dada");
    mostrar(&dada);

    printf("Pila distinto");
    mostrar (&distinto);

}


//5. Cargar desde el teclado la pila DADA.
// Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.//
void ejercicio5()
{

    Pila dada,paso1,paso2;

    inicpila(&dada);
    inicpila(&paso1);
    inicpila(&paso2);

    char control;

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n");
        fflush(stdin);
        scanf("%c",&control);
    }
    while (control == 's');

    printf("Dada");
    mostrar(&dada);

    while (!pilavacia(&dada))
    {
        apilar(&paso1,desapilar(&dada));
    }
    while (!pilavacia(&paso1))
    {
        apilar(&paso2,desapilar(&paso1));
    }
    while(!pilavacia(&paso2))
    {
        apilar(&dada,desapilar(&paso2));
    }

    printf("dada");
    mostrar(&dada);

}


// 6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
// dejando los restantes elementos en el mismo orden.
void ejercicio6()
{

    Pila dada,aux1,aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char control;

//ciclo de carga
    do
    {
        leer(&dada);
        printf("Desea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control=='s');

    printf("pila dada");
    mostrar(&dada);

//aca paso el primer elemento a una pila
    if(!pilavacia(&dada))
    {
        apilar (&aux1,desapilar(&dada));
    }

//aca paso los elementos restantes a otra pila
    while(!pilavacia(&dada))
    {
        apilar(&aux2,desapilar(&dada));
    }
// aca paso el primer elemento a la base de la pila dada
    while(!pilavacia(&aux1))
    {
        apilar(&dada,desapilar(&aux1));
// aca el resto de los elementos a la pila dada
    }
    while(!pilavacia(&aux2))
    {
        apilar(&dada,desapilar(&aux2));
    }
//muestro la pila dada como queda
    printf("Pila dada final");
    mostrar(&dada);


}


//7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope),
// dejando los restantes elementos en el mismo orden.

void ejercicio7()
{
    Pila dada,aux1,aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char control;

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n");
        fflush(stdin);
        scanf("%c",&control);

    }
    while (control == 's');

    printf("pila dada inicial");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux1,desapilar(&dada));
    }
    if(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }
    while(!pilavacia(&aux1))
    {
        apilar(&dada,desapilar(&aux1));
    }
    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("La pila dada final");
    mostrar(&dada);
}

// 8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.

void ejercicio8()
{

    Pila mazo,jugador1,jugador2;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    char control;

    do
    {
        leer(&mazo);
        printf("Desea seguir agregando mas datos? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control == 's');

    while(!pilavacia(&mazo))
    {
        apilar(&jugador1,desapilar(&mazo));

        if(!pilavacia(&mazo))
        {
            apilar(&jugador2,desapilar(&mazo));
        }
    }

    printf("Las cartas del jugador 1");
    mostrar(&jugador1);
    printf("Las cartas del jugador 2 \n");
    mostrar(&jugador2);

}

/// 9. Comparar la cantidad de elementos de las pilas A y B.
///    mostrar por pantalla el resultado.

void ejercicio9()
{



}


/// 10. Comparar las pilas a y B, evaluando si son completamente iguales (en cantidad de elementos,
///     valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.
void ejercicio10()
{
    Pila a;
    Pila b;
    Pila auxA;
    Pila auxB;

    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    int na=0;
    int nb=0;
    int flag = 0;


    char c;

    printf("Ingrese elementos para la pila a \n");

    do
    {
        leer(&a);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &c);
        na++;
    }
    while (c=='s');

    system("cls");

    printf("Ingrese elementos para la pila B \n");

    do
    {
        leer(&b);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &c);
        nb++;
    }
    while (c=='s');

    while((!pilavacia(&a)) && (!pilavacia(&b)) && flag == 0 )
    {
        if((tope(&a) == tope(&b)))
        {
            apilar(&auxA, desapilar(&a));
            apilar(&auxB, desapilar(&b));
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Las pilas son iguales\n");
    }
    else
    {
        if(flag == 1)
        {
            printf("Las pilas son distintas\n");
        }
    }

}


/// 11- 12. Suponiendo la existencia de una pila MODELO (vacía o no) que no esté vacía,
///     eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.


void ejercicio11()
{
    Pila modelo,dada,aux1,aux2,descarte;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&descarte);
    char control;

    //Ingreso de datos
    printf("Ingrese los datos para la pila Modelo\n");
    do
    {
        leer(&modelo);
        printf("Desea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control == 's');
    system("cls");

    printf("Ingrese los datos para la pila Dada\n");
    do
    {
        leer(&dada);
        printf("Desea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
    while (control == 's');
    system("cls");

    // Algotimo del ejercicio 11
    system("pause");

    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&dada))
        {
            if(tope(&dada)==tope(&modelo))
            {
                apilar(&descarte,desapilar(&dada));
            }
            else
            {
                apilar(&aux2,desapilar(&dada));
            }

        }

        while(!pilavacia(&aux2))
        {
            apilar(&dada,desapilar(&aux2));
        }
//Se agrega la parte para el algoritmo del ejercicio 12.

        apilar(&aux1,desapilar(&modelo));
    }
    while(!pilavacia(&aux1))
    {
        apilar(&modelo,desapilar(&aux1));
    }

    printf("Procesando pila...\n");
    system("pause");

    printf("La pila dada tiene los siguientes elementos\n");
    mostrar(&dada);

    system("pause");

    printf("\nLa pila modelo tiene los siguientes elementos\n");
    mostrar(&modelo);
}



/// 13. Suponiendo la existencia de una pila LÍMITE,
/// pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES,
/// y los elementos que sean menores a la pila MENORES.
void ejercicio13()
{

    Pila limite,dada,mayores,menores;
    inicpila(&dada);
    inicpila(&limite);
    inicpila(&mayores);
    inicpila(&menores);
    char cont4;

    printf("Ingrese los valores de la pila limite,(acuerdese que el ultimo valor ingresado sera el limite\n)");
    do
    {
        leer(&limite);
        printf("\nDesea continuar? s/n");
        printf("%c",cont4=getch());
        printf("\n");
    }
    while (cont4=='s');
    system("cls");

    printf("Ingrese los valores para la pila dada \n");
    do
    {
        leer(&dada);
        printf("\nDesea continuar? s/n");
        printf ( "%c",cont4 = getch());
        printf ("\n");
    }
    while (cont4 == 's');
    system("cls");

    while(!pilavacia(&dada))
    {
        if(tope(&dada)>=tope(&limite))
        {
            apilar(&mayores,desapilar(&dada));
        }
        else
        {
            apilar(&menores,desapilar(&dada));
        }
    }
    printf("La pila limite estba cargada por lo siguientes elementos, preste atencion al tope\n");
    mostrar(&limite);

    system("pause");
    system("cls");

    printf("Elementos mayores o iguales al tope de limite\n");
    mostrar(&mayores);

    system("pause");

    printf("\nElementos menores al tope de limite");
    mostrar(&menores);

}

/// 14. Determinar si la cantidad de elementos de la pila DADA es par.
///     Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y
///     si es impar pasar el tope a la pila IMPAR.

void ejercicio14()
{
    Pila dada,par,impar,aux1,aux2,aux3;
    inicpila(&dada);
    inicpila(&par);
    inicpila(&impar);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);

    char cont4;
//ciclo de carga.
    do
    {
        leer(&dada);
        printf("Desea continuar? s/n\n");
        printf("%c",cont4=getch());
        printf("\n");
    }
    while(cont4 =='s');
    system("cls");
//repartir dos numeros
    while(!pilavacia(&dada))
    {
        apilar(&aux1,desapilar(&dada));

        // si la pila es impar, la mayor cantidad de numeros va a quedar en aux1

        if (!pilavacia(&dada))
        {
            apilar(&aux2,desapilar(&dada));
        }
    }
    printf("Procesando Pila...\n");
    system("pause");
    system("cls");

//aca debe saber si la pila es par o impar.


    while(!pilavacia(&aux1)&&!pilavacia(&aux2))
    {
        //empeze primero con aux2 para que me de el tope en la pila impar cuando se hace la salida por consola.

        apilar(&aux3,desapilar(&aux2));
        apilar(&aux3,desapilar(&aux1));

    }
    if(!pilavacia(&aux1))
    {
        apilar(&aux3,desapilar(&aux1));
        system("pause");
        apilar(&impar,desapilar(&aux3));
        printf("La pila es impar y el tope es:\n");
        mostrar(&impar);
    }
    else
    {
        apilar(&par,desapilar(&aux3));
        printf("La pila es par y el tope es:\n");
        mostrar(&par);
    }


}
