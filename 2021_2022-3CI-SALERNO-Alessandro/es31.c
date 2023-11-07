/************************************************
CONSEGNA:
Realizzare un programma in C language che 
permetta all'utente di giocare al master mind con
il compuer. Il computer crea un numero random di
4 cifre numeriche (tutte diverse) e l'utente deve
indovinare le 4 cifre  con un certo numero di
tentativi. Ad ogni tentativo il computer risponde
indicando il n. di cifre nella posizione giusta e
il n. di cifre nella posizione sbagliata. 
Es: se il computer crea il numero 4712 e l'utente
inserisce 4023, il computer risponde 1G 1S
(1 cifra nella posizione giusta ed 1 nella
posizione sbagliata) e così via...

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    01 Febbraio 2022
*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ARRAY_LEN     4
#define NUM_TENTATIVI 10
#define RANDOM()      rand() % 9 + 1


int TrovaInArray(unsigned char arr[], unsigned char val)
{
    int i;
    for (i = 0; i < ARRAY_LEN; i++)
        if (arr[i] == val)
            return i;

    return -1;
}

bool ArrayContiene(unsigned char arr[], unsigned char val)
{
    return TrovaInArray(arr, val) != -1;
}

unsigned char GeneraValoreUnico(unsigned char arr[])
{
    unsigned char val;

    do
        val = RANDOM();
    while (ArrayContiene(arr, val));

    return val;
}

void GeneraArray(unsigned char arr[])
{
    int i;
    for (i = 0; i < ARRAY_LEN; i++)
    {
        unsigned char val = GeneraValoreUnico(arr);
        arr[i] = val;
    }
}

void StampaArray(unsigned char arr[])
{
    int i;
    for (i = 0; i < ARRAY_LEN; i++)
        printf("%d ", arr[i]);
}

void ComparaArray(unsigned char arr1[], unsigned char arr2[], int* giusti, int* sbagliati)
{
    *giusti    = 0;
    *sbagliati = 0;

    int i;
    for (i = 0; i < ARRAY_LEN; i++)
    {
        int idx = TrovaInArray(arr1, arr2[i]);
        if (idx == -1) continue;

        *giusti    += i == idx;
        *sbagliati += i != idx;
    }
}

bool InputValido(unsigned char arr[])
{
    int i;
    for (i = 0; i < ARRAY_LEN; i++)
        if (arr[0] < '0' || arr[0] > '9')
            return false;

    return strlen(arr) == 4;
}

void InputUtente(unsigned char arr[])
{
    do
    {
        printf("\nINSERISCI VALORE -> ");
        scanf("%s", arr);
    } while (!InputValido(arr));
}

void CaricaArray(unsigned char arr[])
{
    InputUtente(arr);

    int i;
    for (i = 0; i < ARRAY_LEN; i++)
        arr[i] -= 48;
}

int  main()
{
    srand(time(NULL));                      // Inizializza seed per il rand

    bool corretto;                          // Indica se l'utente ha vinto o meno

    int tentativi,                          // Conta i tentativi
        sbagliati,                          // Conta le cifre in posizioni sbagliate
        giusti;                             // Conta le cifre in posizioni giuste

    unsigned char   pc    [  ARRAY_LEN  ];  // Array generato   (Computer)
    unsigned char   usr   [ARRAY_LEN + 1];  // Array utente     [+ 1 Per il Null terminator]

    GeneraArray(pc);
    
    for (tentativi = 0; tentativi < NUM_TENTATIVI && !corretto; tentativi++)
    {
        printf("\n\nTentativo %d\n", tentativi + 1);
        CaricaArray(usr);
        ComparaArray(pc, usr, &giusti, &sbagliati);
        
        printf("\nGIUSTI: %d\n", giusti);
        printf("POSIZIONI SBAGLIATE: %d\n", sbagliati);
        printf("SBAGLIATI: %d\n", ARRAY_LEN - (giusti + sbagliati));

        corretto = giusti == ARRAY_LEN;
    }

    printf((corretto) ? "Hai vinto!\n"    :
                        "Hai perso...\n") ;

    return 0;
}
