/**************************************************************************************************************************
Autore: Bellini Antonio
Data: 06/10/2021
Classe: 3C INFORMATICA
Questo programma, dopo aver preso in INPUT un valore di ore,minuti e secondi, converte tutto in secondi, e ne fa la somma.
***************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int main()
 	{
 	 int ore,oreSec,min,minSec,sec,secTot;
 	 
 	 printf("Inserisci un valore in ore-->");
 	 scanf("%d",ore);
 	 printf("Inserisci un valore in minuti-->");
 	 scanf("%d",&min);
 	 printf("Inserisci un valore in secondi-->");
 	 scanf("%d",&sec);
 	 
 	 oreSec=ore*3600;
 	 minSec=min*60;
 	 secTot=oreSec+minSec+sec;
 	 printf("%d ore, %d minuti, %d secondi corrispondono a %d secondi totali",ore,min,sec,secTot);

	 return 0;
	}
