#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <conio.h>


void chargeMatrix(int rows, int columns, int matrix[rows][columns]);
void showMatrix(int rows, int columns, int matrix[rows][columns]);
float averageMatrix(int rows,int columns, int matrix[rows][columns]);

int main()
{
    printf("Hello world!\n");
    srand(time(NULL));

    int row = 3;
    int columns = 3;
    int matrix[row][columns];

    chargeMatrix(row,columns,matrix);
    showMatrix(row,columns,matrix);
    float avg = averageMatrix(row,columns,matrix);


    printf("El promedio es %.2f",avg);




    return 0;
}

void chargeMatrix(int rows, int columns, int matrix[rows][columns])
{

    int j = 0;
    for(int i = 0; i<rows; i++)
    {
        for(j = 0; j<columns; j++)
        {
            matrix[i][j] = rand()%10+1;
        }
    }
}

void showMatrix(int rows, int columns, int matrix[rows][columns])
{
    int j = 0;
    for(int i = 0; i<rows; i++)
    {
        for(j = 0; j<columns; j++)
        {
            printf("  %d ", matrix[i][j]);

        }
        printf("\n");
    }
}


float averageMatrix(int rows,int columns, int matrix[rows][columns])
{
    int j =0;
    float avg = 0.0;
    for(int i = 0; i<rows; i++)
    {
        for(j = 0; j<columns; j++)
        {
            avg+=(float)matrix[i][j];
        }

    }
        return (float)avg/(rows*columns);
}
