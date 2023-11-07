/***********************************************
CONSEGNA:
Leggere un numero n positivo e calcolare il
quadrato con il metodo della somma dei primi n
numeri dispari.

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
    int n   =  0,
        i   =  0,
        r   =  0,
        odd = -1;

    // Output iniziale
    printf("Esercizio 14: Quadrato di un numero n usando i primi n numeri dispari \n");

    // Input del numero
    do
    {
        printf("Inserire numero -> ");
        scanf("%d", &n);
    } while (n < 1);

    // Somma dei primi n numeri dispari
    for (i = 0; i < n; i++)
    {
        odd += 2;
        r   += odd;
    }
    
    // Output finale
    printf("Il quadrato di %d e': %d\n", n, r);
    return 0;
}
