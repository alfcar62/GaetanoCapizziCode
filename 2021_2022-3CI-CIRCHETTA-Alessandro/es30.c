/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   12/01/2022
CLASSE: 3C INFORMATICA
CONSEGNA: Scrivere un programma che definisce un vettore di 10 interi. In base alle 4 voci di menu 1,2,3,4 si deve permettere di:
1) Carica il vettore
2) Visualizza il vettore
3) Ordinamento crescente
4) Ordinamento descrescente
5) Calcolo media
6) Ricerca di un valore con metodo sequenziale
7) Ricerca di un valore con metodo dicotomico
8) esci
**/
#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 10

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

bool caricato=false;

int menu()
{
    int option;
    do
    {
    system("cls");
    gotoxy(30,25);
    printf("MENU SUGLI ARRAY \n");
    gotoxy(9,26);
    printf("1) Caricamento dell'array\n");
    gotoxy(9,27);
    printf("2) Stampa dell'array\n");
    gotoxy(9,28);
    printf("3) Ordina in modo crescente l'array \n");
    gotoxy(9,29);
    printf("4) Ordina in modo decrescente l'array \n");
    gotoxy(9,30);
    printf("5) Fare la media dell'array \n");
    gotoxy(9,31);
    printf("6) Ricerca di un elemento nell'array in modo sequenziale\n");
    gotoxy(9,32);
    printf("7) Ricerca di un elemento nell'array in modo dicotomico\n");
    gotoxy(9,33);
    printf("8) Uscita\n");

        gotoxy(9,34);
        printf("Scelta -> ");
        scanf("%d", &option);
    } while (option < 1 || option > 8);
    return option;
}


void caricamento(int a[])
{
    int i;
    system("cls");
    for (i = 0; i < MAX; i++)
    {
        printf("Inserire elemento N. %d -> ", i + 1);
        scanf("%d", &a[i]);
    }
    caricato=true;
}
void print_array(int a[])
{
    system("cls");
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }
    system("cls");
    int i;
    for (i = 0; i < MAX; i++)
        printf("Elemento %d ---->  %d\n", i, a[i]);
}
void ordina_array_crescente(int a[])
{
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }
    system("cls");
    int i, g, x;
    for (i = 0; i < MAX-1; i++)
    {
        for (x = i+1; x < MAX; x++)
        {
            if (a[i]>a[x])
            {
                g=a[i];
                a[i]=a[x];
                a[x]=g;
            }

            
        }   
    }
    for (i = 0; i < 80; i++)
    {
        gotoxy(i,12);
        printf("%c", 219);
        Sleep(50);
    }
}
void ordina_array_decrescente(int a[])
{
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }
    system("cls");
    int i, g, x;
    for (i = MAX-1; i > 0; i--)
    {
        for (x = i-1; x > -1; x--)
        {
            if (a[x]<a[i])
            {
                g=a[i];
                a[i]=a[x];
                a[x]=g;
            }            
        }   
    }
    for (i = 0; i < 80; i++)
    {
        gotoxy(i,12);
        printf("%c", 219);
        Sleep(50);
    }
}
void media_array(int a[])
{
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }
    int i;
    float m, tot;
    for (i = 0; i < MAX-1; i++)
    {
        tot=tot+a[i];
    }
    m=(tot)/MAX;
    printf("la media e': %f", m);
}

void ricerca_sequenziale(int a[])
{
    if (!caricato) 
    {
        printf("Prima bisogna caricare l'array\n");
        return;
    }

    int valore;

    printf("Quale valore trovare? ");
    scanf("%d", &valore);

    int i;
    bool trovato = false;

    for (i = 0; i < MAX; i++) {
        if (a[i] == valore) {
            printf("Trovato %i in posizione %i\n", valore, i);
            trovato = true;
        }
    }
    
    if (!trovato)
        printf("il valore %d non e' stato trovato\n", valore);
}
void ricerca_dicotomica(int a[])
{
	int n,c=0,i, trovato=0, iMin=0, iMax=MAX;
	system("cls");
	gotoxy(10,5);
	printf("Quale numero vuoi cercare?");
	gotoxy(10,6);
	printf("Numero: ");
	gotoxy(18,6);
	scanf("%d",&n);
	i=(iMax+iMin)/2;
	while(a[i] != n || iMin == iMax)
	{
		i=(iMax + iMin)/2;
		if(a[i]>n)
		{
			iMax=i;
		}
		else
		{
			iMin=i;
		}
	}
	system("cls");
	if(a[i]==n)
	{
		gotoxy(10,5);
		printf("Il numero si trova alla posizione %d", i);
		getchar();
	}
	else
	{
		gotoxy(10,5);
		printf("Numero non trovato");
		getchar();
	}
		
}
int main()
{
    int risp, a[MAX], ans;
    do
    {


        ans = menu();

        switch (ans)
        {
            case 1: { caricamento                 (a);     } break;
            case 2: { print_array                 (a);     } break;
            case 3: { ordina_array_crescente      (a);     } break;
            case 4: { ordina_array_decrescente    (a);     } break;
            case 5: { media_array                 (a);     } break;
            case 6: { ricerca_sequenziale         (a);     } break;
            case 7: { ricerca_dicotomica          (a);     } break;
        };

        getchar();
        getchar();
    }while (ans != 8);
    
}