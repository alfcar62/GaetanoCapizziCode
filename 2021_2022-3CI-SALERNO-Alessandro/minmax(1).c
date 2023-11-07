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
    int x, y;

    // Prendere primo numero in input
    printf("Inserire primo numero -> ");
    scanf("%d", &x);

    // Prendere secondo numero in input
    printf("Inserire secondo numero -> ");
    scanf("%d", &y);

    if (x > y)
        printf("%d %d \n", y, x); // Stampare prima il secondo e poi il primo
    else
        printf("%d %d \n", x, y); // Stampare prima il primo e poi il secodno

    return 0;
}
