/***********************************************
CONSEGNA:
Dato un numero n  letto in input, leggere n
numeri e stampare il più piccolo. Effettuare
il controllo dell'input in modo che i numeri
inseriti siano tutti compresi tra 1 e 10.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    19 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiarazioni delle variabili
    int times = 0,
        min   = 0,
        n     = 0,
        i     = 0;

    do
    {
        printf("Inserire quantita' di numeri da analizzare -> ");
        scanf("%d", &times);
    } while (times <= 0);

    for (i = 0; i < times; i++)
    {
        do
        {
            // Chiedere in input il numero
            printf("Inserire un numero compreso tra 1 e 10 --> ");
            scanf("%d", &n);

            // Se il numero inserito è minore, il nuovo numero viene sostituito al precedente
            if (i == 0 || n < min)
                min = n;
        } while (n < 1 || n > 10);
    }

    // Stampare il numero più piccolo
    printf("Il numero piu' piccolo inserito e': %d \n", min);
    return 0;
}
