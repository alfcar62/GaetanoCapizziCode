/*
ALLIEVO: Alessandro CIRCHETTA
DATA: 06/10/2021  
CLASSE: 3C INFORMATICA
TESTO:Disegnare il flow chart e scrivere un programma C che legga in input 2 numeri interi e stampi il più piccolo (usare  le istruzioni condizionali).
*/
#include <stdio.h>


int main()
{
    int n1, n2;

	printf("Scrivere il primo numero: ");
	scanf("%d", &n1);
	
	printf("Scrivere il secondo numero: ");
	scanf("%d", &n2);
	
	if (n1 > n2)
	{
		printf("%d \n", n2);
		printf("%d", n1);
	}
	else
	{
		printf("%d \n", n1);	
		printf("%d", n2);
	}
	
	return 0;
}