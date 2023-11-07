/*****************************************************************************************************
Consegna: 
Passaggio dei valori di un array per indirizzo 

Spiegaione: int* array --> permette di passare l'indirizzo dell'array (non la copia); gli array vengono
            sempre passati per indirizzo.

Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 01/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_NUMERI 10

void incremento(int* array)
{
    for(int i = 0; i < MAX_NUMERI; i++)
        array[i] += 1;
}


int main() 
{
    int array[MAX_NUMERI] = {1,2,3,4,5,6,7,8,9,10};
	 
	for(int i = 0; i < MAX_NUMERI; i++)
        printf("%d\n",array[i]); 
	 
	incremento(array);

    for(int i = 0; i < MAX_NUMERI; i++)
        printf("%d\n",array[i]);	 
	 
	 
    return 0;
}