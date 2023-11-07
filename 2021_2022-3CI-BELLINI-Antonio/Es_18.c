/*
Autore: Bellini Antonio 
Data: 09/11/2021
Classe: 3C INFORMATICA
Programma che dice i numeri pari e dispari con l'utilizzo dell'array.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() 
	{
	 //numero di numeri
	 //numero di input 
	 //due array
	 //for che prende input e mette i valori in array
	
	 int p=0,d=0,num=0,times=0,pari[MAX],dispari[MAX];
	 
	 printf("Quanti numeri vuoi analizzare?-->");
	 scanf("%d",&times);
	 	 
	 for(num=0;num<times*2;num++)
	  {
	  	if(num%2==0)
	  	{
	  	 pari[p]=num;
	  	 p++;
	  	}
	  	else
	  	{
	  	 dispari[d]=num;
	  	 d++;
		}
	  }
	printf("Pari:\n");
	  for(num=0;num<p;num++)
	  	printf(" %d ",pari[num]);
	
	printf("\n\nDispari:\n");
	  for(num=0;num<d;num++)
	  	printf(" %d ",dispari[num]);
	 
	  	 	  	 
	
	 return 0;
	}
