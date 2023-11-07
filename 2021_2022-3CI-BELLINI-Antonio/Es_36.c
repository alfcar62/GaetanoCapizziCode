/*************************************************
Consegna: Esercizio 36

Cognome: Bellini 		Nome: Antonio
Data: 05/04/2022		Classe: 3C Informatica
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define RIG 5
#define COL 5

void iniz(int mat[RIG][COL], int num){
    int r,                          // r = righe; usato per l'indice delle righe nella matrice
        c;                          // c = colonne; usato per l'indice delle colonne nella matrice

    srand(time(NULL));

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            mat[r][c] = rand() % 10 + 1;
            printf(" %02d",mat[r][c]);

            if (c == (RIG - 1))
                printf("\n");
        }
    }

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            if (num == mat[r][c])
                printf("\nNumero trovato alla riga: %d\ncolonna: %d\n",r + 1,c + 1);
            else if ((num != mat[r][c]) && (r == RIG) && (c == COL))
                printf("\nIl numero inserito non e' stato trovato!\n");
        }
    }
}


int main(){
    int matrice[RIG][COL],      // matrice dei numeri casuali
        numero;                 // numero che l'utente darà in input e che verrà confrontato con gli altri numeri presenti nella matrice

    printf("Inserisci il numero che vuoi-->");
    scanf("%d",&numero);

    iniz(matrice, numero);

    return 0;
}