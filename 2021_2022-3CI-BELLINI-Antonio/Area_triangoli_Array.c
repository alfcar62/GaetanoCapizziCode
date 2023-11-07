/*
Autore: Bellini Antonio 
Data: 12/01/2021
Classe: 3C INFORMATICA
Programma che carica in un array di lunghezza n permette di inserire il valore dei lati e calcola l'area.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 3

int main() 
	{
	 int lato[MAX], 
	 	 area[MAX],
	 	 magg,
	 	 pos,
		 i,			//i è usata per il contatore dei valori caricati all'interno dell'array 
		 k;			//k è usata per la stampa dei valori dell'area 
	 
	 for(i=0; i<MAX; i++)
	 	{
	 	 printf("Inserisci un valore da mettere nell'array-->");
		 scanf("%d",&lato[i]);
		 area[i]=lato[i]*lato[i];
		 if(area[i]>magg)
		 	{
		 	 magg=area[i];
		 	 pos=i;
			}
		}
	 for(k=0;k<MAX;k++)
	 	{
	 	 printf("\nIl valore dell'area e' %d",area[i]);	
		}
	 printf("\nIl maggiore e' %d e si trova in posizione %d",magg,i);
	
	 
	 return 0;
	}
