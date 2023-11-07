/*
Alunno:		Alessandro Circhetta
Classe: 	3c inf
Data:		30/03/2022
Esercizio: 	Matrice con Valori Casuali
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>    
#include <string.h>
#include <ctype.h>
#define MAX 10

bool contiene(int mat[MAX][MAX], int val, int* r, int* c) 
{
    for (int riga = 0; riga < MAX; riga++) {
        for (int col = 0; col < MAX; col++) {
            if (mat[riga][col] == val) {
                *r = riga;
                *c = col;
                return true;
            }
        }
    }

    return false;
}
int main()
{
	int matrice[MAX][MAX];

	int x = 0, col =0, rig = 0;

    srand(time(NULL));

	for(rig = 0; rig< MAX; rig++)
	{
		for(col = 0; col < MAX; col++)
		{
			matrice[rig][col] = rand() % 100;

			printf(" %03d", matrice[rig][col]);
		}
        printf("\n");
	}

    printf("che valore devo cercare -->");
    scanf("%d", &x);

    int trig = 0, tcol = 0;
    bool trovato = contiene(matrice, x, &trig, &tcol);

    if(trovato)
        printf("IL VALORE %d SI TROVA NELLA POSIZIONE:\n Riga-->%d\n Colonna %d\n", x, trig, tcol);
    else
        printf("il valore non e' stato trovato");

	return 0;
}