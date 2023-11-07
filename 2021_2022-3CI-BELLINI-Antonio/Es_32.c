/*****************************************************************************************************
Consegna: es 32 eserczio 1
Funzione che esegue la somma tra 3 numeri in una funzione


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 14/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Caso 1, viene utilizzato un passaggio per copia, non è necessario passare per indirizzo
int risultato;

int somma(int x, int y, int z){

    risultato = x + y + z;
    
    return risultato;
}

int main(){
    
    int num1,
        num2,
        num3;

    printf("Inserisci il primo numero-->");
    scanf("%d",&num1);    
    printf("Inserisci il secondo numero-->");
    scanf("%d",&num2);
    printf("Inserisci il terzo numero-->");
    scanf("%d",&num3);
	 
    somma(num1,num2,num3);

    printf("La somma vale-->%d",risultato);

	 
	return 0;
}