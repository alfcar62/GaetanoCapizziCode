/*
    Marco Schiavello 3^CI 16/08/2021

    Scrivere un programma che acquisisca da tastiera una parola (cioè una stringa di caratteri priva di
    separatori) e dica se tale parola è palindroma, ossia leggibile nello stesso modo da destra a sinistra e
    viceversa (es. OSSESSO).
*/
#include <iostream>
#include <string.h>
#include <ctype.h>
#define DIM 20

void toUpStr(char str[]);
void caricaStr(char str[]);
bool isPalin(char str[]);

/*__________Main_________*/
int main()
{
    char str[DIM];
    caricaStr(str);
    if(isPalin(str))
        printf("la stringa %s e' palindroma",str);
    else
        printf("la stringa %s non e' palindroma",str);
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
    printf("immetti la stringa da controllare per vedere se e' palindroma: ");
    gets(str);
}

/**
*   prende una stringa e controlla se è palindroma
*   params:
*       @param char str[] : input : stringa da controllare
*       @return bool :  indica se la stringa è palindroma o non lo è
*/
bool isPalin(char str[])
{
    toUpStr(str);
    bool isPali = true;
    for(int i = 0; i < strlen(str)/2 && isPali ; i++)
        if(str[i] != str[(strlen(str)-1)-i])
            isPali = false;

    return isPali;
}
