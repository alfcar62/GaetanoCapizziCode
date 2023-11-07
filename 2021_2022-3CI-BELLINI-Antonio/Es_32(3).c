/*****************************************************************************************************
Consegna: es 32
Esercizio 3: doppio tra 3 numeri 

Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 14/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_VAL 4

int doppio(int arr, int doppio){
    for(int i = 0; i < MAX_VAL; i++){
        doppio = arr[i] * 2; 
    }
}

int main(){
	 int arr[MAX_VAL];
	 
     for (i = 0; i = MAX_VAL; i++){
         printf("Inserisci un numero-->");
         scanf("%d",&arr[i]);
     }

     doppio(arr, ris)

     ris = doppio(arr, ris);

	return 0;
}