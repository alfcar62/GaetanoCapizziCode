/***************************************
Consegna: es37

Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 20/04/2022
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define RIG 10
#define COL 10
#define MAX 10

// INIZIALIZZAZIONE DELLA MATRICE A 0
void iniz(int mat[RIG][COL]){
    int r,
        c;

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            mat[r][c] = 0;

            if (c == (COL - 1))
                printf("\n");
        }
    }
}

// STAMPA DELLA MATRICE
void stamp(int mat[RIG][COL]){
    int r,
        c;
    
    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            printf(" %d",mat[r][c]);

            if (c == (COL - 1))
                printf("\n");
        }
    }
}

// POSIZIONI RANDOM DELLE NAVI
void position(int mat[RIG][COL], int row[], int col[]){
    int r,
        c;

    srand(time(NULL));

    row[0] = rand() % 10;
    col[0] = rand() % 10;

    printf("%d %d \n",row[0], col[0]);

    // Posizionamento della prima nave
    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            if ((r == row[0]) && (c == col[0])){
                mat[r][c] = 4;
                printf("%d",mat[r][c]);
            }

            printf(" %d",mat[r][c]);

            if (c == (COL - 1))
                printf("\n");
        }
    }
}


// MAIN
int main(){
    system("cls");

    int matrice[RIG][COL],
        riga[MAX]        ,
        colonna[MAX]     ;

    // Procedura che inizializza a 0 la matrice
    iniz(matrice);

    // Procedura che stampa la matrice
    //stamp(matrice);

    // Procedura che crea riga e colonna random per la prima nave
    position(matrice, riga, colonna);




	return 0;
}