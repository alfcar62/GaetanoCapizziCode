/*
Autore: Bellini Antonio
Data: 20/10/2021
Classe: 3C INFORMATICA
Programma che esegue la somma di 2 numeri con il metodo della addizione successive.
*/
#include <stdio.h>
#include <stdlib.h>

int main() 
	{
	 int numero,numero2,i,somma;
	 do 
	  {
	   printf("Inserisci il primo numero-->");
	   scanf("%d",&numero);
	   printf("Inserisci il secondo numero-->");
	   scanf("%d",&numero2);
	  }
	  while(numero&&numero2<1);
	  somma=0;
	  for(i=0;i<numero2;i++)
	   {
	   	somma+=numero;
	   }
	  printf("Il prodotto di %d per %d vale %d",numero,numero2,somma);

	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 return 0;
	}
