/***********************************************
CONSEGNA:
Dato un tempo espresso in secondi, trasformarlo
in ore,minuti e secondi.

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
    int input, hours, minutes, seconds;

    // Chiedere secondi in input
    printf("Numero di secondi --> ");
    scanf("%d", &input);

    // Calcolare ore, minuti e secondi
    hours       = input / 3600;
    minutes     = (input % 3600) / 60;
    seconds     = input - (minutes * 60 + hours * 3600);

    // Stampare risultato
    printf("\nSono: %d:%d:%d \n", hours, minutes, seconds);
    return 0;
}
