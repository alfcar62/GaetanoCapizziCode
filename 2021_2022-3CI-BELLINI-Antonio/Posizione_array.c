/*
Autore: Bellini Antonio 
Data: 08/11/2021
Classe: 3C INFORMATICA 
Prova array numero 2.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VAL 10

int main() 
	{
	 int arr[MAX_VAL], 
	 	 i, 
		 pos;
	 
	 printf("Di quale posizione vuoi sapere il contenuto?-->");
	 scanf("%d",&pos);
	 
	 for(i = 0; i < MAX_VAL; i++)
	  {
	  	arr[i] = 9 - i;
	  }
	  
	  printf("L'elemento in posizione %d vale %d",pos, arr[pos]);
	
	 return 0;
	}
