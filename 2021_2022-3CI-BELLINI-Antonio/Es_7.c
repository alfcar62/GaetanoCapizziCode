/*****************************************************************************************************
Consegna: es7


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 03/11/2021
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
{
     int numero1,numero2,numero3,numero4;
	 char accento=130, accento2=151;
			
	   printf("Inserisci il primo numero-->");
	   scanf("%d",&numero1);
	   printf("Inserisci il secondo numero-->");
	   scanf("%d",&numero2);
	   printf("Inserisci il terzo numero-->");
	   scanf("%d",&numero3);
	   printf("Inserisci il quarto numero-->");
	   scanf("%d",&numero4);
	   if(numero1<numero2&&numero1<numero3&&numero1<numero4)
	   printf("Il primo numero %c il pi%c piccolo",accento,accento2);
	   else
	   if(numero2<numero3&&numero2<numero4)
	   printf("Il secondo numero %c il pi%c piccolo",accento,accento2);
	   else
	   if(numero3<numero4)
	   printf("Il terzo numero %c il pi%c piccolo",accento,accento2);
	   else
	   printf("Il quarto numero %c il pi%c piccolo",accento,accento2);
	 
	
	return 0;
}
