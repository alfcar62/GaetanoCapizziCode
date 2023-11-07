/***********************************************
CONSEGNA:
Prendere 4 numeri in input, valutare qual è il
minore e darlo in input. Utilizzare le strutture
condizionali

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
    int n1, n2, n3, n4;

    // Prendere primo valore
    // Si presume che n1 sia il numero minore
    // n1 viene anche usata come variabile d'appoggio per evitare di crearne un'altra, risparmiando 4 byte
    printf("Inserire primo numero --> ");
    scanf("%d", &n1);

    // Prendere secondo valore
    printf("Inserire secondo numero --> ");
    scanf("%d", &n2);

    // Prendere terzo valore
    printf("Inserire terzo numero --> ");
    scanf("%d", &n3);

    // Prendere quarto vlaore
    printf("Inserire quarto numero --> ");
    scanf("%d", &n4);

    // Controllare se il primo numero è maggiore del secondo numero
    // Ed impostare r al secondo numero se lo è
    if (n1 > n2)
        n1 = n2;
    
    // Controllare se il risultato temporaneo è maggiore del terzo numero
    // Ed impostare r a quest'utlimo se lo è
    if (n1 > n3)
        n1 = n3;

    // Controllare se il risultato temporaneo è maggiore del quarto numero
    // Ed impostare r a quest'utlimo se lo è
    if (n1 > n4)
        n1 = n4;

    // Stampare il risultato
    printf("\nIl risultato e' %d \n", n1);
    return 0;
}
