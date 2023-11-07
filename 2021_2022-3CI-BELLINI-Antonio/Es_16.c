/*
Autore: Bellini Antonio 
Data: 09/11/2021
Classe: 3C INFORMATICA
Programma che stampa gli n numeri primi.
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
	{	
	 int n=0,
	 	 i=0,
	   num=0,
	   div=0,
	   primi=0;
	 
	 printf("Inserire numero di numeri da analizzare-->");
	 scanf("%d",&primi);
	 
	 for(i=0;i<primi;i++)
	  {
	  	do
	  	 {
	  	  num++;
	  	  div=0;
	  	  
	  	  for(n=2;n<num;n++)
	  	  	if(num%n==0)
	  	  		div++;
		 }while (div!=0);
		 
		 printf(" %d ",num);
	  }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 return 0;
	}
