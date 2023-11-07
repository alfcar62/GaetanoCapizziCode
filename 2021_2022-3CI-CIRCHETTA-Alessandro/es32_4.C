/*
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA: Scrivere un programma che chiama una funzione che, dato un array di interi in input, aggiunga 1 a tutti gli elementi dell'array e restituisca in output al main la somma di tutti gli elementi dell'array.
Il main effettuerà la stampa degli elementi dell'array e della somma restituita dalla funzione.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEC 10

void input(int array[])
{
    for (int i = 0; i < DEC; i++)
    {
        printf("inserire il %d numero all'interno del vettore\n", i + 1);
        scanf("%d",&array[i]);
    }
}

void somma1(int array[])
{
    for (int i = 0; i < DEC; i++)
    {
        array[i] += 1;
    }
}

int sommaarray(int array[])
{
    int sommatore = 0;

    for (int i = 0; i < DEC; i++)
    {
        sommatore += array[i];
    }
    return sommatore;
}

int main()
{
 
    int vettore[DEC];

    input(vettore);
    somma1(vettore);

    for (int i = 0; i < DEC; i++)
    {
        printf("valore %d aumentato di 1 dell'array e': %d\n", i + 1, vettore[i]);
    }

    int somma = sommaarray(vettore);
    printf("la somma di tutti i valori aumentati di 1 dell'array e'--> %d\n",somma);

    return 0;
}