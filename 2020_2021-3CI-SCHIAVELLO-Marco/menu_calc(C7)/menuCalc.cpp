//Marco Schiavello 3^Ci 2/12/2020
//menu calcolatrice
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

void somma(int ope1,int ope2);
void sottrazione(int ope1,int ope2);
void moltiplicazione(int ope1,int ope2);
void divisione(int ope1,int ope2);
int menu();
void insertOperandi(int * ope1,int * ope2);

/*_________Main_________*/
int main()
{
    int ope1,ope2;
	bool fine=false;
	do
	{
	    int scelta = menu();
        insertOperandi(&ope1,&ope2);
		switch(scelta)
		{
			case 1:
			{
				somma(ope1,ope2);
				getch();
				break;
			}
			case 2:
			{
				sottrazione(ope1,ope2);
				getch();
				break;
			}
			case 3:
			{
				moltiplicazione(ope1,ope2);
				getch();
				break;
			}
			case 4:
			{
				divisione(ope1,ope2);
				getch();
				break;
			}
			default:
			{
				fine=true;
				break;
			}
		}
	}
	while(fine==false);
}

/**
*   esegue e stampa una somma tra due operandi
*   params:
*       @param int ope1 : input : primo operando
*       @param int ope2 : input : secondo operando
*       @return void
*/
void somma(int ope1,int ope2) { printf("%d + %d = %d",ope1,ope2,ope1+ope2); }
/**
*   esegue e stampa una sottrazione tra due operandi
*   params:
*       @param int ope1 : input : primo operando
*       @param int ope2 : input : secondo operando
*       @return void
*/
void sottrazione(int ope1,int ope2){ printf("%d - %d = %d",ope1,ope2,ope1-ope2); }
/**
*   esegue e stampa una moltiplicazione tra due operandi
*   params:
*       @param int ope1 : input : primo operando
*       @param int ope2 : input : secondo operando
*       @return void
*/
void moltiplicazione(int ope1,int ope2) { printf("%d * %d = %d",ope1,ope2,ope1*ope2); }
/**
*   esegue e stampa una divisione tra due operandi
*   params:
*       @param int ope1 : input : primo operando
*       @param int ope2 : input : secondo operando
*       @return void
*/
void divisione(int ope1,int ope2) { printf("%d / %d = %d",ope1,ope2,ope1/ope2); }

/**
*   fa visualizzare un menu dove l'utente sceglie cosa vuole fare
*   params:
*       @return int numero della voce scelta dal menu
*/
int menu()
{
	int scelta;
	do
	{
		system("cls");
		printf("Calcolatrice\n\n");
		printf("1) Somma\n\n");
		printf("2) Sottrazione\n\n");
		printf("3) Moltiplicazione\n\n");
		printf("4) Divisione\n\n");
		printf("5) Esci\n\n");
		printf("scegli --> ");
		scanf("%d",&scelta);
	}
	while(scelta<1||scelta>5);
	return scelta;
}

/**
*   prende due puntatori che puntano agli operandi per segunti operazioni e li chiedi all'utente
*   params:
*       @param int * ope1 : output : puntatore che punta al primo operando
*       @param int * ope2 : output : puntatore che punta al secondo operando
*       @return void
*/
void insertOperandi(int * ope1,int * ope2)
{
    system("cls");
	printf("inserisci primo operando --> ");
	scanf("%d",ope1);
	printf("inserisci secondo operando --> ");
	scanf("%d",ope2);
}


