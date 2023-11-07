/************************************************
CONSEGNA:
Scrivere un programma che crea una matrice di
interi quadrata inizializzata con il valore uno
nella diagonale  principale e nella diagonale
secondaria, e i restanti valorizzati a zero.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (MinGW/GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    06 Aprile 2022
*************************************************/


#include <stdio.h>
#include <memory.h>

#define LATO 5


// Visualizza la matrice
void visualizza(int mat[LATO][LATO]) {
    for (int riga = 0; riga < LATO; riga++) {
        for (int col = 0; col < LATO; col++)
            printf("%01d ", mat[riga][col]);
        
        printf("\n");
    }
}

int main() {
    int mat[LATO][LATO];
    memset(mat, 0, sizeof(mat));    // Imposta a 0 tutte le celle

    // Crea diagonali
    for (int x = 0; x < LATO; x++) {
        mat[x][x] = 1;              // Crea diagonale
        mat[x][LATO - x - 1] = 1;   // Crea diagonale secondaria
    }

    visualizza(mat);

    return 0;
}
