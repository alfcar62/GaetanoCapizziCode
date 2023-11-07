/************************************************
CONSEGNA:
Scrivere un programma che crea una matrice di
interi quadrata e la inizializza con tutti zeri
e la stampa

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (MinGW/GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    06 Aprile 2022
*************************************************/


#include <stdio.h>
#include <memory.h>

#define RIGHE   5
#define COLONNE 5


int main() {
    int mat[RIGHE][COLONNE];
    memset(mat, 0, sizeof(mat));
}
