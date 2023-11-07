/***********************************************
CONSEGNA:
Leggere 2 numeri positivi e calcolarne la
divisione con il metodo delle sottrazioni
successive.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    20 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiaraizone variabili
    int n1 = 0,
        n2 = 0,
        r  = 0;
    
    // Output iniziale
    printf("Esercizio 13: Divisione con sottrazioni successive \n");

    // Input del primo numero
    do
    {
        printf("Inserire primo numero -> ");
        scanf("%d", &n1);
    } while (n1 < 1);

    // Input del secondo numero
    do
    {
        printf("Inserire secondo numero -> ");
        scanf("%d", &n2);
    } while (n2 < 1);

    // Effettua la divisione per sottrazioni successive
    for (r = 0; n1 - n2 >= 0; r++)
        n1 -= n2;

    // Output risultato
    printf("Il quoziente e': %d\n", r);
    return 0;
}
