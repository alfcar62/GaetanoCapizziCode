/*
Alunno:		Alessandro Circhetta
Classe: 	3c inf
Data:		30/03/2022
Esercizio: 	DATO UN NUMERO DI RAGAZZI E LE LORO ETA' CALCOLARE IL NUMERO DI MINORENNI E MAGGIORENNI, FARE LA MEDIA DELLA LORO ETA' E STAMPARE UN AVVISO NEL CASO I MINORENNI RAPPRESENTANO + DEL 50% DEL GRUPPO
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  
#include <windows.h>    
#include <string.h>
#include <ctype.h>
#define RIGHE 10
#define COLONNE 10

int main()
{
    int mat [RIGHE][COLONNE];    //inizializzazione della matrice
    int rig =0, col = 0,i;


    for(rig = 0; rig<RIGHE; rig++)
    {
        printf("\n----------------------------------------------------------\n");
        for(col = 0; col<COLONNE; col++)
        {

            mat[rig][col] = rand() % 10;

            printf("| %02d |",mat[rig][col]);
        }
    }
    printf("\n----------------------------------------------------------");
    return 0;
}