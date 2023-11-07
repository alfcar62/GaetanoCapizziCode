/************************************************
CONSEGNA:
Dato un numero n in input, stampare i primi
n numeri primi.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    03 Novembre 2021
*************************************************/


#include <stdio.h>


int main()
{
    int n     = 1, // Contiene il numero che si sta analizzando
        resti = 0, // Conta per qunati numeri è divisbile il valore in analisi
        i     = 0, // Contatore
        div   = 0, // Divisore
        jump  = 0, // Contiene il salto da compiere per arrivare al prossimo numero da analizzare
        primi = 0; // Quantità di numeri primi che si vuole generare

    // Output iniziale
    printf("Esercizio 16: Dato un numero n in input, stampare i primi n numeri primi\n");

    // Prendere in input il numero di numeri primi che si volgino trovare
    do
    {
        printf("Inserire quantita' di valori primi che si vogliono generare -> ");
        scanf("%d", &primi);
    } while (primi < 1);

    // Ripetere fin quando non si sono trovati `primi` numeri primi
    for (i = 0; i < primi; i += !resti)
    {
        jump  = !resti * ((n > 2) + (jump == 2 && n >= 7) * 2) + 1 + !!resti;
        resti = 0;

        for (div = 2; div < n && div < 4; div++)
            resti += n % div == 0;
        
        for (div = 5; div < n && !resti; div += 2)
            resti += n % div == 0;

        // Se si tratta di un numero primo, stamparlo
        (!resti) ? printf("%d ", n) : 0;

        jump -= !!resti * 2 * (jump == 4);
        n    += jump;
    }

    return 0;
}
