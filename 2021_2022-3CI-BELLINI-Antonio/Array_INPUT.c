/*
Autore: Bellini Antonio 
Data: 09/11/2021
Classe: 3C INFORMATICA
Programma con arrary definito da tastiera.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main() 
	{
	 int i, arr[MAX];
	 
	 for(i=0;i<MAX;i++)
	  {
	  	printf("Inserisci il %d numero-->",i+1);
	  	scanf("%d",&arr[i]);
	  }
	  	for(i=0;i<MAX;i++)
	  	 {
	  	  printf("%d\n",arr[i]);
		 }

	 
	 return 0;
	}