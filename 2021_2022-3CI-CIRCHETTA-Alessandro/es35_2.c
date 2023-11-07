/*
Alunno:		Alessandro Circhetta
Classe: 	3c inf
Data:		30/03/2022
Esercizio: 	matrice con diagonali
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>    
#include <string.h>
#include <ctype.h>
#define MAX 20

int main()
{
	int matrice[MAX][MAX];

	int x = 0, col =0, rig = 0;

//azzeramento matrice
    for(rig = 0; rig< MAX; rig++)    
	{
		for(col = 0; col < MAX; col++)
		{
			matrice[rig][col] = 0;

			//printf(" %d", matrice[rig][col]);
		}

		//printf("\n");
	}
//generazione diagonali
	for (x = 0; x < MAX; x++)
	{
		// da sx a dx
		matrice[x][x] = 1;

		// da dx a sx
		matrice[x][MAX - x - 1] = 1;

	}

//stampa
	for(rig = 0; rig< MAX; rig++)
	{
		for(col = 0; col < MAX; col++)
			printf("%02d ", matrice[rig][col]);

		printf("\n");
	}

	return 0;
}
