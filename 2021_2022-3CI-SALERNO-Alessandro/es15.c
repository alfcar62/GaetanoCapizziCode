/************************************************
CONSEGNA:
dato in input un numero n maggiore di zero,
determinare e stampare i primi n numeri di
Fibonacci

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    03 Novembre 2021
*************************************************/


#include <stdio.h>


int main()
{
    // Dichirazione variabili
    int n  = 0,
        n1 = 0,
        n2 = 1,
        r  = 0,
        i  = 0;
    
    // Output iniziale
    printf("Esercizio 15: Sequenza di Fibonacci dei i primi n numeri\n");

    // Input del numero
    do
    {
        printf("Inserire numero -> ");
        scanf("%d", &n);
    } while (n < 3);

    // Stampare 0 ed 1 (Fissi)
    printf("%d\n%d\n", n1, n2);

    // Stampare tutti gli altri numeri della sequenza
    for (i = 2; i < n; i++)
    {
        r  = n1 + n2;
        n1 = n2;
        n2 = r;

        printf("%d \n", r);
    }

    return 0;
}
