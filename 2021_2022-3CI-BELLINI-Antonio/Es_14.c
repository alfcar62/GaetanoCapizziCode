/*
Autore: Bellini Antonio
Data: 20/10/2021
Classe 3C INFORMATICA
Programma che legge un numero n positivo e calcola il quadrato con il metodo della somma dei primi n numeri dispari.
*/
#include <stdio.h>
#include <stdlib.h>

int main() 
	{
	 int numero,numeroQuadrato,a,i;
	 do
	  {
	   printf("Inserisci il numero di cui vuoi sapere il quadrato-->");
	   scanf("%d",&numero);
	  }
	  while(numero<1);
	  a=1;
	  numeroQuadrato=0;
	  for(i=0;i<numero;i++)
	    {
		 numeroQuadrato+=a;
		 a+=2;
	    }
	   printf("Il quadrato di %d vale %d",numero,numeroQuadrato);
	
	
	
	
	
	
	
	
	 return 0;
	}
