/************************************************
CONSEGNA:
Scrivere un programma che chiede ininput un
numero intero n, dopodichè carica un array
contenente i primi n numeri pari e un array
contenente i primi n numeri dispari.
Infine stampa in output il contenuto
dei due array.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    10 Novembre 2021
*************************************************/


#include <stdio.h>


int main()
{
    int num    = 0,
        iodd   = 0,
        ieven  = 0,
        numeri = 0;

    int pari[100],
        dispari[100];

    printf("Esercizio 18: Array di pari e dispari\n");

    do
    {
        printf("Inserire quantita' di numeri che si uvole analizzare -> ");
        scanf("%d", &numeri);
    } while (numeri < 1);
    
    for (num = 0; num < numeri * 2; num++)
    {
        int check     = num % 2 == 0;
        
        pari[ieven]   = check * num;
        dispari[iodd] = !check * num;

        ieven        += check;
        iodd         += !check;
    }

    printf("Pari: ");

    for (num = 0; num < ieven; num++)
        printf(" %d ", pari[num]);

    printf("\nDispari: ");

    for (num = 0; num < iodd; num++)
        printf(" %d ", dispari[num]);

    return 0;
}