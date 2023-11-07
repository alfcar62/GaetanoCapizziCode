/***********************************************
CONSEGNA:
Dato un numero n  letto in input, leggere n
numeri e stampare il più piccolo

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    11 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiarazioni delle variabili
    int times = 0,
        min   = 0,
        n     = 0,
        i     = 0;

    printf("Inserire quantita' di numeri da analizzare -> ");
    scanf("%d", &times);

    for (i = 0; i < times; i++)
    {
        // Chiedere in input il numero
        printf("Inserire un numero -> ");
        scanf("%d", &n);

        // Se il numero inserito è minore, il nuovo numero viene sostituito al precedente
        if (i == 0 || n < min)
            min = n;
    }

    // Stampare il numero più piccolo
    printf("Il numero piu' piccolo inserito e': %d \n", min);
    return 0;
}
