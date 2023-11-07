/***********************************************
CONSEGNA:
Prendere in input due numeri e, utilizzando le
strutture condizionali, stampare prima il più
piccolo e poi il più grande.

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    05 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiarazione variabili
    int n1, n2;

    // Prendere primo numero in input
    printf("Inserire primo numero -> ");
    scanf("%d", &n1);

    // Prendere secondo numero in input
    printf("Inserire secondo numero -> ");
    scanf("%d", &n2);

    if (n1 > n2)
        printf("%d %d \n", n2, n1); // Stampare prima il secondo e poi il primo
    else
        printf("%d %d \n", n1, n2); // Stampare prima il primo e poi il secodno

    return 0;
}
