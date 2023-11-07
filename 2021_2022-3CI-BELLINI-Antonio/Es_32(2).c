/*****************************************************************************************************
Consegna: es 32 esercizio 2
Funzione che esegue la media tra 3 numeri in una funzione 

Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 14/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int media(int x, int y, int z, int media){
	media = (x + y + z) / 3;

	return media;
}

int main(){
	 
	 int ris  = 0,
	 	 num1 = 0,
	 	 num2 = 0,
		 num3 = 0;

	printf("Inserisici il primo numero-->");
	scanf("%d",&num1);
	printf("Inserisci il secondo numero-->");
	scanf("%d",&num2);
	printf("Inserisci il terzo numero-->");
	scanf("%d",&num3);
	 
	media(num1, num2, num3, ris); 

	ris = media(num1, num2, num3, ris);

	printf("La media vale-->%d",ris);
	 
	return 0;
}