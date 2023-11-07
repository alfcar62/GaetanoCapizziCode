/************************************************
CONSEGNA:
stampare i primi numeri pari (da 0 a 10).

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
        jump  = 0, // Contiene il salto da compiere per arrivare al prossimo numero da analizzare
        primi = 0; // Quantità di numeri primi che si vuole generare

    // Prendere in input il numero di numeri primi che si volgino trovare
    do
    {
        printf("Inserire quantita' di valori primi che si volgiono generare -> ");
        scanf("%d", &primi);
    } while (primi < 1);

    // Ripetere fin quando non si sono trovati `primi` numeri primi
    for (int i = 0; i < primi; i += !resti)
    {
        // Non è possibile avere due numeri primi vicini (Ad eccezione di 1, 2 e 3)
        // Inoltre, non è possibile, superato il 7, avere più di un primo gemello consecutivamente
        // Dunque è possibile ridurre i salti da effettuare escludendo alcuni valori
        // La seguente formula restituisce +1 per i valori 1 e 2, +2 per quelli tra 3 e 7 e +2 o +4 per i valori superiori o uguali al 7 
        // Per i valori >= 7, viene restituito +2 nel caso sia stato trovato un numero primo usando +4 oppure nel caso non sia stato trovato un numero primo
        // E restituisce +4 nel caso sia stato trovato un numero primo usando il salto di 2
        // Benchmark: Utilizzando questo metodo i tempi di calcolo sono stati ridotti IN MEDIA del ~40%
        jump  = !resti * ((n != 1 && n != 2) + (jump == 2 && n >= 7) * 2) + 1 + !!resti;
        resti = 0;

        // Conta per qunati numeri è divisibile (Usando divisori inferiori al primo numero pari dopo il 2 [4])
        for (int div = 2; div < n && div < 4; div++)
            resti += n % div == 0;
        
        // Conta per quanti numeri è divisibile
        // Il salto è di due in modo da ignorare i numeri pari, in quanto il 2 è già stato testato precedentemente
        // Questo permette di dimezzare le comparazioni effettuate
        // Benchmark: Utilizzando questo metodo i tempi di calcolo sono stati ridotti del 50%
        for (int div = 5; div < n && !resti; div += 2)
            resti += n % div == 0;

        // Se si tratta di un numero primo, stamparlo
        if (!resti) printf("%d ", n);

        // Se il numero trovato non è primo, il salto deve essere impostato a 2
        // Le seguenti istruzioni si occupano di saltare della giusta quantità
        // L'espressione restituisce 0 se è stato trovato un numero primo oppure l'ultimo salto era 2. Restituendo 0, il salto è invariato
        // Mentre restituisce 2 se il numero trovato non è primo oppure il salto precedente era 4. Restituendo 2, il salto passa da 4 a 2.
        jump -= !!resti * 2 * (jump == 4);
        n    += jump;
    }

    return 0;
}