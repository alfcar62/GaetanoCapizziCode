/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA:Scrivere un programma che chiama una funzione che, dati tre numeri interi in input, ne calcoli la somma e la restituisca il risultato al main.
Il main effettuerà la stampa del risultato ottenuto
Che tipo di passaggio parametri si utilizza?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int somma(int a, int b, int c)
{	
    int somm;

    return somm = a + b + c;  
}


int  main()
{
    int n1 = 0,
        n2 = 0,
        n3 = 0;

    printf("inserire il primo numero -->");
    scanf("%d",&n1);

    printf("inserire il secondo numero -->");
    scanf("%d",&n2);

    printf("inserire il terzo numero -->");
    scanf("%d",&n3);

		
	int s = somma(n1, n2, n3);
		printf("la somma dei tre numeri e':%d", s);

return 0;
}

char inputstringa(char stringa[10])
{
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        printf("inserire il numero ad indirizzo %d", i);
        scanf("%d", &stringa[i]);
    }
    
}