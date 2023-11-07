/*
Autore: Bellini Antonio
Data:03/11/2021
Classe: 3C INFORMATICA
Programma che scrive n volte i numeri con la tecnica della sequenza di Fibonacci.
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
	{	
	 int n,i,numero=0,numero2=1,fibonacci;
	 do
	 {
	  printf("Quanti numeri vuoi stampare?-->");
	  scanf("%d",&n);
	 }while(n<0);
	  printf("%d\n",numero);
		for(i=1; i<n; i++)
	  	 {
	  	  fibonacci=numero+numero2;
	  	  printf("%d\n",fibonacci);
	  	  numero=numero2;
	  	  numero2=fibonacci;
		 }
	 return 0;
	}
