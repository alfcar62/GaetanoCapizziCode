/*****************************************************************************************************
Consegna: 
Prova di utilizzo delle stringeh e delle funzioni presenti nella libreria string.h

Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 09/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() 
{
	char arr,
		 arr2;
	int l;
		 
	printf("Inserisci un nome-->");
	gets(arr);	
	printf("Inserisci un altro nome-->");
	gets(arr2); 
	 
	lunghezza  = strlen(arr);
	lunghezza2 = strlen(arr2);
	printf("La lunghezza del primo nome inserito e' %d\n",lunghezza);
	printf("La lunghezza del secondo nome e' %d",lunghezza2);

	arr[0]  = toupper(arr[0]); 
	arr2[0] = toupper(arr2[0]);

	controllo = strcmp(arr, arr2);

	if(controllo == 0)
		pintf("I nomi inseriti hanno lo stesso ordine alfabetico");
	
	else
	
	if(controllo > 0)
		printf("Il primo nome è maggiore del secondo");
	
	else
	
	if(controllo < 0)
		printf("Il secondo nome è maggiore del primo");


	puts(arr);
	puts(arr2); 
	 

	return 0;
}