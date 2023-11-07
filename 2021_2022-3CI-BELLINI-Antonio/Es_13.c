/*
Autore: Bellini Antonio
Data: 20/10/2021
Classe: 3C INFORMATICA
Programma che esegue la divisone tra numero e numero2 usando la tecnica delle sottrazioni succesive.
*/
#include <stdio.h>
#include <stdlib.h>

int main() 
	{
	 int i,resto,n1,n2,sup;

	 do
 	{
  	 printf("Dammi il valore del primo numero: ");
  	 scanf("%d",&n1);
 	}
	while(n1<1);
	 sup=n1;
	do
 	 {	
  	  printf("Dammi il valore del secondo numero: ");
  	  scanf("%d",&n2);
 	 }
	while(n2<1);
	do
 	 {
  	  i=i+1;
  	  n1=n1-n2;
 	 } 
	while(n1>=n2);
	printf("Il risultato vale: %d\n",i);
	printf("Il resto vale: %d",n1);
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 return 0;
	}
