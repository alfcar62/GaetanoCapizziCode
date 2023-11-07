/*****************************************************************************************************
Consegna/Spiegazione: 
Prova di utilizzo della libreria "string.h" e utilizzo di alcune sue funzioni
La libreria che serve per utilizzare le funzioni usate i questo programma è "string.h"
#include <string.h>
"gets" serve per prendere in input un nome 
"puts" serve a stampare il nome dato nella gets
Queste 2 funzioni sono utili perche evitano si utilizzare un for per stampare un char oppure stamparlo

"gets" permette di inserire in input le lettere con accento, ma "puts" non permette di stampare queste lettere

La funzione "toupper()" permette di trasfomare la lettera presente nella variabile tra le parentesi
in maiuscolo

La funzione "tolower()" permette di trasformare la lettera presente nella varibile tra le parentesi 
in minuscolo

"strlen" permette di trovare la lunghezza di un array di char

"strcmp" string compare, compara 2 stringhe; se: 
                                             genera un numero = 0 (sono uguali)
                                             genera un numero > 0 (prima stringa > seconda stringa)
                                             genera un numero < 0 (seconda stringa > prima stringa)
per > e < si intende l'ordine alfabetico, non la lunghezza della stringa.

Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 09/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define MAX_VAL 5

int main() 
{
    char arr[MAX_VAL];
    char vincenzo;
    int l;

    printf("Inserisci un nome-->");
    gets(arr);                      //Prende in input un nome e una volta premuto invio lo salva in "arr"
    
    l = strlen(arr);

    printf("Lunghezza del nome --> %d\n",l);

    arr[0] = toupper(arr[0]);
    puts(arr);

    return 0;
}