/*
    Marco Schiavello 3^CI 16/08/2021

    Realizzare un programma che, data una matrice di n righe ed m colonne, permetta di
    visualizzare il massimo degli elementi di ciascuna riga, il minimo di tutti gli elementi della matrice
    e la media di ciascuna colonna
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define ROW 5
#define COL 10

void createMatrix(int mat[][COL]);
void maxEleRows(int mat[][COL]);
int minEleMatrix(int mat[][COL]);
void aveEleRows(int mat[][COL]);
void printMatrix(int mat[][COL]);
void menu(int * scelta);

/*_______Main_________*/
int main()
{
    int mat[ROW][COL],scelta;
    char foo;
    createMatrix(mat);

    do
    {
        menu(&scelta);
        switch(scelta)
        {
            case 1:
                maxEleRows(mat);
            break;
            case 2:
                printf("il numero minimo e': %d",minEleMatrix(mat));
            break;
            case 3:
                aveEleRows(mat);
            break;
            case 4:
                printMatrix(mat);
            break;
        }

        getch();
    }
    while(scelta > 0 && scelta <5);
}

/**
*   visualizza un menu dove l'utente sceglie che operazaione fare
*   params:
*       @param int * scelta : output : dove viene messa la scelta
*       @return void
*/
void menu(int * scelta)
{
    system("cls");
    printf("Scegliere operazione da fare sulla matrice\n");
    printf("1)stampa massimi per ogni riga\n");
    printf("2)stampa il valore minimo della matrice\n");
    printf("3)stampa la media di ogni riga\n");
    printf("4)stampa matrice\n");
    printf("premi qualsiasi altro numero per uscire ...\n");
    printf("Scelta: ");
    scanf("%d", scelta);
}


/**
*   carica una matrice di numeri casuali
*   params:
*       @param int mat[][COL] : output : matrice da caricare di numeri
*       @return void
*/
void createMatrix(int mat[][COL])
{
    srand(time(0));

    for(int i = 0;i < ROW; i++)
        for(int j = 0;j < COL;j++)
            mat[i][j] = (rand()%100)+1;
}

/**
*   stampa il massimo valore per ogni riga
*   params:
*       @param int mat[][COL] : input : matrice da cui prendere i numeri massimi per ogni riga
*       @return void
*/
void maxEleRows(int mat[][COL])
{
    int maxNum = -1;
    for(int i = 0;i < ROW; i++)
    {
        for(int j = 0;j < COL;j++)
            if(mat[i][j] > maxNum)
                maxNum = mat[i][j];
        printf("il numero minimo nella riga %d e': %d \n",i,maxNum);
        maxNum = -1;
    }

}

/**
*   stampa il valore minimo nella matrice
*   params:
*       @param int mat[][COL] : input : matrice da cui prendere il numero minore
*       @return int : numero minore nella matrice
*/
int minEleMatrix(int mat[][COL])
{
    int minNum = mat[0][0];
    for(int i = 0;i < ROW; i++)
    {
        for(int j = 0;j < COL;j++)
            if(mat[i][j] < minNum)
                minNum = mat[i][j];
    }

    return minNum;
}

/**
*   calcola la media di tutti i numeri su una riga per ogni riga
*   params:
*       @param int mat[][COL] : input : matrice su cui calcolare la media su ogni riga
*       @return void
*/
void aveEleRows(int mat[][COL])
{
    int sum = 0;
    for(int i = 0;i < ROW; i++)
    {
        for(int j = 0;j < COL;j++)
            sum += mat[i][j];
        printf("la media dei numeri nella riga %d e': %.3f \n",i,(float) sum/COL);
        sum = 0;
    }
}

/**
*   stampa la matrice data in input
*   params:
*       @param int mat[][COL] : input : matrice da stamapre
*       @return void
*/
void printMatrix(int mat[][COL])
{
    for(int i = 0;i < ROW; i++)
    {
        printf("\n");
        for(int j = 0;j < COL;j++)
            printf(" %3d ",mat[i][j]);
    }
}
