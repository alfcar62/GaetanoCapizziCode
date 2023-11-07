/***********************************************************************************************************
Consegna: Esercizio 34


Cognome: Bellini 		Nome: Antonio 
Data: 05/04/2022		Classe: 3C Informatica 
************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define RIG 11
#define COL 11

int main(){
	system("cls");

	// Variabili per gli indici dei cicli for
	int	numero = 0,
		c = 0,
		r = 0;


	// Variabili per la matrice
	int tabella[RIG][COL]; 				// Matrice che contiene la tabella pitagorica


	for (r = 0; r < RIG; r++){
		for (c = 0; c < COL; c++){
			tabella[r][c] = (r)*(c);
			printf(" %02d",tabella[r][c]);

			if (c == (COL - 1))
				printf("\n");
		}
	}
	return 0;
}