/************************************************
CONSEGNA:
Realizzare un programma che presenti il seguente
menu:
1) Carica un vettore
2) Visualizza il vettore
3) Ordina il vettore in modo crescente
4) Esci

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (MinGW/GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    19 Gennaio 2022
*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 10
#define clear() system(CLEARSTR)

#ifdef _WIN32
    #define CLEARSTR "cls"
#else
    #define CLEARSTR "clear"
#endif



int input_utente, vec[MAX];
bool array_caricato = false;


void Menu()
{
    printf("1. Carica array\n");
    printf("2. Stampa array\n");
    printf("3. Ordina l'array\n");
    printf("4. Esci\n\n");
}

int InputMenu()
{
    int opzione;

    do
    {
        printf("Scelta -> ");
        scanf("%d", &opzione);
    } while (opzione < 1 || opzione > 4);

    return opzione;
}

void CaricaArray()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("Inserire elemento N. %d -> ", i + 1);
        scanf("%d", &vec[i]);
    }

    array_caricato = true;
}

void VisualizzaArray()
{
    if (!array_caricato)
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }

    int i;
    for (i = 0; i < MAX; i++)
        printf("Elemento %d: %d\n", i, vec[i]);
}

void SwapInArray(int i, int j)
{
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

void OrdinaArray()
{
    int i, j, tmp;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            if (vec[i] < vec[j])
                SwapInArray(i, j);

    VisualizzaArray();
}

int main()
{
    char continua[1];
    
    clear();
    printf("Esercizio 27 - Vettori\n\n");

    do
    {
        Menu();
        input_utente = InputMenu();

        if (!array_caricato && input_utente != 1 && input_utente != 4)
        {
            clear();
            printf("Bisogna prima caricare l'array!\n\n");
            continue;
        }

        switch (input_utente)
        {
            case 1: { CaricaArray();     } break;
            case 2: { VisualizzaArray(); } break;
            case 3: { OrdinaArray();     } break;
        }

        if (array_caricato && input_utente != 1 && input_utente != 4)
        {
            printf("\nContinuare? [S/n] ");
            scanf("%s", continua);
            continua[0] = toupper(continua[0]);
        }

        clear();
    } while (input_utente != 4 && continua[0] != 'N');

    return 0;
}
