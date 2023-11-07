/*
Alunno:		Alessandro Circhetta
Classe: 	3c inf
Data:		01/05/2022
Esercizio: 	esercitazione per interrogazione -- ricreare una sorta di scacchiera dove lo 0 rappresenta il bianco e l' 1 rappresenta il nero 
            (per farlo è stato fatto un altro es precedente che consisteva nel rendere tutti 1 i valori delle colonne dispari e tutti 0 i valori delle colonne pari)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

int init(int matrice[MAX][MAX])
{
    int rig = 0, col = 0, n = 0;

    for (rig = 0; rig < MAX; rig++)
    {
        for (col = 0; col < MAX; col++)
        {
            if (rig%2==0)
            {
                if (col%2==0)
                    matrice[rig][col] = 0;
                else
                    matrice[rig][col] = 1;
            }
            else
            {
                if (col%2==0)
                    matrice[rig][col] = 1;
                else
                    matrice[rig][col] = 0;                 
            }
            printf(" %01d", matrice[rig][col]);
        }
        printf("\n");
    } 
}

int main()
{
    int matr[MAX][MAX];
    
    init(matr);
    
    return 0;
}

