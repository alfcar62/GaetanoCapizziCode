/*
Alunno:		Alessandro Circhetta
Classe: 	3c inf
Data:		30/03/2022
Esercizio: 	matrice azzerata
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>    
#include <string.h>
#include <ctype.h>
#define MAX 10

int main()
{
	int matrice[MAX][MAX];

	int x = 0, col =0, rig = 0;

	for(rig = 0; rig< MAX; rig++)
	{
		for(col = 0; col < MAX; col++)
		{
			matrice[rig][col] = 0;

			printf(" %d", matrice[rig][col]);

			if (col==MAX - 1)
				printf("\n");
		}
	}
	return 0;
}
