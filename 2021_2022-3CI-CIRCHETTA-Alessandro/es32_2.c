/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA:Scrivere un programma che chiama una funzione che, dati tre numeri intero in input,  restituisca al main il valor medio.
Il main effettuerà la stampa del risultato ottenuto
Che tipo di passaggio parametri si utilizza? ---> si utilizza per copia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

float media(int a, int b, int c)
{	
    float med;
    float somma = a + b + c;

    return med = somma/3;  
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

	float m = media(n1, n2, n3);
		printf("la media dei tre numeri e':%f", m);

return 0;
}