#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define RIG 15
#define COL 15

// Menu per la scelta dei programmi
int menu(){
    int scelta;

    do{
        system("cls");
        printf("Cosa vuoi eseguire?\n1) inizializza una matrice con valori casuali\n2) cerca un numero nella matrice\n");
        printf("3) Diagonali in una matrice\n4) Croce in una matrice\n5) Perimetro della matrice\n\nScelta-->");
        scanf("%d",&scelta);
    }while (scelta < 1 || scelta > 5);
    
    return scelta;
}

// Programma numero 1 del menu
void caso1(int mat[RIG][COL]){
    int r,          // r = righe; indice delle righe della matrice
        c;          // c = colonne; indice delle colonne della matrice

    srand(time(NULL));

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            mat[r][c] = rand() % 10;
            printf(" %d",mat[r][c]);

            if (c == (COL - 1))
                printf("\n");
        }
    }
}

// Programma numero 2 del menu
void caso2(int mat[RIG][COL], int num){
    int r,          // r = righe; indice delle righe della matrice
        c;          // c = colonne; indice delle colonne della matrice

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            mat[r][c] = rand() % 10;
            printf("    %d",mat[r][c]);

            if (c == (COL - 1))
                printf("\n");
        }
    }

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            if (mat[r][c] == num)
                printf("Il numero inserito e' presente nella riga %d e colonna %d\n",r + 1,c + 1);
            else{
            }
        }
    }
}

// Programma numero 3 del menu
void caso3(int mat[RIG][COL]){
    int r,          // r = righe; indice delle righe della matrice
        c;          // c = colonne; indice delle colonne della matrice

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            if ((r == c) || ((r + c) == (COL - 1)))
                mat[r][c] = 1;
            else
                mat[r][c] = 0;

            printf("    %d", mat[r][c]);

            if (c == (COL - 1))
                printf("\n");
        }
    }
}

// Programma numero 4 del menu
void caso4(int mat[RIG][COL]){
    int r,          // r = righe; indice delle righe della matrice
        c;          // c = colonne; indice delle colonne della matrice

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){
            if (c == ((COL - 1)  / 2))
                mat[r][c] = 1;
            else
                mat[r][c] = 0;

            if (r == ((RIG - 1)  / 2))
                mat[r][c] = 1;
            else{
            }

            printf("    %d",mat[r][c]);

            if (c == (COL -1))
                printf("\n");
        }
    }
}

// Programma numero 5 del menu
void caso5(int mat[RIG][COL]){
    int r,          // r = righe; indice delle righe della matrice
        c;          // c = colonne; indice delle colonne della matrice

    for (r = 0; r < RIG; r++){
        for (c = 0; c < COL; c++){  
            if ((r == 0) || (r == (RIG - 1)))
                mat[r][c] = 1;
            else
                mat[r][c] = 0;

            if ((c == 0) || (c == (COL - 1)))
                mat[r][c] = 1;

            printf("    %d",mat[r][c]);

            if (c == (COL - 1))
                printf("\n");        
        }
    }
    
}

int main(){
    // Creo la matrice
    int matrice[RIG][COL];
    // Creo la variabile per il numero che l'utente vuole inserire
    int numero,
        scelta;

    scelta = menu();

    switch (scelta){
        case 1:

            caso1(matrice);
        
        break;
    
        case 2:
            printf("Inserisci un numero-->");
            scanf("%d",&numero);

            caso2(matrice, numero);

        break;

        case 3:

            caso3(matrice);

        break;

        case 4:

            caso4(matrice);

        break;

        case 5:

            caso5(matrice);
        
        break;
    
    }



    return 0;
}
