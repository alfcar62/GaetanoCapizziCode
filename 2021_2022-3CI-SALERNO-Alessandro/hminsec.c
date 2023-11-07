/***********************************************
CONSEGNA:
leggere il tempo in ore, minuti e secondi e
trasformare il tutto in secondi.

WARNING:
Funzionamento verificato solo con l' ultima
versioen del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    06 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiarazione variabili
    int hours, minutes, seconds, sum;

    // Prendere ore in input
    printf("Numero di ore --> ");
    scanf("%d", &hours);

    // Prendere minuti in input
    printf("Numero di minuti --> ");
    scanf("%d", &minutes);

    // Prendere secondi in input
    printf("Numero di secondi --> ");
    scanf("%d", &seconds);

    // Calcolare e stampare somma
    sum = (hours * 3600) + (minutes * 60) + seconds;
    printf("\nIn totale sono %d secondi\n", sum);

    return 0;
}
