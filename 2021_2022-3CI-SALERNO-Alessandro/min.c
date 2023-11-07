/***********************************************
CONSEGNA:
Leggere in input 2 numeri interi e stampi il
più piccolo (usare le istruzioni condizionali).

WARNING:
Funzionamento verificato solo con l' ultima
versioen del compilatore GNU (GCC).

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
        printf("Il piu' piccolo e' %d", n2); // Stampare il secondo
    else
        printf("Il piu' piccolo e' %d", n1); // Stampare il primo

    return 0;
}
