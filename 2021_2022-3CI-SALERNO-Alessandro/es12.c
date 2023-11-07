/***********************************************
CONSEGNA:
Leggere 2 numeri positivi e calcolarne il
prodotto con il metodo delle addizioni successive

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    20 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichirazione variabili
    int n1 = 0,
        n2 = 0,
        r  = 0,
        i  = 0;

    // Output iniziale
    printf("Esercizio 12: Moltiplicazione con addizioni successive \n");

    // Input del primo fattore
    do
    {
        printf("Inserire primo numero -> ");
        scanf("%d", &n1);
    } while (n1 < 1);

    // Input del secondo fattore
    do
    {
        printf("Inserire secondo numero -> ");
        scanf("%d", &n2);
    } while (n2 < 1);

    // Calcolo del prodotto attraverso le addizioni successive
    for (i = 0; i < n2; i++)
        r += n1;
    
    // Output risultato
    printf("Il risultato e': %d\n", r);
    return 0;
}
