#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio13();
void ejercicio14();

void ordernacionPorInsercion();

int main()
{
    srand(time(NULL));
    int option;
    printf("<<<Ingrese el n�mero del ejercicio>>>\n");
    printf("1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas inicializadas en vac�o\n");
    printf("2. Cargar desde el teclado la pila ORIGEN e inicializar en vac�o la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO \n");
    printf("3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.\n");
    printf("4. Cargar desde el teclado la pila ORIGEN e inicializar en vac�o la pila DESTINO. Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dej�ndolos en el mismo orden. \n");
    printf("5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso. \n");
    printf("6. Pasar el primer elemento (tope) de la pila DADA a su �ltima posici�n (base), dejando los restantes elementos en el mismo orden. \n");
    printf("7. Pasar el �ltimo elemento (base) de la pila DADA a su primera posici�n (tope), dejando los restantes elementos en el mismo orden. \n");
    printf("8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa. \n");
    printf("9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado. \n");
    printf("10. Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales (en cantidad de elementos, valores que contienen y posici�n de los mismos). Mostrar por pantalla el resultado. \n ");
    printf("11. Suponiendo la existencia de una pila MODELO que no est� vac�a, eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO. \n");
    printf("12. Suponiendo la existencia de una pila MODELO (vac�a o no), eliminar de la pila DADA todos los elementos que existan en MODELO. \n");
    printf("13. Suponiendo la existencia de una pila L�MITE, pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES. \n");
    printf("14. Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. (NO contar los elementos) \n");
    printf("15. GUIA 2 - Dada la pila ORIGEN ordenarla en forma ascendente por m�todo de inserci�n dejando el resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.  \n");
    scanf("%d",&option);
    system("cls");
    switch(option)
    {
    case 1:
        ejercicio1();
        break;
    case 2:
        ejercicio2();
        break;
    case 3:
        ejercicio3();
        break;
    case 4:
        ejercicio4();
        break;
    case 5:
        ejercicio5();
        break;
    case 6:
        ejercicio6();
        break;
    case 7:
        ejercicio7();
        break;
    case 8:
        ejercicio8();
        break;
    case 9:
        ejercicio9();
        break;
    case 10:
        ejercicio10();
        break;
    case 11:
        ejercicio11();
        break;
    case 12:
        ejercicio11();
        break;
    case 13:
        ejercicio13();
        break;
    case 14:
        ejercicio14();
        break;
    case 15:
        ordernacionPorInsercion();



    }


    return 0;
}

/// 1. Cargar desde el teclado una pila DADA con 5 elementos.
///    Pasar los tres primeros elementos a la pila AUX1 y los dos
///    restantes a la pila AUX2, ambas pilas inicializadas en vac�o.


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

    apilar(&aux1,desapilar(&dada));
    apilar(&aux1,desapilar(&dada));
    apilar(&aux1,desapilar(&dada));

    //paso 2 elementos a aux2
    apilar(&aux2,desapilar(&dada));
    apilar(&aux2,desapilar(&dada));


    printf("dada");
    mostrar(&dada);
    printf("aux1");
    mostrar(&aux1);
    printf("aux2");
    mostrar(&aux2);

}

//2. Cargar desde el teclado la pila ORIGEN e inicializar en vac�o la pila DESTINO.
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
        fflush(stdin);
        scanf("%c",&control);
    }
    while (control == 's');

    printf("Origen");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {
        apilar(&destino,desapilar(&origen));
    }
    printf("Origen");
    mostrar(&origen);
    printf("Destino");
    mostrar(&destino);
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

    while(!pilavacia(&dada)) // Hago que los elementos vuelvan a dada.
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
///4. Cargar desde el teclado la pila ORIGEN e inicializar en vac�o la pila DESTINO.
///   Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dej�ndolos en el mismo orden.
void ejercicio4()
{

    Pila origen, destino, aux;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    char op;
    int num;

    do
    {
        printf("Ingrese un numero \n");
        scanf("%d",&num);
        apilar(&origen,num);

        printf("\nDesea seguir agregando m�s numeros (s/n)\n");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op=='s');

    printf("\nPila ORIGEN cargada inicial");
    mostrar2(&origen);



    while(!pilavacia(&origen))
    {
        apilar(&aux,desapilar(&origen));
    }
    while(!pilavacia(&aux))
    {
        apilar(&destino,desapilar(&aux));
    }

    printf("\nPila ORIGEN descargada");
    mostrar2(&origen);

    printf("\n Pila DESTINO cargada");
    mostrar2(&destino);





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


// 6. Pasar el primer elemento (tope) de la pila DADA a su �ltima posici�n (base),
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


//7. Pasar el �ltimo elemento (base) de la pila DADA a su primera posici�n (tope),
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
///     valores que contienen y posici�n de los mismos). Mostrar por pantalla el resultado.
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

    //int na=0;
    //int nb=0;
    int flag = 0;


    char c;

    printf("Ingrese elementos para la pila a \n");

    do
    {
        leer(&a);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &c);
        //na++;
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
        // nb++;
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


/// 11- 12. Suponiendo la existencia de una pila MODELO (vac�a o no),
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



/// 13. Suponiendo la existencia de una pila L�MITE,
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
        printf("%c",cont4=getch()); // cont4 = getch();
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
    printf("<<<<<<<<<<La pila dada>>>>>>>>>>>>>>");
    mostrar2(&dada);
    system("pause");
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



void ordernacionPorInsercion()
{
    Pila dada, aux, dato;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&dato);



    for(int i = 0; i<10; i++)
    {
        apilar(&dada,rand()%10+1);
    }

    printf("<<<<<<<< DADA DESORDENADA >>>>>>>>>>>>");
    mostrar2(&dada);


    // apilar(&dato, 3);

    //inserta un dato

//    while((!pilavacia(&dada))&& tope(&dato)<tope(&dada))
//    {
//        apilar(&aux,desapilar(&dada));
//    }
//    apilar(&dada,desapilar(&dato));
//
//    while(!pilavacia(&aux))
//    {
//        apilar(&dada,desapilar(&aux));
//    }

    if(!pilavacia(&dada))
    {

        apilar(&dato,desapilar(&dada));
        while(!pilavacia(&dada))
        {
            if(tope(&dada)>tope(&dato))
            {
                apilar(&dato, desapilar(&dada));
            }
            else
            {
                while(!pilavacia(&dato) && tope(&dato)>tope(&dada))
                {
                    apilar(&aux,desapilar(&dato));
                }
                apilar(&dato, desapilar(&dada));

                while(!pilavacia(&aux))
                {
                    apilar(&dato,desapilar(&aux));
                }
            }
        }
        while(!pilavacia(&dato))
        {
            apilar(&dada,desapilar(&dato));
        }
    }

    printf("\n <<<<<<<< DADA ORDENADA >>>>>>>>>>>>");
    mostrar2(&dada);
}







