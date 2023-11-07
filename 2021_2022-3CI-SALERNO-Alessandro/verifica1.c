// Verifica 1 Dicembre 2021
// Informatica Laboratorio
// Linguaccio C
// Alessandro Salerno


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define CLEAR "clear"
#endif


// Variabili globali
int opzione;


// Input iniziale
void InputIniziale()
{
    do
    {
        printf("Opzione --> ");

        if (1 != scanf("%d", &opzione))
        {
            printf("\nErrore di input\nTermino il programma...\n");
            exit(-1);
        }
    } while (opzione < 1 || opzione > 5);
}

// Disegna menù
void DisegnaMenu()
{
    system(CLEAR);

    printf("1. Dati 10 numeri interi, dire quanti sono pari\n");
    printf("2. Dati 2 numeri interi, calcolare la somma se sono positivi ed il prodotto se negativi\n");
    printf("3. Dati base ed esponente, calcolare la potenza\n");
    printf("4. Date le coordinate di un punto su un piano cartesiano, dire a quale quadrate appartiene\n");
    printf("5. Esci\n\n");
}

void Esercizio1()
{
    system(CLEAR);

    int i, pari = 0;
    for (i = 0; i < 10; i++)
    {
        int num;
        printf("Inserire numero -> ");
        scanf("%d", &num);

        // Aggiunge 1 a pari se il numero è pari
        // Altrimenti aggiunge 0 (Lasciando invariato)
        pari += !(num & 1); // Se il bit meno significativo è 1 (Numro dispari) dà 0, altrimenti dà 1
    }

    printf("\nI numeri pari sono %d\n", pari);
    printf("I numeri dispari sono %d\n", 10 - pari);
}

void Esercizio2()
{
    system(CLEAR);

    int a, b, ret;

    printf("Inserire primo numero -> ");
    scanf("%d", &a);

    printf("Inserire secondo numero -> ");
    scanf("%d", &b);

    // Se a e b sono positivi, ret diventa la somma dei due, altrimenti il prodotto
    // Versione branchless dell'equivalente if (a > 0 && b > 0) { ret = a + b; } else { ret = a *  b; }
    ret = (a > 0 && b > 0) * (a + b) + !(a > 0 && b > 0) * (a * b);

    printf("\nIl risultato e' %d\n", ret);
}

void Esercizio3()
{
    system(CLEAR);

    int base, exp;

    printf("Inserire la base --> ");
    scanf("%d", &base);

    printf("Inserire l'esponente --> ");
    scanf("%d", &exp);

    int i, val = base;
    for (i = 0; i < exp - 1; i++)
        val *= base;

    printf("\nLa potenza e' %d\n", val);
}

void Esercizio4()
{
    system(CLEAR);

    int x, y;

    printf("Inserire valore di X --> ");
    scanf("%d", &x);

    printf("Inserire valore di Y --> ");
    scanf("%d", &y);

    if (x > 0 && y > 0)
        printf("\nQuadrante I (+ +)\n");
    else if (x < 0 && y > 0)
        printf("\nQuadrate II (- +)\n");
    else if (x < 0 && y < 0)
        printf("\nQuadrante III (- -)\n");
    else if (x > 0 && y < 0)
        printf("\nQuadrante IV (+ -)\n");
    else
        printf("\nOrigine\n");
}

int main()
{
    DisegnaMenu();
    InputIniziale();
    
    switch (opzione)
    {
        case 1: { Esercizio1(); } break;
        case 2: { Esercizio2(); } break;
        case 3: { Esercizio3(); } break;
        case 4: { Esercizio4(); } break;
        case 5: { return 0;     } break;
    }

    return 0;
}
