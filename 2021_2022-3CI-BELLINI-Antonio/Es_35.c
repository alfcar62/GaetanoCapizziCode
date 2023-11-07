/*************************************************
Consegna: Esercizio 35

Cognome: Bellini 		Nome: Antonio 
Data: 05/04/2022		Classe: 3C Informatica 
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#define RIG 5
#define COL 5

// Procedura che inizializza a 0 tutta la matrice e crea le due diagonali
void iniz(int mat[RIG][COL]){
	// Indici dei 2 cicli for
	int r,						// r = righe; indice delle righe della matrice
		c;						// c = colonne; indice delle colonne dell matrice

	// Inizializzazione e creazione diagonale principale e secondaria
	for (r = 0; r < RIG; r++){
		for (c = 0; c < COL; c++){
			if ((r == c) || ((r + c) == (COL - 1)))
				mat[r][c] = 1;
			else
				mat[r][c] = 0;
			
			// Stampa del risultato
			printf(" %02d",mat[r][c]);
			
			// Al termine della riga va a capo per la riga successiva
			if (c == (RIG - 1))
				printf("\n");
		}
	}
}


int main(){
	int matrice[RIG][COL];

	// Chiamo la procedura che inizalizza a 0 la matrice e crea le due diagonali
	iniz(matrice);

	return 0;
}