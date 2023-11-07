/************************************************
CONSEGNA:
Scrivere un programma che definisce un vettore
di 10 interi. In base alle 4 voci di menu 1,2,3,4
si deve permettere di:
1) Caricare il vettore
2) Visualizza contenuto del vettore
3) Ricerca di un elemento nel vettore
4) Esci

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (MinGW/GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    02 Gennaio 2022
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
    printf("3. Cercare un elemento nell'array\n");
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

void TrovaInArray()
{
    if (!array_caricato)
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }

    int cerca;

    printf("Quale valore trovare? ");
    scanf("%d", &cerca);

    int i;
    bool trovato = false;

    for (i = 0; i < MAX; i++)
    {
        if (vec[i] == cerca)
        {
            printf("Trovato %i in posizione %i\n", cerca, i);
            trovato = true;
        }
    }
    
    if (!trovato)
        printf("Non trovato\n");
}

int main()
{
    // Spiegazione a riga 141
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
            case 1: { CaricaArray();      } break;
            case 2: { VisualizzaArray();  } break;
            case 3: { TrovaInArray();    } break;
        }

        // scanf("%c", ...) e getchar() non funzionavano
        // Ho cercato su interent, e sembrerebbe un porblema che non posso risolvere
        // Parrebbe che, almeno col mio compilatore e la mia libc, la lettura dei caratteri sia non-blocking
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
