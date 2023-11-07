/*****************************************************************************************************
Consegna: es 8


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 03/011/2021
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
{
    int ripetizione,numero,min,i,cont=0;
	
    do
	{
	    printf("Inserisci il numero di numeri che vuoi inserire-->");
	    scanf("%d",&ripetizione);
	}
	while(ripetizione<1);

	 do
	 {
	    printf("Inserisci il %d numero:",i);
	    scanf("%d",&numero);	
	    cont++;
	    if(numero<min||cont==1)
	    {
	        min=numero;
	    }
	    i++;
	 }while(cont < ripetizione);
	 
        printf("Il minore tra i numeri inseriti vale: %d",min);
	 
     return 0;	 	
}