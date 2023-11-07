/*
Autore: Bellini Antonio
Data: 13/10/2021
Classe: 3C INFORMATICA
Programma che stampa in OUTPUT i numeri pari da 1 a 10.
*/
#include <stdio.h>
#include <stdlib.h>


int main() 
	{
	 int i=0,scelta;
	 printf("quale tipo di stampa vuoi effetuare? \nclicca 1 per i numeri pari da 1 a 10\nclicca 2 per i numeri dispari da 1 a 10\n");
	 scanf("%d",&scelta);
	 printf("\n");
	 if(scelta==1)
	 {
	  do
	 {
	  i++;
	  if(i % 2 == 0)
      printf("%d\n",i);
	 }
	 while(i < 10);
	 }
	 else
	 {
	  do
	 {
	  i++;
	  if(i%2==1)
      printf("%d\n",i);
	 }
	 while(i<10);
	 }
	 
	 return 0;
	}
