/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA: Realizzare un programma in C language che  permetta all'utente di giocare al master mind con il compuer.
Il computer crea un numero random di 4 cifre numeriche (tutte diverse) e l'utente deve indovinare le 4 cifre  con un certo numero di tentativi.
Ad ogni tentativo il computer risponde indicando il n. di cifre nella posizione giusta e il n. di cifre nella posizione sbagliata. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define MAX 4

typedef unsigned char color_t;

enum
{
Black,
Red,
Green,
Yellow,
Blue,
Magenta,
Cyan,
LightGray,
Gray,
LightRed,
LightGreen,
LightYellow,
LightBlue,
LightMagenta,
LightCyan,
White
};

void textcolor(color_t fgcolor, color_t bgcolor)
{
printf(
// \003 indica una sequenza
// 38 è colore testo
// 48 è colore sfondo
// 5 indica modalità a 256 colori (Profondità 8 bit)
// %d è il colore
"\033[38;5;%dm\033[48;5;%dm",
fgcolor, bgcolor);
}
int find(unsigned char arr[], unsigned char val)
{
    int i;
    for (i = 0; i < MAX; i++)
        if (arr[i] == val)
            return i;

    return -1;
}

bool ArrayCe(unsigned char arr[], unsigned char val)
{
    return find(arr, val) != -1;
}

unsigned char GeneraUnico(unsigned char arr[])
{
    unsigned char val;

    do
        val = rand() % 9 + 1;
    while (ArrayCe(arr, val));

    return val;
}

void Macchina(unsigned char arr[])
{
    arr[0] = rand() % 9 + 1;

    int i;
    for (i = 1; i < MAX; i++)
    {
        unsigned char val = GeneraUnico(arr);
        arr[i] = val;
    }
}

void Stampaarray(unsigned char arr[])
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
}
bool InputValido(unsigned char arr[])
{
    int i;
    for (i = 0; i < MAX; i++)
        if (arr[0] < '0' || arr[0] > '9')
            return false;

    return strlen(arr) == 4;
}

void InputPlayer(unsigned char arr[])
{
    do
    {
        printf("\n INSERISCI IL NUMERO GIOCATORE-> ");
        scanf("%s", arr);
    } while (!InputValido(arr));
}
void Player(unsigned char arr[])
{
    printf("\n INSERISCI IL NUMERO GIOCATORE-> ");
    scanf("%s", arr);

    int i;
    for (i = 0; i < MAX; i++)
        arr[i] -= 48;
}

void compare(unsigned char arr1[], unsigned char arr2[], int* giusti, int* sbagliati)
{
    *giusti    = 0;
    *sbagliati = 0;

    int i;
    for (i = 0; i < MAX; i++)
    {
        int idx = find(arr1, arr2[i]);

        if (idx == -1)
            continue;

        *giusti    += i == idx;
        *sbagliati += i != idx; 
    }
}

int  main()
{
    srand(time(NULL));
    textcolor(White, Black);
    unsigned char pc[MAX];    // Vettore generato
    unsigned char user[MAX+1];    // Vettore utente
    bool corretto;
    Macchina(pc);
    printf("\n");
    int tent;
    int giusti, sbagliati;
    for (tent = 0; tent < 10 && !corretto; tent++)
    {
        printf("SEI AL %d TENTATIVO", tent+1);
        Player(user);
        compare(pc, user, &giusti, &sbagliati);
        printf("\nGiusti in posizione giusta: %d\n", giusti);
        printf("\nGiusti in posizione sbagliata: %d\n", sbagliati);
        corretto=giusti==MAX;
    }
    if (tent==10)
    {
        textcolor(Red, Black);
        printf("HAI PERSO, IL NUMERO ERA: ");
        Stampaarray(pc);
    }
    if (corretto)
    {
        textcolor(Green, Black);
        printf("HAI VINTO, IL NUMERO ERA:");
        Stampaarray(pc);
    }


    return 0;
}