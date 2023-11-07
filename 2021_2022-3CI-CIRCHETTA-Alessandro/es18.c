/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Scrivere un programma che chiede in input un numero intero n, dopodichè carica un array contenente i primi n numeri pari e un array contenente i primi n numeri dispari. Infine stampa in output il contenuto dei due array
*****************************************/
#include <stdio.h>


int main()
{
    int num   = 0,
        idisp = 0, 
        ipari = 0,
        n     = 0; 

    int pari[100],
        dispari[100];

    printf("inserire numero di numeri da analizzare -> ");
    scanf("%d", &n);

    for (num = 0; num < n * 2; num++)
    {
        if (num % 2 == 0)
        {
            pari[ipari] = num;
            ipari++;
        }
        else
        {
            dispari[idisp] = num;
            idisp++;
        }
    }

    printf("Pari: ");

    for (int indice = 0; indice < ipari; indice++)
        printf(" %d ", pari[indice]);

    printf("\nDispari: ");

    for (int indice = 0; indice < idisp; indice++)
        printf(" %d ", dispari[indice]);

    return 0; 
}