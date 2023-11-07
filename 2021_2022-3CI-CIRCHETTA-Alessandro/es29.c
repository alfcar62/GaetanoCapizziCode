/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   22/12/2021   
CLASSE: 3C INFORMATICA  
CONSEGNA: Scrivere un programma che definisce un vettore di 10 interi. In base alle 4 voci di menu 1,2,3,4 si deve permettere di:
1) Caricare il vettore
2) Visualizza contenuto del vettore
3) Ricerca di un elemento nel vettore
4) Esci
**/
#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#define MAX 10

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

int ans, a[MAX];
bool caricato = false;


void menu()
{
    printf("1) Caricamento dell'array\n");
    printf("2) Stampa dell'array\n");
    printf("3) Ordinamento elementi dell'array\n");
    printf("4) uscita\n");
}

int selezione()
{
    int option;

    do
    {
        printf("Scelta -> ");
        scanf("%d", &option);
    } while (option < 1 || option > 4);

    return option;
}
    
void array()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("Inserire elemento N. %d -> ", i + 1);
        scanf("%d", &a[i]);
    }

    caricato = true;
}

void visualizza_contenuto()
{
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }

    int i;
    for (i = 0; i < MAX; i++)
        printf("Elemento %d: %d\n", i, a[i]);
}

void ordina_array()
{
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }

    int i,
        g,
        x;

    for (i = 0; i < MAX; i++)
    {
        for (x = i + 1; x < MAX; x++)
        {
            if (a[i] > a[x])
            {
                g = a[i];

                a[i] = a[x];

                a[x] = g;
            }
            
        }
        
    }
    
    for (i = 0; i < MAX; i++)
    {
        printf("Elemento numero %d: %d\n", i+1, a[i]);
    }
    

}

int main() 
{
    int risp;

    system("cls");

    do
    {

        menu();
        ans = selezione();

        switch (ans)
        {
            case 1: { array();     } break;
            case 2: { visualizza_contenuto(); } break;
            case 3: { ordina_array();    } break;
        };
        if (caricato && ans != 1 && ans != 4) {
            printf("Continuare? [1/0] ");
            scanf("%d", &risp);
            system("cls");
        }
        else if (!caricato && ans != 4) {
            system("cls");
            printf("Devi caricare l'array!\n\n");
        }
        else {
            system("cls");
        }
    }while (ans != 4 && risp != 0);
}