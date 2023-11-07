/*****************************************************************************************************
Consegna: es 4


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 06/10/2021
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
{
    int num1,
        num2,
        nMagg,
        nMin;

        printf("Inserisci il primo numero-->");
        scanf("%d",&num1);
        printf("\nInserisci il secondo numero-->");
        scanf("%d",&num2);

        if(num1 > num2){
            nMagg = num1;
            nMin = num2;
            printf("Il primo numero inserito e' il maggiore");
        }
        else{
            nMagg = num2;
            nMin = num1;
            printf("Il secondo numero inserito e' il maggiore");    
        }

	 
	 
	 
	 
	 
	
	 
	 
	 
	return 0;
}