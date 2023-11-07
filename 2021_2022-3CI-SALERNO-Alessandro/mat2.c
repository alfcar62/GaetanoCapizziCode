/************************************************
CONSEGNA:

Scrivere un programma che crea una matrice di
interi quadrata inizializzata con valori causali.
Una volta creata ed inizializzata, chiedere in
input un numero e stampare se quel numero è
presente o meno nella matrice (in tal caso
indicare in quale posizione (riga,colonna))

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (MinGW/GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    06 Aprile 2022
*************************************************/


#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <stdbool.h>

#define RIGHE   5
#define COLONNE 5


bool contiene(int mat[RIGHE][COLONNE], int val, int* r, int* c) {
    for (int riga = 0; riga < RIGHE; riga++) {
        for (int col = 0; col < COLONNE; col++) {
            if (mat[riga][col] == val) {
                *r = riga;
                *c = col;
                return true;
            }
        }
    }

    return false;
}

void genera(int mat[RIGHE][COLONNE]) {
    for (int riga = 0; riga < RIGHE; riga++)
        for (int col = 0; col < COLONNE; col++)
            mat[riga][col] = rand() % 100;
}

int main() {
    srand(time(NULL));

    int mat[RIGHE][COLONNE];
    memset(mat, 0, sizeof(mat));
    genera(mat);

    int input, r, c;
    printf("Inserire valore da cercare in matrice -> ");
    scanf("%d", &input);

    if (contiene(mat, input, &r, &c))
        printf("Il valore e' contenuto nella matrice in posizione %d:%d\n", r, c);
    else
        printf("Il valore non e' contenuto nella matrice\n");

    return 0;
}
