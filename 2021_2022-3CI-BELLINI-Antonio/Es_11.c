/*****************************************************************************************************
Consegna: es 11


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 03/11/2021
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
{
    //Caso 1
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
	  }while(cont<ripetizione);
	    printf("Il minore tra i numeri inseriti vale: %d",min);

     //Caso 2
     int ripetizione,numero,min,i,cont=0;
	 do
	 {
	    printf("Inserisci il numero di numeri che vuoi inserire-->");
	    scanf("%d",&ripetizione);
	 }while(ripetizione<1);
	 
     while(cont<ripetizione)
	 { 
	    printf("Inserisci il %d numero:",i);
	    scanf("%d",&numero);	
	    cont++;
	    if(numero<min||cont==1)
	    {
	        min=numero;
	    }
	    i++;
	  }
	    printf("Il minore tra i numeri inseriti vale: %d",min);

     //Caso 3
     int ripetizione,numero,min,i,cont;
	 do
	 {
	    printf("Inserisci il numero di numeri che vuoi inserire-->");
	    scanf("%d",&ripetizione);
	 }while(ripetizione<1);

	 for(cont=0;cont<ripetizione;cont++)
	 {
	    printf("Inserisci il %d numero:",i);
	    scanf("%d",&numero);	
	    if(numero<min||cont==0)
	    {
	        min=numero;
	    }
	    i++;
	  }
	    printf("Il minore tra i numeri inseriti vale: %d",min);
	 
	 
	 
	 
	 
	
	 
	 
	 
	return 0;
}