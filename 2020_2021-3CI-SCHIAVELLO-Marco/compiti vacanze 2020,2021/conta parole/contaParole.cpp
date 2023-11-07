/*
    Marco Schiavello 3^CI 16/08/2021

    Scrivere un programma che permetta all’utente di inserire un’intera frase. Il programma
    successivamente visualizzi il numero di parole che compone la frase. Si supponga che una frase sia
    costituita di parole, dove una parola è una sequenza di caratteri diversi dallo spazio e delimitata da
    uno o più spazi a destra e sinistra. Uno o più spazi possono aprire o chiudere la frase.
*/
#include <iostream>
#include <string.h>
#include <ctype.h>
#define DIM 1500

void toUpStr(char str[]);
void caricaStr(char str[]);
int contaparole(char str[]);

/*__________Main_________*/
int main()
{
    char str[DIM];
    caricaStr(str);
    printf("la frase contiene %d parole",contaparole(str));
    return 0;
}

/**
*    fa un toupper() su ogni singolo
*    carattere della stringa.
*    Facendo cosi risurtare come un toupper
*    su tutta la stringa
*    Params:
*       @param char str[] : input/output : stringa da far diventare tutta maiuscola
*       @return void
*/
void toUpStr(char str[])
{
    for(int i = 0;i<strlen(str);i++)
        str[i] = toupper(str[i]);
}

/**
*   prende una stringa in input e la mette dentro l'array
*   params:
*       @param char str[] : output : array dove verrà messa la stringa
*       @return void
*/
void caricaStr(char str[])
{
    printf("metti frase per contare le sue parole: ");
    gets(str);
}

int contaparole(char str[])
{
    if(str[0] == 0)
        return 0;

    int parole = 0;

    for(int i = 0;i < strlen(str); i++)
        if(str[i] == ',' || str[i] == '.' || str[i] == ' ')
            if(i != 0 && (str[i-1] != ',' && str[i-1] != '.' && str[i-1] != ' ' ))
                parole++;

    if(str[strlen(str)-1] != ',' && str[strlen(str)-1] != '.' && str[strlen(str)-1] != ' ')
        parole++;

    return parole;
}
