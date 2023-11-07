/***********************************************
CONSEGNA:
Leggere in input 2 numeri interi e stampi il
più piccolo (usare l'istruzione do-while).

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    09 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiarazione variabili
    int i = 0,
        n = 0,
        r = 2147483647; // Valore massimo consentito dal range signed int32, evita un if nel do while

    do
    {
        // Chiedere in input il numero
        printf("Inserire numero --> ");
        scanf("%d", &n);

        // Se il numero inserito è minore, il nuovo numero viene sostituito al precedente
        if (n < r) r = n;

        // Aumentare il contatore del ciclo
        i++;
    } while (i < 2);

    // Stampare il numero più piccolo
    printf("Il numero piu' piccolo inserito e': %d \n", r);
    return 0;
}
