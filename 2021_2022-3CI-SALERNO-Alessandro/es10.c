/***********************************************
CONSEGNA:
stampare i primi numeri dispari (da 0 a 10).

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    19 Ottobre 2021
************************************************/


#include <stdio.h>


int main()
{
    // Dichiarazione variabili
    int num;

    // Stampare tutti i numeri dispari
    for (num = 1; num < 10; num += 2)
        printf("%d \n", num);

    return 0;
}
