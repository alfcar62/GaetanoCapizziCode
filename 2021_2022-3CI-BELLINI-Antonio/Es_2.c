/***************************************************************************************************
Autore: Bellini Antonio
Data: 06/10/2021
Classe: 3C INFORMATICA
Questo programma, dopo aver preso in INPUT un valore in secondi, lo traforma in ore,minuti e secondi.
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int main()
 	{
 	 int ore,min,sec,secIniz;
 	 printf("Inserisci un valore in secondi-->");
 	 scanf("%d",&secIniz);
	 ore=secIniz/3600;
 	 min=(secIniz-(ore*3600))/60;
	 sec=(secIniz-(ore*3600)-(min*60)); 
 	 printf("%d secondi equivalgono a %d ore, %d minuti, e %d secondi",secIniz,ore,min,sec);

	 return 0;
	}
