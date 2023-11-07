/***********************************************
CONSEGNA:
Prendere due tempi t1 e t2 espressi in ore,
minuti, secondi e calcolare la somma di t1 e t2
espressa in ore, minuti, secondi

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
    // h: ore, m: minuti, s: secondi
    int h1,    m1,      s1,
        h2,    m2,      s2,
        tot1,  tot2,    tot,
        hours, minutes, seconds;

    // Prendere ore in input
    printf("Inserire H1 --> ");
    scanf("%d", &h1);

    // Prendere minuti in input
    printf("Inserire M1 --> ");
    scanf("%d", &m1);

    // Prendere secondi in input
    printf("Inserire S1 --> ");
    scanf("%d", &s1);

    // Lasciare uno spazio per separare meglio i blocchi
    printf("\n");

    // Prendere ore in input
    printf("Inserire H2 --> ");
    scanf("%d", &h2);

    // Prendere minuti in input
    printf("Inserire M2 --> ");
    scanf("%d", &m2);

    // Prendere secondi in input
    printf("Inserire S2 --> ");
    scanf("%d", &s2);

    // Calcolare totali
    tot1 = (h1 * 3600) + (m1 * 60) + s1;
    tot2 = (h2 * 3600) + (m2 * 60) + s2;
    tot  = tot1 + tot2;

    // Calcolare risultato
    hours   = tot / 3600;
    minutes = (tot % 3600) / 60;
    seconds = tot - (minutes * 60 + hours * 3600);

    // Stampare risultato
    printf("\nLa somma dei due tempi e' %d:%d:%d\n", hours, minutes, seconds);
    return 0;
}
